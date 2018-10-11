#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define PACER_RATE 500
#define MESSAGE_RATE 10

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
    int game_options[] = {'1', '3', '5'};
    char game_type = 0;

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
        {
            game_type = game_options[game_index];
            game_chosen = 1;
        }

        display_character(game_options[game_index]);

    }

    return game_type;
}

int main (void)
{
    system_init ();
    navswitch_init ();
    pacer_init (PACER_RATE);

    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

    int game_type = 0;


    while (1)
    {

        //open_message();
        game_type = choose_game();
        /*your_char = choose_char();
        their_char = get_char();
        winner = winner(your_char, their_char);
        score = score_update(winner);
        game_win(score, game_type);*/

    }

    return 0;
}
