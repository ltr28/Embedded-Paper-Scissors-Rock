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

char choose_game (void);


int calc_round_limit(char game_type);


int update_score(int winner, int player, int score);


int check_continue(int round_limit, int your_score, int their_score);


int find_game_result(int your_score, int their_score);

#endif


