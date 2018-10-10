#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "delay.h"

#define PACER_RATE 500
#define MESSAGE_RATE 10

static int check = 0;

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text(buffer);
}

int choose_game (void)
{
    int game_chosen = 0;
    char game_options[] = {'1', '3', '5'};
    int i = 0;
    while (game_chosen == 0) {
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
            game_chosen = game_options;
        }
        display_character(game_options[i]);
    }
    return game_chosen;
}

/*
int winner (char input1, char input2)
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
    system_init ();
    navswitch_init ();
    pacer_init (PACER_RATE);
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text("Best of: ");
    while (check == 0) {
        pacer_wait();
        tinygl_update();
        navswitch_update();
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            check += 1;
        }
    }
}

int main (void)
{

    initial_message();
    int game_type = choose_game();

    while (1)
    {

/*
        your_char = choose_char();
        their_char = get_char();
        winner = winner(your_char, their_char);
        score = score_update(winner);
        game_win(score, game_type);
*/

    }

    return 0;
}
