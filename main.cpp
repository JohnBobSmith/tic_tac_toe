/*Tic Tac Toe Game v1.0
Released under the GPL liscence version 2
Written by JohnBobSmith*/

#include "TicTacToe.h"

int main()
{
    TicTacToe TTT;
    while (TTT.exitGame == false){
        TTT.run_game();
    }
}
