#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "delay.h"

#define PACER_RATE 500
#define MESSAGE_RATE 20

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text(buffer);
}

char choose_item(char item_options[])
{
    int i = 0;
    int item_chosen = 0;
    while (item_chosen == 0) {
        pacer_wait();
        tinygl_update();
        navswitch_update ();
        if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
            i++;
        }
        if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
            i--;
        }
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            item_chosen = item_options[i];
        }
        display_character(item_options[i]);
    }
    return item_chosen;
}

void display_message(void)
{
    int check = 0;
    while (check == 0) {
       pacer_wait();
       tinygl_update();
       navswitch_update();
       if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
           check += 1;
       }
   }
}


int choose_game (void)
{
    char game_options[] = {'1', '3', '5'};
    int game_chosen = choose_item(game_options);

    return game_chosen;
}

char choose_char(void)
{
    char char_options[] = {'P', 'S', 'R'};
    int char_chosen = choose_item(char_options);


    return char_chosen;
}


int decide_winner (char input1, char input2)
{
    //Who wins the game?
    //input: 'P'-Paper, 'S'-Scissors, 'R'-Rock
    //output: 1-Player1 won, 2-Player2 won
    //output: 0-Error/Draw
    int winner = 0;
    if (input1 == 'P') {
        if (input2 == 'S') {
            winner = 2;
        } else if (input2 == 'R') {
            winner = 1;
        } else {
            winner = 0;
        }
    } else if (input1 == 'S') {
        if (input2 == 'R') {
            winner = 2;
        } else if (input2 == 'P') {
            winner = 1;
        } else {
            winner = 0;
        }
    } else if (input1 == 'R') {
        if (input2 == 'P') {
            winner = 2;
        } else if (input2 == 'S') {
            winner = 1;
        } else {
            winner = 0;
        }
    } else {
        winner = 0;
    }
    return winner;
}

/*
void run_game(void)
{
    int chosen = 0;
    char options[] = {'P', 'S', 'R'};
    int i = 0;
    while (option == 0) {
        pacer_wait();
        tinygl_update();
        navswitch_update ();
        if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
            i++;
        }
        if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
            i--;
        }
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            chosen = options;
        }
        display_character(options[i]);

    }
    char opponent = 'R';
    int winner = winner(chosen, opponent);
    score[winner-1] += 1;
}
*/
void initial_message (void) {

    tinygl_text("Best of: ");
    display_message();
}

void choose_char_message (void) {

    tinygl_text("Object: ");
    display_message();
}

void round_result_message (int winner) {

    if (winner == 0)
    {
        tinygl_text("Round: You Drew!");
        display_message();
    }
    else if (winner == 1)
    {
        tinygl_text("Round: You Won!");
        display_message();
    }
    else if (winner == 2)
    {
        tinygl_text("Round: You Lost!");
        display_message();
    }

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
    int winner = 0;
    char your_char;
    //int game_track = 0;
    char their_char;


    initial_message();
    game_type = choose_game();
    choose_char_message();
    your_char = choose_char();
    their_char = 'R';
    winner = decide_winner(your_char, their_char);
    round_result_message(winner);


 /*   while (game_track < game_type)
    {


        score = score_update(winner);

        game_track++;
        your_char = choose_char();
        their_char = get_char();


        game_win(score, game_type);


    }*/

    return 0;
}
