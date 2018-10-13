/*----------------------Scoring Functions-----------------------------*/

#include "scoring.h"
#include "auxiliary.h"

char choose_game (void)
{
    char game_options[] = {'1', '3', '5'};
    char game_chosen = choose_item(game_options);

    return game_chosen;
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
    if (winner == player)
    {
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

