/*
    *File:    auxiliary.c
    *Authors: Samuel Crawley (43420688)
              Luke Trenberth (47277086)
    *Date:    13.10.18
    *Brief:   auxiliary functions used in Paper Scissors Rock
*/


/*------------------Auxiliary functions------------------------------*/

#include "auxiliary.h"

/** Displays a single character */
void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text(buffer);
}

/** Iterate through an array of character options
    @param list of options
    @param index to iterate through list
    @return index of the selected option*/
int increment_options(char item_options[], int i)
{
    pacer_wait();
    tinygl_update();
    navswitch_update ();
    if (navswitch_push_event_p (NAVSWITCH_NORTH) && i < 2) { // the array is always 1x3. The index conditions ensure that the selection does not run off the edge of the array
        i++;
    }
    if (navswitch_push_event_p (NAVSWITCH_SOUTH) && i > 0) {
        i--;
    }
    display_character(item_options[i]);
    return i;
}

/** Selects an option from an array of characters
    @param list of options
    @return the chosen character*/
char choose_item(char item_options[])
{
    //Initialise variables
    int i = 0;
    char item_chosen = 0;
    char their_item = 'a';
    while (item_chosen != their_item) { //While loop ensures that the game only proceeds once each player selects a paper (P) scissors (S) or rock (R) character
        i= increment_options(item_options, i);
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            item_chosen = item_options[i]; //Choose your P, S or R character
            ir_uart_putc(item_chosen);//Transmit your character choice to the other player
        }
        if (ir_uart_read_ready_p()) {
            their_item = ir_uart_getc();//Receive the other player's character
        }
    }
    return item_chosen;
}
