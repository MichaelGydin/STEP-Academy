#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];

void initBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "| ";
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " | ";
        } cout << endl << "-------------" << endl;
    }
}

bool isFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    } return true;
}

bool checkWin(char player) {
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    } return false;
}

bool makeMove(int row, int col, char player) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
        return false;
    } board[row][col] = player; return true;
}

int main() {
    initBoard();
    char Player = 'X';
    bool gameOver = false;

    while (!gameOver) {
        printBoard();
        int row, col;  cout << "Player " << Player << ", enter your move (row: 0-2): "; cin >> row;
        cout << "Player " << Player << ", enter your move (col: 0-2): "; cin >> col;

        if (!makeMove(row, col, Player)) {
            cout << "Invalid move." << endl;
            continue;
        }
        if (checkWin(Player)) {
            printBoard();
            cout << "Player " << Player << " wins!" << endl;
            gameOver = true;
        }
        else if (isFull()) {
            printBoard();
            cout << "Draw!" << endl;
            gameOver = true;
        } Player = (Player == 'X') ? 'O' : 'X';
    } return 0;
}