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


int decide_winner (char input1, char input2);


int exchange_options(char item_options[]);


char play_round(void);

#endif
