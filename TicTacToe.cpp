/*Tic Tac Toe Game v1.0
Released under the GPL liscence version 2
Written by JohnBobSmith*/

#include "TicTacToe.h"
#include <iostream>
#include <limits>

char board[3][3];

TicTacToe::TicTacToe()
{
    std::cout << "\nWelcome to tic tac toe!" << std::endl;
    std::cout << "Here is a blank board: " << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << std::endl;
        for (int j = 0; j < 3; j++){
            board[i][j] = '-';
            std::cout << board[i][j];
        }
    }
}

void TicTacToe::print_board(char playerPiece, int row, int col)
{
    //prints out the updated board when called upon to do so
    for(int i = 0; i < 3; i++){
        std::cout << "\n";
        for (int j = 0; j < 3; j++){
            board[row][col] = playerPiece;
            std::cout << board[i][j];
        }
    }
}

void TicTacToe::check_for_overlap(int row, int col)
{
    if (board[row][col] != '-'){
        std::cout << "\nOVERLAP DETECTED!!!!!!" << std::endl;
        if (lastPlayerMove == 'X'){
            std::cout << "\nThe board has been re-set" << std::endl;
            std::cout << "\nPlayer X, please go again" << std::endl;
            print_board('O', row, col);
        } else if (lastPlayerMove == 'O'){
            std::cout << "\nThe board has been re-set" << std::endl;
            std::cout << "\nPlayer O, please go again" << std::endl;
            print_board('x', row, col);
        }
    }
}

void TicTacToe::update_board(char playerPiece)
{
    //updates the board based on user input
    int playerRow, playerCol;
    std::cout << "\nEnter a position to place the " << playerPiece << " on the board" << std::endl;
    while (true){
        std::cout << "Enter row: " << std::endl;
        std::cin >> playerRow;
        if (playerRow < 1 || playerRow > 3 || std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Your number is invalid. Try again. " << std::endl;
        } else {
            break;
        }
    }
    while (true)
    {
        std::cout << "Enter col: " << std::endl;
        std::cin >> playerCol;
        if (playerCol < 1 || playerCol > 3 || std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Your number is invalid. Try again. " << std::endl;
        } else {
            break;
        }
    }
    playerCol = playerCol - 1;
    playerRow = playerRow - 1;
    check_for_overlap(playerRow, playerCol);
    print_board(playerPiece, playerRow, playerCol);
}

int TicTacToe::check_for_win(char playerPiece)
{
    /*slices the board and checks if playerPiece occupies that slot.
    If the player makes a line, print that playerPiece has won
    and exit the game.*/

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == playerPiece && board[i][1] == playerPiece && board[i][2] == playerPiece){
            std::cout << "\nPlayer " << playerPiece << " wins!" << std::endl;
            return true;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == playerPiece && board[1][i] == playerPiece && board[2][i] == playerPiece){
            std::cout << "\nPlayer " << playerPiece << " wins!" << std::endl;
            return true;
        }
    }
    if(board[0][0] == playerPiece && board[1][1] == playerPiece && board[2][2] == playerPiece){
        std::cout << "\nPlayer " << playerPiece << " wins!" << std::endl;
    }
    if(board[0][2] == playerPiece && board[1][1] == playerPiece && board[2][0] == playerPiece){
        std::cout << "\nPlayer " << playerPiece << " wins!" << std::endl;
    }
    return false;
}

int TicTacToe::run_game()
{
    char letter_o = 'O';
    char letter_x = 'X';
    while (true){
        std::cout << "\nPlayer one, it is your turn" << std::endl;
        update_board(letter_x);
        if (check_for_win(letter_x) == true){
            exitGame = true;
            break;
        }
        std::cout << "\nPlayer two, it is your turn" << std::endl;
        update_board(letter_o);
        if (check_for_win(letter_o) == true){
            exitGame = true;
            break;
        }
    }
}
