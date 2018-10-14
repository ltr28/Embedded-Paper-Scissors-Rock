/*
    * File:     ingame.c
    * Authors:  Samuel Crawley (43420688)
    *           Luke Trenberth (47277086)
    * Date:     13.10.18
    * Brief:    Header File for functions to run 1 round
*/

#ifndef INGAME_H
#define INGAME_H

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "delay.h"
#include "auxiliary.h"
/*---------------------In Game functions------------------------------*/

/* Takes in char parameters of player1 and player2's inputs
    Returns a player number for who won
    input: 'P'-Paper, 'S'-Scissors, 'R'-Rock
    1-Player1 won, 2-Player2 won
    0-Draw*/
int decide_winner (char input1, char input2);

/*  Finds player1 and player2's options.
    Calls the decide_winner function to find winner
    Outputs the winner*/
int exchange_options(char item_options[]);

    /*Runs one round of play, calling the exchange options function */
char play_round(void);

#endif
