#include <stdio.h>
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
int main(void)
{
    int win = 0;
    win = winner('S', 'P');
    printf("Winner was player %d\n", win);
    win = winner('S', 'R');
    printf("Winner was player %d\n", win);
    win = winner('R', 'R');
    printf("Winner was player %d\n", win);
}
