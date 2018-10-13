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

void display_message(void);


void initial_message (void);


void choose_char_message (void);


void round_result_message (int winner);


void game_result_message(int did_you_win_game);

#endif
