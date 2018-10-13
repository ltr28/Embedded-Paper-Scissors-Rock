/*---------------------Message functions------------------------------*/

#include "message.h"
#include "auxiliary.h"

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

void initial_message (void) {

    tinygl_text("  Best of: ");
    display_message();
}

void choose_char_message (void) {

    tinygl_text("  Object: ");
    display_message();
}

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
