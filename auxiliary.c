/*------------------Auxiliary functions------------------------------*/

#include "auxiliary.h"

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text(buffer);
}

int increment_options(char item_options[], int i)
{
    pacer_wait();
    tinygl_update();
    navswitch_update ();
    if (navswitch_push_event_p (NAVSWITCH_NORTH) && i < 2) {
        i++;
    }
    if (navswitch_push_event_p (NAVSWITCH_SOUTH) && i > 0) {
        i--;
    }
    display_character(item_options[i]);
    return i;
}

char choose_item(char item_options[])
{
    int i = 0;
    char item_chosen = 0;
    char their_item = 'a';
    while (item_chosen != their_item) {
        i= increment_options(item_options, i);
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            item_chosen = item_options[i];
            ir_uart_putc(item_chosen);
        }
        if (ir_uart_read_ready_p()) {
            their_item = ir_uart_getc();
        }
    }
    return item_chosen;
}
