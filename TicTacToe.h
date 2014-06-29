/*Tic Tac Toe Game v1.0
Released under the GPL liscence version 2
Written by JohnBobSmith*/

/*Tic Tac Toe Game v1.0
Released under the GPL liscence version 2
Written by JohnBobSmith*/

#ifndef TICTACTOE_H
#define TICTACTOE_H


class TicTacToe
{
    public:
        TicTacToe();
        int run_game();
        char lastPlayerMove;
        bool exitGame = false;
    private:
        void update_board(char playerPiece);
        void print_board(char playerPiece, int row, int col);
        void check_for_overlap(int row, int col);
        int check_for_exit(char playerPiece);
        char board[3][3];
};

#endif // TICTACTOE_H
