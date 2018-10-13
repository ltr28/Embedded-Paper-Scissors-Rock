/*
    * File:     game.h
    * Authors:  Samuel Crawley (43420688)
    *           Luke Trenberth (47277086)
    * Date:     13.10.18
    * Brief:    Runs Paper Scissors Rock
*/

#ifndef GAME_H
#define GAME_H



#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "delay.h"

#define PACER_RATE 500
#define MESSAGE_RATE 30


/*
Runs a game of paper scissors rock.
An initial selection of the number of rounds comes up first. The message continues until the middle button is pressed. The navigation switch up and down buttons can toggle between the options, choosing best of 1, 3 or 5.

For a round, a selection is make by toggling up and down, finalizing a selection by pushing down on the navigation button.

The winner of each round and the overall round is displayed on the LED matrix.
*/
int main (void)
