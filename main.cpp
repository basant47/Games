#include"Games.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;
int main() {
    int choice;
    int num_game;

    cout << "Welcome to Four in a row Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1){
        cout<< "what you want to play enter 1 if you want to play xo or enter 2 if you want (four in row) game or 3 if you want pyramic tic_tac_toe game or 4 if you want tic tac toe game ";
        cin >> num_game;
        if (num_game == 1) {
            Player *players[2];
            players[0] = new Player(1, 'x');
            players[1] = new Player(2, 'o');

            GameManager x_o_game(new X_O_Board(), players);
            x_o_game.run();
        } else if (num_game == 2)
        {
            Player *players[2];
            players[0] = new fourinrow_player(1, 'x');
            players[1] = new fourinrow_player(2, 'o');
            GameManager fourinarow_game(new Four_in_a_row_Board(), players);
            fourinarow_game.run();
        }
          if (num_game == 3); {
            Player *players[2];
            players[0] = new Player(1, 'x');
            players[1] = new Player(2, 'o');
            GameManager x_o_game(new pyramic_XO_Board(), players);
            x_o_game.run();
        }
         if(num_game==4){
                Player* players[2];
                players[0] = new Player (1, 'x');
                players[1] = new Player (2, 'o');
                GameManager x_o_game (new Game_3(), players);
                x_o_game.run();
        }
    }
    else if (choice == 1){
        cout<< "what you want to play enter 1 if you want to play xo or enter 2 if you want( four in row) game or 3 if you want pyramic tic_tac_toe game or 4 if you want tic tac toe game ";
        cin >> num_game;
        if (num_game==1) {
            Player *players[2];
            players[0] = new Player(1, 'x');
            players[1] = new RandomPlayer('o', 3);

            GameManager x_o_game(new X_O_Board(), players);
            x_o_game.run();

        }
        else if(num_game == 2) {
            Player *players[2];
            players[0] = new fourinrow_player(1, 'x');
            players[1] = new RandomPlayer('o', 3);
            GameManager fourinarow_game(new Four_in_a_row_Board(), players);
            fourinarow_game.run();
        }
         if (num_game==3){
            Player* players[2];
            players[0] = new Player (1, 'x');
            players[1] = new RandomPlayer ('o', 3);
            //GameManager x_o_game (new pyramic_XO_Board(), players);
            //x_o_game.run();
            GameManager pyramic (new pyramic_XO_Board(), players);
            pyramic.run();
        }
        if(num_game==4){
            Player* players[2];
            players[0] = new Player (1, 'x');
            players[1] = new RandomPlayer ('o', 5);
            GameManager tic_tac (new Game_3(), players);
            tic_tac.run();
        }

    }
    system ("pause");
}

//Player pointer points to child
