#ifndef AUXILIARY_H
#define AUXILIARY_H

#define PACER_RATE 500
#define MESSAGE_RATE 30

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

/*------------------Auxiliary functions------------------------------*/
void display_character (char character);

int increment_options(char item_options[], int i);

char choose_item(char item_options[]);

#endif
