#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "delay.h"
#include "auxiliary.h"
#include "message.h"
#include "scoring.h"
#include "ingame.h"

#define PACER_RATE 500
#define MESSAGE_RATE 30


/*-----------------------Main function--------------------------------*/
int main (void)
{
    system_init ();
    navswitch_init ();
    ir_uart_init();
    pacer_init (PACER_RATE);
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

    while(1) {
        int round_limit = 0;
        char game_type = 0;
        int your_score = 0;
        int their_score = 0;
        int game_continue = 1;
        int did_you_win_game = 0;
        int round_winner = 0;

        initial_message();
        game_type = choose_game();
        round_limit = calc_round_limit(game_type);

        while (game_continue)
        {
            choose_char_message();
            round_winner = play_round();
            round_result_message(round_winner);
            your_score = update_score(round_winner, 1, your_score);
            their_score = update_score(round_winner, 2, their_score);

            game_continue = check_continue(round_limit, your_score, their_score);
        }

        did_you_win_game = find_game_result(your_score, their_score);
        game_result_message(did_you_win_game);
    }

    return 0;
}
