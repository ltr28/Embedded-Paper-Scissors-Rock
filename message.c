/*
    *File:    message.c
    *Authors: Samuel Crawley (43420688)
              Luke Trenberth (47277086)
    *Date:    13.10.18
    *Brief:   displays messages throughout PAPER SCISSORS ROCK
*/

/*---------------------Message functions------------------------------*/

#include "message.h"
#include "auxiliary.h"

/**Is called by the other message functions to display the message */
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

/**Displays the message at the beginning of the game "Best of: "*/
void initial_message (void) {

    tinygl_text("  Best of: ");
    display_message();
}

/**Displays the message "Object: "*/
void choose_char_message (void) {

    tinygl_text("  Object: ");
    display_message();
}

/**Displays the relevant message describing the reuslt of the round "Round: You Drew!", "Round: You Won!" or "Round: You Lost!"
    @param integer representing if you drew(0) if you won(1) or if the other player won(2)*/
void round_result_message (int winner) {

    if (winner == 0)
    {
        tinygl_text("  Round: You Drew!");
        display_message();
    }
    else if (winner == 1)
    {
        tinygl_text("  Round: You Won!");
        display_message();
    }
    else if (winner == 2)
    {
        tinygl_text("  Round: You Lost!");
        display_message();
    }

}

/**Displays the relevant message describing the reuslt of the game "GAME OVER: You Win !" or "GAME OVER: You Lost!"
    @param integer representing if you won the game (1) or not (0)*/
void game_result_message(int did_you_win_game)
{
    if (did_you_win_game)
    {
        tinygl_text("  GAME OVER: You Win!");
        display_message();
    }
    else {
        tinygl_text("  GAME OVER: You Lose!");
        display_message();
    }
}
