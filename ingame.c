/*
    * File:     ingame.c
    * Authors:  Samuel Crawley (43420688)
    *           Luke Trenberth (47277086)
    * Date:     13.10.18
    * Brief:    Files required to run 1 round
*/
#include "ingame.h"
#include "auxiliary.h"

/*---------------------In Game functions------------------------------*/
/** Finds the winner and loser 'P'-Paper, 'S'-Scissors, 'R'-Rock
    @param Player1 character
    @param Player2 character
    @return 1-Player1 won, 2-Player2 won, 0-Draw*/
int decide_winner (char input1, char input2)
{
    int winner = 0;
    if (input1 == 'P') {
        //Player 1 selects paper
        if (input2 == 'S') {
            winner = 2;
        } else if (input2 == 'R') {
            winner = 1;
        } else {
            winner = 0;
        }
    } else if (input1 == 'S') {
        //Player 1 selects Scissors
        if (input2 == 'R') {
            winner = 2;
        } else if (input2 == 'P') {
            winner = 1;
        } else {
            winner = 0;
        }
    } else if (input1 == 'R') {
        //Player 1 selects Rock
        if (input2 == 'P') {
            winner = 2;
        } else if (input2 == 'S') {
            winner = 1;
        } else {
            winner = 0;
        }
    } else {
        winner = 0;
        // Error catching
    }
    return winner;
}

/** Finds the winner and loser 'P'-Paper, 'S'-Scissors, 'R'-Rock
    @param Options to choose
    @return winner of game(1-Player1 won, 2-Player2 won, 0-Draw)*/
int exchange_options(char item_options[])
{
    int i = 0;
    int winner = 0;
    char their_item = 'a';
    char item_chosen = 0;
    while (item_chosen == 0 || their_item == 'a') {
        //While loop continues until both players have selected an input
        i= increment_options(item_options, i); // Chooses the display option
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            //If nav button is pushed, select item and send output to other controller
            item_chosen = item_options[i];
            ir_uart_putc(item_chosen);
        }
        if (ir_uart_read_ready_p()) {
            //If a signal is received, set player 2's selection to the received char
            their_item = ir_uart_getc();
        }
    }
    winner = decide_winner(item_chosen, their_item); //Finds winner from 2 selections
    return winner;
}

/** Chooses PSR options
    @return winner of round*/
char play_round(void)
{
    char char_options[] = {'P', 'S', 'R'}; //Chooses P, S, R options
    int winner = exchange_options(char_options); //Finds the winner

    return winner;
}

