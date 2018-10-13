/*---------------------In Game functions------------------------------*/

#include "ingame.h"
#include "auxiliary.h"

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

int exchange_options(char item_options[])
{
    int i = 0;
    int winner = 0;
    char their_item = 'a';
    char item_chosen = 0;
    while (item_chosen == 0 || their_item == 'a') {
        i= increment_options(item_options, i);
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            item_chosen = item_options[i];
            ir_uart_putc(item_chosen);
        }
        if (ir_uart_read_ready_p()) {
            their_item = ir_uart_getc();
        }
    }
    winner = decide_winner(item_chosen, their_item);
    return winner;
}


char play_round(void)
{
    char char_options[] = {'P', 'S', 'R'};
    int winner = exchange_options(char_options);

    return winner;
}

