// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

int dx [] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {1,-1,0,1,-1,1,-1,0};


bool valid(int x , int y ) {
    return x >= 0 && y >= 0 && x < 5 && y < 5 ;
}


X_O_Board::X_O_Board () {
   n_rows = n_cols = 5;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

bool X_O_Board::update_board (int x, int y, char mark){
   if (!(x < 0 || x > 5 || y < 0 || y > 5) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

void X_O_Board::display_board() {
   for (int i: {0,1,2,3,4}) {
      cout << "\n| ";
      for (int j: {0,1,2,3,4}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n------------------------------------------";
   }
   cout << endl;
   if (n_moves == 24)
  { 
     for (int i = 0 ; i < 5 ; i++ ){
      for (int j = 0 ; j < 5 ; j ++ ){
            for (int k = 0 ; k < 8 ; k++ ){
               int xx = dx[k];
               int yy = dy[k];
               int cont = 0 , n = 2 ;
               while ( n-- ){
                  if (  valid( i+ xx,  j + yy) && (board[i][j] == board[i + xx][ j + yy]) ){
                     cont ++ ;
                     xx += xx;
                     yy += yy;
                  }
               } 
               if (cont == 2 ){
                  if ( board[i][j] == 'X')
                     x++;
                  else o ++ ;
               }
            }
      }
   }
   }
   
}

bool X_O_Board :: is_winner() {
      return (n_moves == 24 && (x > o) || (o > x ) );
}
bool X_O_Board::is_draw() {
   return (n_moves == 24 && !is_winner());
}

bool X_O_Board::game_is_over () {
    return n_moves > 24;
}
