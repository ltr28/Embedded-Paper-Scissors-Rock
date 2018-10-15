/*
    *File:    message.c
    *Authors: Samuel Crawley (43420688)
              Luke Trenberth (47277086)
    *Date:    13.10.18
    *Brief:   displays messages throughout Paper Scissors Rock
*/


/*---------------------Message functions------------------------------*/

#include "message.h"
#include "auxiliary.h"


/**Displays the message at the beginning of the game "Best of: "*/
void display_message (char* text) {

    tinygl_text(text);
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

/**Displays the relevant message describing the reuslt of the round "Round: You Drew!", "Round: You Won!" or "Round: You Lost!"
    @param integer representing if you drew(0) if you won(1) or if the other player won(2)*/
void round_result_message (int winner) {

    if (winner == 0)
    {
        display_message("  Round: You Drew!");
    }
    else if (winner == 1)
    {
        display_message("  Round: You Won! ");
    }
    else if (winner == 2)
    {
        display_message("  Round: You Lost!");
    }

}

/**Displays the relevant message describing the reuslt of the game "GAME OVER: You Win !" or "GAME OVER: You Lost!"
    @param integer representing if you won the game (1) or not (0)*/
void game_result_message(int did_you_win_game)
{
    if (did_you_win_game)
    {
        display_message("  GAME OVER: You Win! ");
    }
    else {
        display_message("  GAME OVER: You Lose!");
    }
}

