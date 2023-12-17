#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;
class Board {
protected:
    int n_rows, n_cols;
    char** board;
    int n_moves = 0;

public:
    int countX_G3=0 ;
    int countO_G3=0 ;

    virtual bool update_board(int x, int y, char symbol) = 0;
    virtual bool is_winner() = 0;
    virtual bool is_draw() = 0;
    virtual void display_board() = 0;
    virtual bool game_is_over() = 0;
};
class X_O_Board:public Board {
public:
    X_O_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};
class Four_in_a_row_Board:public Board{
public:
    Four_in_a_row_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};
class Player {
protected:
    string name;
    char symbol;
public:
    Player (char symbol); // Needed for computer players
    Player (int order, char symbol);
    virtual void get_move(int& x, int& y);
    string to_string();
    char get_symbol();
};
class RandomPlayer: public Player {
protected:
    int dimension;
public:
    RandomPlayer (char symbol, int dimension);
    void get_move(int& x, int& y);
};
class fourinrow_player:public Player{
public:
    fourinrow_player (char symbol):Player(symbol){} // Needed for computer players
    fourinrow_player (int order,char symbol):Player(order,symbol){} // Needed for computer players
    void get_move(int& x, int& y);
};
class fourinrow_Randomplayer:public RandomPlayer{
public:
    fourinrow_Randomplayer (char symbol, int dimension):RandomPlayer(symbol,dimension){}
    void get_move(int& x, int& y);
};
class GameManager {
protected:
    Board *boardPtr;
    Player *players[2];
public:
    GameManager(Board *, Player *playerPtr[2]);

    void run();
};
class pyramic_XO_Board : public Board {
public:
    pyramic_XO_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};
class game
{
public:
    game();
    virtual ~game();

protected:

private:
};
class Game_3 : public Board {
public:
    Game_3();
    bool update_board(int x, int y, char symbol) ;
    void display_board() ;
    bool is_winner() ;
    bool is_draw() ;
    bool game_is_over() ;
};
class Player_3g : public Player{

public :
    Player_3g (int order ,char soymbol);
    // virtual
    void get_move(int& x, int& y) ;

};
