/*
    *File:    auxiliary.h
    *Authors: Samuel Crawley (43420688)
              Luke Trenberth (47277086)
    *Date:    13.10.18
    *Brief:   auxiliary functions used in PAPER SCISSORS ROCK
*/
    
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

/** Displays a single character */
void display_character (char character);

/** Iterate through an array of character options 
    @param list of options 
    @param index to iterate through list
    @return index of the selected option*/ 
int increment_options(char item_options[], int i);

/** Selects an option from an array of characters 
    @param list of options
    @return the chosen character*/ 
char choose_item(char item_options[]);

#endif
