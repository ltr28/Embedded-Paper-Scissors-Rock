#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "delay.h"

#define PACER_RATE 500
#define MESSAGE_RATE 20

/*------------------Auxiliary functions------------------------------*/
void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text(buffer);
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

int choose_results(char item_options[])
{
    int i = 0;
    int winner = 0;
    char their_item = 'a';
    char item_chosen = 0;
    while (item_chosen == 0 || their_item == 'a') {
        pacer_wait();
        tinygl_update();
        navswitch_update ();
        if (navswitch_push_event_p (NAVSWITCH_NORTH) && i < 2) {
            i++;
        }
        if (navswitch_push_event_p (NAVSWITCH_SOUTH) && i > 0) {
            i--;
        }
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            item_chosen = item_options[i];
            ir_uart_putc(item_chosen);
        }
        if (ir_uart_read_ready_p()) {
            their_item = ir_uart_getc();
        }
        display_character(item_options[i]);
    }
    winner = decide_winner(item_chosen, their_item);
    return winner;
}

char choose_item(char item_options[])
{
    int i = 0;
    char item_chosen = 0;
    char their_item = 'a';
    while (item_chosen != their_item) {
        pacer_wait();
        tinygl_update();
        navswitch_update ();
        if (navswitch_push_event_p (NAVSWITCH_NORTH) && i < 2) {
            i++;
        }
        if (navswitch_push_event_p (NAVSWITCH_SOUTH) && i > 0) {
            i--;
        }
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            item_chosen = item_options[i];
            ir_uart_putc(item_chosen);
        }
        if (ir_uart_read_ready_p()) {
            their_item = ir_uart_getc();
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

/*---------------------Message functions------------------------------*/

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

void game_result_message(int did_you_win_game)
{
    if (did_you_win_game)
    {
        tinygl_text("GAME OVER: You Win!");
        display_message();
    }
    else {
        tinygl_text("GAME OVER: You Lose!");
        display_message();
    }
}


/*---------------------Game functions------------------------------*/

char choose_game (void)
{

    char game_options[] = {'1', '3', '5'};
    char game_chosen = choose_item(game_options);

    return game_chosen;
}

char choose_char(void)
{
    char char_options[] = {'P', 'S', 'R'};
    int winner = choose_results(char_options);

    return winner;
}

int calc_round_limit(char game_type)
{
    int round_limit = 0;

    if (game_type == '1')
    {
        round_limit = 1;
    }
    else if (game_type == '3')
    {
        round_limit = 2;
    }
    else if (game_type == '5')
    {
        round_limit = 3;
    }

    return round_limit;
}



int update_score(int winner, int player, int score)
{
    if (winner == player) {
        score += 1;
    }
    return score;
}


int check_continue(int round_limit, int your_score, int their_score)
{
    int continue_game = 0;

    if (your_score < round_limit && their_score < round_limit)
    {
        continue_game = 1;
    }

    return continue_game;
}

int find_game_result(int your_score, int their_score)
{
    int did_you_win_game = 0;

    if (your_score > their_score)
    {
        did_you_win_game = 1;
    }

    return did_you_win_game;
}

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
            round_winner = choose_char();
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
