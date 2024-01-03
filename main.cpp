#include"function.h"

int main() 
{
    vector<vector<char>> board(3, vector<char>(3, ' '));
    int row, col;
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!\n";

    do {
        // Print the current board
        printBoard(board);

        // Get the next move from the current player
        do {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
        } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ');

        // Make the move
        if (!makeMove(board, currentPlayer, row - 1, col - 1)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for a draw
        if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch to the next player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);

    return 0;
}

