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

Test case 2: Player 2 wins with a flush
8S 9S
KH QS
2S 7S 4S 5D 6D

Test case 3: Draw with a full house for both players
KC KD
KH KS
QC QD QS 2C 2S

Test case 4: Player 1 wins with a higher pair
AC 5D
KC 9C
AD 3H 6D 8C 7H

Test case 5: Player 2 wins with a two-pair
8C 8D
6H 6D
7H 7D 9S 2C 3S
 */

typedef struct {
    int value;
    char suit;
} Card;

int card_value(char card_value);

int compare_hands(Card *player1, Card *player2, Card *community);


/* Parse the number of players at the table for the bonus extension.
 * IMPORTANT: Do not modify this function! */
static int parse_players (int argc, char **argv)
{
    switch (argc) {
        case 1:
            return 2;
        case 2:
            return atoi(argv[1]);
        default:
            return 0;
    }
}

int main(int argc, char **argv)
{
    int players = parse_players(argc, argv);

    // Remove the following line if you intend to use the `players` variable
    (void) players;

    char input[1024];
    Card player1[2], player2[2], community[5];

    while (fgets(input, sizeof(input), stdin) != NULL) {
        sscanf(input, " %c%c %c%c", &player1[0].value, &player1[0].suit, &player1[1].value, &player1[1].suit);
        player1[0].value = card_value(player1[0].value);
        player1[1].value = card_value(player1[1].value);

        fgets(input, sizeof(input), stdin);
        sscanf(input, " %c%c %c%c", &player2[0].value, &player2[0].suit, &player2[1].value, &player2[1].suit);
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
    return 0;
}