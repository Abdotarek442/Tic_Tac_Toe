#include <bits/stdc++.h>
#include"BoardGame_Classes.hpp"

using namespace std;

Pyramic_X_O::Pyramic_X_O() {
    n_rows = 3;
    n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++) {
            if (!((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0) || (i == 0 && j == 3) ||
                  (i == 0 && j == 4) ||
                  (i == 1 && j == 4)))
                board[i][j] = ' ';
            else
                board[i][j] = '1';
        }
    }
}

bool Pyramic_X_O::update_board(int x, int y, char mark) {
    if (!(x < 0 || x > 2 || y < 0 || y > 4) && (board[x][y] == ' ') &&
        !((x == 0 && y == 0) || (x == 0 && y == 1) || (x == 1 && y == 0) || (x == 0 && y == 3) || (x == 0 && y == 4) ||
          (x == 1 && y == 4))) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else
        return false;
}

void Pyramic_X_O::display_board() {
    for (int i: {0, 1, 2}) {
        cout << "\n| ";
        for (int j: {0, 1, 2, 3, 4}) {
            if (!((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0) || (i == 0 && j == 3) ||
                  (i == 0 && j == 4) ||
                  (i == 1 && j == 4))) {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " |";
            } else {
                cout << "       ";
                cout << setw(2) << " |";
            }
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;
}

bool Pyramic_X_O :: is_winner() {
    
    if ((board[0][2] == board[1][2] && board[1][2] == board[2][2] && (board[0][2] != ' ')) ||
        (board[1][1] == board[1][2] && board[1][2] == board[1][3] && (board[1][1] != ' ')) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && (board[0][2] != ' ')) ||
        (board[0][2] == board[1][3] && board[1][3] == board[2][4] && (board[0][2] != ' ')) ||
        (board[2][0] == board[2][1] && board[2][1] == board[2][2] && (board[2][0] != ' ')) ||
        (board[2][1] == board[2][2] && board[2][2] == board[2][3] && (board[2][1] != ' ')) ||
        (board[2][2] == board[2][3] && board[2][3] == board[2][4] && (board[2][2] != ' ')))
        return true;
    else
        return false;
}

bool Pyramic_X_O::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Pyramic_X_O::game_is_over() {
    return n_moves >= 9;
}