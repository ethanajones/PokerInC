#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/*
In this assignment, we will focus on the world's most popular card game - poker.
This game is known in many variants. Here we will deal with probably the most widespread,
Texas Hold'em Poker, when each player holds two cards in his hand and (up to)
five cards common to all players are dealt to the table.
Your task will be to write a program that will communicate with the user via the
command line. Of course, your program will need to be able to compare individual
card combinations with each other. The heart of the problem will be the algorithm
deciding which of the two players won, if it knows both cards of both players
and all five cards lying on the table.


Test case 1: Player 1 wins with a straight
TC KH
3H 9D
9C QD JS 3C 2H

Test case 2: Player 2 wins with a straight
3H 9D
TC KH
9C QD JS 3C 2H

Test case 3: Player 1 wins with a straight
8S 9S
KH QS
2S 7S 4S 5D 6D

Test case 4: Draw with a full house for both players
KC KD
KH KS
QC QD QS 2C 2S

Test case 5: Player 1 wins with a higher pair
AC 5D
KC 9C
AD 3H 6D 8C 7H

Test case 6: Player 2 wins with a two-pair
6H 6D
8C 8D
7H 7D 9S 2C 3S

Test case 7: Player 2 wins with a higher pair
KC 9C
AC 5D
AD 3H 6D 8C 7H
 */

typedef struct {
    int value;
    char suit;
} Card;

int card_value(char card_value);

int compare_hands(Card *player1, Card *player2, Card *community);


/* Parse the number of players at the table for the bonus extension.
 * IMPORTANT: Do not modify this function! */
static int parse_players(int argc, char **argv) {
    switch (argc) {
        case 1:
            return 2;
        case 2:
            return atoi(argv[1]);
        default:
            return 0;
    }
}

int card_value(char card_value) {
    if (isdigit(card_value)) {
        return card_value - '0';
    }

    switch (toupper(card_value)) {
        case 'T':
            return 10;
        case 'J':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        case 'A':
            return 14;
        default:
            return -1;
    }
}

bool validate_cards(Card *cards, int len) {
    for (int i = 0; i < len; i++) {
        if (cards[i].value < 2 || cards[i].value > 14) {
            return false;
        }
    }
    return true;
}

typedef enum {
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH
} HandRank;

typedef struct {
    HandRank rank;
    int tiebreakers[5];
} Hand;

void sort_cards(Card *cards, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (cards[i].value < cards[j].value) {
                Card temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
        }
    }
}

bool is_flush(Card *cards, int len) {
    for (int i = 0; i < len - 1; i++) {
        if (cards[i].suit != cards[i + 1].suit) {
            return false;
        }
    }
    return true;
}

bool is_straight(Card *cards, int len) {
    // Check for Ace-low straight (A, 2, 3, 4, 5)
    if (cards[0].value == 14 && cards[1].value == 5) {
        for (int i = 1; i < len - 1; i++) {
            if (cards[i].value != cards[i + 1].value + 1) {
                return false;
            }
        }
        return true;
    } else {
        for (int i = 0; i < len - 1; i++) {
            if (cards[i].value != cards[i + 1].value + 1) {
                return false;
            }
        }
        return true;
    }
}


int is_n_of_a_kind(Card *cards, int len, int n) {
    for (int i = 0; i <= len - n; i++) {
        int count = 1;
        for (int j = i + 1; j < len && cards[i].value == cards[j].value; j++) {
            count++;
        }
        if (count == n) {
            return cards[i].value;
        }
    }
    return 0;
}

int is_full_house(Card *cards, int len) {
    int three_of_a_kind_value = is_n_of_a_kind(cards, len, 3);
    if (three_of_a_kind_value) {
        for (int i = 0; i < len - 1; i++) {
            if (cards[i].value != three_of_a_kind_value && cards[i].value == cards[i + 1].value) {
                return three_of_a_kind_value;
            }
        }
    }
    return 0;
}


