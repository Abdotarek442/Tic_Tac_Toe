//File name : Four_in_a_row.cpp
//purpose   :The Game (Four in a Row )
//Author    : Al-Hussain Abdo Mohamed
//ID        :20220878
//Section   :S23
//Date      :15/12/2023
#include <bits/stdc++.h>
#include"BoardGame_Classes.hpp"

using namespace std;
four_in_a_row:: four_in_a_row() {
    n_rows = 6, n_cols = 7;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool four_in_a_row :: update_board (int x, int y, char mark)
{
    if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0)) {
        if(x!=5&&board[x+1][y]==0){
            cout<<"\n{ put your choice in valid address according to four in a row ruls !! }\n";
            return false;
        }
        else{
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }

    }
    else
        return false;
}
void four_in_a_row :: display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------------------------";
    }
    cout << endl;
}
bool four_in_a_row :: is_winner() {
    string checkerh,checkerv,checkerd;

    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (board[i][j] == 'X' && board[i][j + 1] == 'X' && board[i][j + 2] == 'X' && board[i][j + 3] == 'X') {
                return true;  // 'X' wins horizontally
            }
            if (board[i][j] == 'O' && board[i][j + 1] == 'O' && board[i][j + 2] == 'O' && board[i][j + 3] == 'O') {
                return true;  // 'O' wins horizontally
            }
        }
    }
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (board[i][j] == 'X' && board[i + 1][j] == 'X' && board[i + 2][j] == 'X' && board[i + 3][j] == 'X') {
                return true;  // 'X' wins vertically
            }
            if (board[i][j] == 'O' && board[i + 1][j] == 'O' && board[i + 2][j] == 'O' && board[i + 3][j] == 'O') {
                return true;  // 'O' wins vertically
            }
        }
    }
    // Check diagonally (\)
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (board[i][j] == 'X' && board[i + 1][j + 1] == 'X' && board[i + 2][j + 2] == 'X' && board[i + 3][j + 3] == 'X') {
                return true;  // 'X' wins diagonally
            }
            if (board[i][j] == 'O' && board[i + 1][j + 1] == 'O' && board[i + 2][j + 2] == 'O' && board[i + 3][j + 3] == 'O') {
                return true;  // 'O' wins diagonally
            }
        }
    }
    // Check diagonally (/)
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = 3; j < n_cols; ++j) {
            if (board[i][j] == 'X' && board[i + 1][j - 1] == 'X' && board[i + 2][j - 2] == 'X' && board[i + 3][j - 3] == 'X') {
                return true;  // 'X' wins diagonally
            }
            if (board[i][j] == 'O' && board[i + 1][j - 1] == 'O' && board[i + 2][j - 2] == 'O' && board[i + 3][j - 3] == 'O') {
                return true;  // 'O' wins diagonally
            }
        }
    }

    return false;
}
bool four_in_a_row :: is_draw() {
    return (n_moves == 42 && !is_winner());
}
bool four_in_a_row :: game_is_over() {
    return n_moves >= 42;
}