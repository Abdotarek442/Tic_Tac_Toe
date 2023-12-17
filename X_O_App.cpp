
#include <iostream>
#include"BoardGame_Classes.hpp"
#include "Pyramic_X_O.cpp"
#include "RandomPlayer.cpp"
#include "Player.cpp"
#include "GameManager.cpp"
#include "four_in_a_row.cpp"
#include "X_O_Board.cpp"

using namespace std;

int main() {
    int choice;
    Player* players[2];
    cout << "Welcome to FCAI X-O Game. :)\n";
    cout<<"Choose Game: "<<'\n';
    cout<<"Enter 1 for Pyramid XO "<<'\n';
    cout<<"Enter 2 for Four in a row XO "<<'\n';
    cout << "Enter 3 for 5*5 XO \n";
    int choice2;
    cin>>choice2;
    players[0] = new Player (1, 'x');
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        players[1] = new RandomPlayer ('o', 5);

    if(choice2 == 1 ) {
        GameManager x_o_game(new Pyramic_X_O(), players);
        x_o_game.run();
    }
    else if (choice2 == 2){
        GameManager x_o_game(new four_in_a_row(), players);
        x_o_game.run();
    }
   else if ( choice2 == 3 ){
     GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
   }
    system ("pause");
}