Hand evaluate_hand(Card *cards, int len) {
    sort_cards(cards, len);
    Hand best_hand = {0};

    for (int a = 0; a < len - 4; a++) {
        for (int b = a + 1; b < len - 3; b++) {
            for (int c = b + 1; c < len - 2; c++) {
                for (int d = c + 1; d < len - 1; d++) {
                    for (int e = d + 1; e < len; e++) {
                        Card selected_cards[] = {cards[a], cards[b], cards[c], cards[d], cards[e]};
                        Hand hand = {0};

                        // Check for straight flush
                        if (is_straight(selected_cards, 5) && is_flush(selected_cards, 5)) {
                            hand.rank = STRAIGHT_FLUSH;
                            hand.tiebreakers[0] = selected_cards[0].value;
                        }

                        // Check for four of a kind
                        // Check for four of a kind
                        int four_of_a_kind_value = is_n_of_a_kind(selected_cards, 5, 4);

                        if (four_of_a_kind_value) {
                            hand.rank = FOUR_OF_A_KIND;
                            hand.tiebreakers[0] = four_of_a_kind_value;
                            return hand;
                        }

                        // Check for full house
                        int full_house_value = is_full_house(selected_cards, 5);

                        if (full_house_value) {
                            hand.rank = FULL_HOUSE;
                            hand.tiebreakers[0] = full_house_value;
                            return hand;
                        }

                        // Check for flush
                        if (is_flush(selected_cards, 5)) {
                            hand.rank = FLUSH;
                            for (int i = 0; i < 5; i++) {
                                hand.tiebreakers[i] = selected_cards[i].value;
                            }
                            if (hand.rank > best_hand.rank) {
                                best_hand = hand;
                            }
                            continue;
                        }


                        // Check for straight
                        if (is_straight(selected_cards, 5)) {
                            hand.rank = STRAIGHT;
                            hand.tiebreakers[0] = selected_cards[0].value;
                            return hand;
                        }

                        // Check for three of a kind
                        int three_of_a_kind_value = is_n_of_a_kind(selected_cards, 5, 3);
                        if (three_of_a_kind_value) {
                            hand.rank = THREE_OF_A_KIND;
                            hand.tiebreakers[0] = three_of_a_kind_value;
                            return hand;
                        }

                        // Check for two pair
                        int first_pair_value = is_n_of_a_kind(selected_cards, 5, 2);
                        if (first_pair_value) {
                            int second_pair_value = 0;
                            for (int i = 0; i < 5 - 1; i++) {
                                if (selected_cards[i].value != first_pair_value &&
                                    selected_cards[i].value == selected_cards[i + 1].value) {
                                    second_pair_value = selected_cards[i].value;
                                    break;
                                }
                            }
                            if (second_pair_value) {
                                hand.rank = TWO_PAIR;
                                hand.tiebreakers[0] = first_pair_value;
                                hand.tiebreakers[1] = second_pair_value;
                                return hand;
                            }
                        }

                        // Check for pair
                        if (first_pair_value) {
                            int k = 1;
                            hand.rank = PAIR;
                            hand.tiebreakers[0] = first_pair_value;
                            for (int i = 0; i < 5; i++) {
                                if (selected_cards[i].value != first_pair_value) {
                                    hand.tiebreakers[k++] = selected_cards[i].value;
                                }
                            }
                        }

                        // If no hand was found, default to high card
                        if (hand.rank == HIGH_CARD) {
                            for (int j = 0; j < 5; j++) {
                                hand.tiebreakers[j] = selected_cards[j].value;
                            }
                        }


                        // Update best_hand if the current hand is better
                        if (hand.rank > best_hand.rank) {
                            best_hand = hand;
                        } else if (hand.rank == best_hand.rank) {
                            for (int i = 0; i < 5; i++) {
                                if (hand.tiebreakers[i] > best_hand.tiebreakers[i]) {
                                    best_hand = hand;
                                    break;
                                } else if (hand.tiebreakers[i] < best_hand.tiebreakers[i]) {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return best_hand;
}

int compare_hands(Card *player1, Card *player2, Card *community) {
    Card combined1[7], combined2[7];
    memcpy(combined1, player1, sizeof(Card) * 2);
    memcpy(combined1 + 2, community, sizeof(Card) * 5);
    memcpy(combined2, player2, sizeof(Card) * 2);
    memcpy(combined2 + 2, community, sizeof(Card) * 5);

    Hand hand1 = evaluate_hand(combined1, 7);
    Hand hand2 = evaluate_hand(combined2, 7);

    if (hand1.rank > hand2.rank) {
        return 1;
    } else if (hand1.rank < hand2.rank) {
        return -1;
    } else {
        for (int i = 0; i < 5; i++) {
            if (hand1.tiebreakers[i] > hand2.tiebreakers[i]) {
                return 1;
            } else if (hand1.tiebreakers[i] < hand2.tiebreakers[i]) {
                return -1;
            }
        }
        return 0;
    }
}

int main(int argc, char **argv) {
    int players = parse_players(argc, argv);

    (void) players;

    int* input = malloc(1024 * sizeof(char));
    if (input == NULL) {
        exit(EXIT_FAILURE);
    }

    Card* player1 = malloc(2 * sizeof(Card));
    if (player1 == NULL) {
        exit(EXIT_FAILURE);
    }

    Card* player2 = malloc(2 * sizeof(Card));
    if (player2 == NULL) {
        exit(EXIT_FAILURE);
    }

    Card* community = malloc(5 * sizeof(Card));
    if (community == NULL) {
        exit(EXIT_FAILURE);
    }
    

    while (fgets(input, sizeof(input), stdin) != NULL) {
        sscanf(input, " %c%c %c%c", &player1[0].value, &player1[0].suit, &player1[1].value,
               &player1[1].suit);
        player1[0].value = card_value(player1[0].value);
        player1[1].value = card_value(player1[1].value);

        fgets(input, sizeof(input), stdin);
        sscanf(input, " %c%c %c%c", &player2[0].value, &player2[0].suit, &player2[1].value,
               &player2[1].suit);
        player2[0].value = card_value(player2[0].value);
        player2[1].value = card_value(player2[1].value);

        fgets(input, sizeof(input), stdin);
        sscanf(input, " %c%c %c%c %c%c %c%c %c%c",
               &community[0].value, &community[0].suit,
               &community[1].value, &community[1].suit,
               &community[2].value, &community[2].suit,
               &community[3].value, &community[3].suit,
               &community[4].value, &community[4].suit);

        for (int i = 0; i < 5; i++) {
            community[i].value = card_value(community[i].value);
        }

        int result = compare_hands(player1, player2, community);
        if (result > 0) {
            printf("Player 1\n");
        } else if (result < 0) {
            printf("Player 2\n");
        } else {
            printf("Draw\n");
        }
    }

    free(input);
    free(player1);
    free(player2);
    free(community);
    
    return 0;
}
