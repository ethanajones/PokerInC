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
    printf("Hello World");

    /* TODO (BONUS):
     * If you intend to implement the bonus, «REMOVE» the following line and use
     * the ‹players› variable. It either contains the amount of players, or 0 on
     * invalid program arguments. The validation is left up to you. */
//    (void) players;


    /* TODO:
     * Your implementation goes here.
     * Feel free to define your own functions. */

    return 0;
}
