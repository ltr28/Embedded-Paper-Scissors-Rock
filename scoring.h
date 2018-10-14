/*
    *File:    scoring.h
    *Authors: Samuel Crawley (43420688)
              Luke Trenberth (47277086)
    *Date:    13.10.18
    *Brief:   functions that use scores throughout PAPER SCISSORS ROCK
*/
    
#ifndef SCORING_H
#define SCORING_H

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "delay.h"

/*----------------------Scoring Functions-----------------------------*/

/**Chooses the game type to be played. Can either be best of 1, 3 or 5
    @return the character equivelent of either 1, 3 or 5*/
char choose_game (void);

/** Calculates the limit to the number of rounds for a single player in the game type chosen. If game type is best of 1, 3 or 5 the player round limit is 1 , 2 or 3 respectively. 
    @param game type chosen 
    @return the maximum number of rounds of each player*/ 
int calc_round_limit(char game_type);

/** Increments the score of one of the players by 1 after a round
    @param the winner of the round. Is either you (1) or the other player (2)
    @param the player to have their score incremented. Is either you (1) or the other player (2)
    @return the score of the player*/ 
int update_score(int winner, int player, int score);

/** Checks if the game should continue to another round based on whether each of the players scores are less than the round limit 
    @param the round limit
    @param your score
    @param the other players score
    @return an int indicating that the game should continue (1) or not (0)*/
int check_continue(int round_limit, int your_score, int their_score);

/** Determines who wins the game by who has the highest score.
    @param your score
    @param the other players score
    @return returns an int indicating if you won the game (1) or not (0) */
int find_game_result(int your_score, int their_score);

#endif


