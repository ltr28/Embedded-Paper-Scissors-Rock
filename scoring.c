/*
    *File:    scoring.c
    *Authors: Samuel Crawley (43420688)
              Luke Trenberth (47277086)
    *Date:    13.10.18
    *Brief:   functions that use scores throughout Paper Scissors Rock
*/


/*----------------------Scoring Functions-----------------------------*/

#include "scoring.h"
#include "auxiliary.h"

/**Chooses the game type to be played. Can either be best of 1, 3 or 5
    @return the character equivelent of either 1, 3 or 5*/
char choose_game (void)
{
    char game_options[] = {'1', '3', '5'};
    char game_chosen = choose_item(game_options);

    return game_chosen;
}

/** Calculates the limit to the number of rounds for a single player in the game type chosen.
    If game type is best of 1, 3 or 5 the player round limit is 1 , 2 or 3 respectively.
    @param game type chosen
    @return the maximum number of rounds of each player*/
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

/** Increments the score of one of the players by 1 after a round
    @param the winner of the round. Is either you (1) or the other player (2)
    @param the player to have their score incremented. Is either you (1) or the other player (2)
    @return the score of the player*/
int update_score(int winner, int player, int score)
{
    if (winner == player)
    {
        score += 1;
    }
    return score;
}

/** Checks if the game should continue to another round based on whether each of the players scores are less than the round limit
    @param the round limit
    @param your score
    @param the other players score
    @return an int indicating that the game should continue (1) or not (0)*/
int check_continue(int round_limit, int your_score, int their_score)
{
    int continue_game = 0;
    if (your_score < round_limit && their_score < round_limit)
    {
        continue_game = 1;
    }
    return continue_game;
}

/** Determines who wins the game by who has the highest score.
    @param your score
    @param the other players score
    @return returns an int indicating if you won the game (1) or not (0) */
int find_game_result(int your_score, int their_score)
{
    int did_you_win_game = 0;
    if (your_score > their_score)
    {
        did_you_win_game = 1;
    }
    return did_you_win_game;
}

