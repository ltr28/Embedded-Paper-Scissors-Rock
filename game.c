/*
    * File:     game.c
    * Authors:  Samuel Crawley (43420688)
    *           Luke Trenberth (47277086)
    * Date:     13.10.18
    * Brief:    Runs Paper Scissors Rock
*/




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
    //Initializing Systems
    system_init ();
    navswitch_init ();
    ir_uart_init();

    //Initializing the pacer and tinygl
    pacer_init (PACER_RATE);
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);


    while(1) {
        //Initializing game variables
        int round_limit = 0;
        char game_type = 0;
        int your_score = 0;
        int their_score = 0;
        int game_continue = 1;
        int did_you_win_game = 0;
        int round_winner = 0;

        initial_message(); //Displays startup message
        game_type = choose_game(); //Chooses Best of number (1/3/5)
        round_limit = calc_round_limit(game_type); //Finds round limit from input

        while (game_continue) //Continues to run while the game limit is not reached
        {
            choose_char_message(); //Displays a choose char message until a button is pressed
            round_winner = play_round(); //Selects inputs, compares them and finds winner
            round_result_message(round_winner); //Displays winner
            your_score = update_score(round_winner, 1, your_score); //updates your score
            their_score = update_score(round_winner, 2, their_score); //updates opponent's score

            game_continue = check_continue(round_limit, your_score, their_score); // if score limit reached, stop. Otherwise, run another round
        }

        did_you_win_game = find_game_result(your_score, their_score); // Finds who won overall
        game_result_message(did_you_win_game); // Displays win/loss message
    }

    return 0;
}
