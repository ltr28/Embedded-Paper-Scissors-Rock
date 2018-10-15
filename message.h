/*
    *File:    message.h
    *Authors: Samuel Crawley (43420688)
              Luke Trenberth (47277086)
    *Date:    13.10.18
    *Brief:   displays messages throughout PAPER SCISSORS ROCK
*/
    


#ifndef MESSAGE_H
#define MESSAGE_H

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "delay.h"
/*---------------------Message functions------------------------------*/

/**Displays a text message
    @param text to display */
void display_message(char* text);

/**Displays the relevant message describing the reuslt of the round "Round: You Drew!", "Round: You Won!" or "Round: You Lost!"
    @param integer representing if you drew(0) if you won(1) or if the other player won(2)*/
void round_result_message (int winner);

/**Displays the relevant message describing the reuslt of the game "GAME OVER: You Win !" or "GAME OVER: You Lost!"
    @param integer representing if you won the game (1) or not (0)*/
void game_result_message(int did_you_win_game);

#endif
