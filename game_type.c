/**/

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

int choose_game (void)
{
    int game_chosen = 0;
    int game_index = 0;

    int game_options = [1, 3, 5];
    int game_type = 0;


    const char* text = "Welcome! Choose game best-out-of option";
    tinygl_text(text);

    while(game_chosen == 0)
    {
        pacer_wait();
        tinygl_update();
        navswitch_update ();

        if (navswitch_push_event_p (NAVSWITCH_NORTH))
            game_index++;

        if (navswitch_push_event_p (NAVSWITCH_SOUTH))
            game_index--;

        if (navswitch_push_event_p (NAVSWITCH_PUSH))
                game_type = game_options(game_index)
                game_chosen = 1;

        display_character(game_options(game_index));

    }

    return game_type;
}











