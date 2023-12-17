#include"Games.h"
void fourinrow_player::get_move(int& x, int& y){
    x=6;
    cout<<"enter your move y(0 to 6)";
    cin>>y;
    x--;
}
void fourinrow_Randomplayer::get_move(int& x, int& y){
    y=(int)(rand()/(RAND_MAX+1.0)*dimension);
}
Four_in_a_row_Board::Four_in_a_row_Board(){
    n_rows =6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool Four_in_a_row_Board::update_board (int x, int y, char mark){
    if (!(x<0||x>5 ||y < 0 || y > 6) && (board[0][y] ==0)) {
        for (int i = 5; i >= 0; i--) {
            if (board[i][y] == 0) {
                board[i][y] = toupper(mark);
                return true;

            }
        }
    }
    return false;
}
void Four_in_a_row_Board::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
bool Four_in_a_row_Board::is_winner() {
    char mark;
    for (int i = 0; i <= 5; i++) { //horizontal
        for (int j = 0; j <= 3; j++) {
            mark = board[i][j];
            if (mark != 0 && board[i][j + 1] == mark && board[i][j + 2] == mark && board[i][j + 3] == mark) {
                return true;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            mark = board[i][j];
            if (mark != 0 && board[i + 1][j] == mark && board[i + 2][j] == mark && board[i + 3][j] == mark) {
                return true;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= 3; j++) {
            mark = board[i][j];
            if (mark != 0 && board[i + 1][j + 1] == mark && board[i + 2][j + 2] == mark &&
                board[i + 3][j + 3] == mark) {
                return true;
            }
        }
    }
    for (int i = 3; i < 6; i++) {
        for (int j = 0; j <= 3; j++) {
            mark = board[i][j];
            if (mark != 0 && board[i - 1][j + 1] == mark && board[i - 2][j + 2] == mark &&
                board[i - 3][j + 3] == mark) {
                return true;
            }
        }
    }
    return false;
}
bool Four_in_a_row_Board::is_draw() {
    return (n_moves == 42 && !is_winner());
}
bool Four_in_a_row_Board::game_is_over () {
    return n_moves >= 42;
}GameManager::GameManager(Board* bPtr, Player* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}
 // update in  game manager 
void GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " wins " << players[(i==0)? 1:0]->to_string() << '\n';
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}
void RandomPlayer::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}
void Player::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 5) and (0,6)and separated by spaces: ";
    cin >> x >> y;
}
string Player::to_string(){
    return "Player: " + name ;
}
char Player::get_symbol() {
    return symbol;
}
X_O_Board::X_O_Board () {
    n_rows = n_cols = 3;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
    for (int i: {0,1,2}) {
        cout << "\n| ";
        for (int j: {0,1,2}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_Board::is_winner() {
    char row_win[3], col_win[3], diag_win[2];
    for (int i:{0,1,2}) {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i:{0,1,2}) {
        if ( (row_win[i] && (row_win[i] == board[i][0])) ||
             (col_win[i] && (col_win[i] == board[0][i])) )
        {return true;}
    }
    if ((diag_win[0] && diag_win[0] == board[1][1]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
    {return true;}
    return false;
}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over () {
    return n_moves >= 9;
}
RandomPlayer::RandomPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
Player::Player(char symbol) {
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}
pyramic_XO_Board::pyramic_XO_Board(){
    n_rows = 3; // Kept as 3 for pyramid shape
    n_cols = 5; // Kept as 5 for pyramid shape
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        fill(board[i], board[i] + n_cols, ' '); // Initialize with spaces instead of zeros
    }
}
// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool pyramic_XO_Board::update_board (int x, int y, char mark){
    // Only update if the move is valid
    if (!(x < 0 || x >= n_rows || y < 0 || y >= n_cols) && (board[x][y] == ' ')) { // Adjusted the boundaries and empty cell check
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else {
        return false;
    }
}


// Display the board and the pieces on it
void pyramic_XO_Board::display_board() {
    for (int i : {0, 1, 2}) {
        cout << "\n| ";
        int spaces = 0; // Variable to store the number of spaces before each row
        switch (i) { // Use a switch statement to assign the number of spaces based on the row index
            case 0:
                spaces = 0; // The first row has no spaces before it
                break;
            case 1:
                spaces = 4; // The second row has 4 spaces before it
                break;
            case 2:
                spaces = 8; // The third row has 8 spaces before it
                break;
        }
        for (int j : {0, 1, 2, 3, 4}) {
            if (i + j >= 2 && j - i < 3) { // Adjusted the condition to display the valid positions on the different pyramid
                if (spaces > 0) { // If the number of spaces is positive, add them before the first position on the row
                    cout << setw(spaces) << " ";
                    spaces = 0; // Reset the number of spaces to zero
                }
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " |"; // Use the default width of 2
            } else {
                cout << "       |"; // Print empty space for invalid positions
            }
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool pyramic_XO_Board::is_winner() {
    char player;

    // Check rows
    for (int i = 0; i < 3; i++) {
        player = board[i][0]; // Get the first cell of the row
        if (player != ' ' && board[i][1] == player && board[i][2] == player) {
            // If the row has the same non-empty symbol, return true
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        player = board[0][j]; // Get the first cell of the column
        if (player != ' ' && board[1][j] == player && board[2][j] == player) {
            // If the column has the same non-empty symbol, return true
            return true;
        }
    }

    // Check diagonals
    player = board[1][1]; // Get the center cell, which is common in both diagonals
    if (player != ' ') {
        if ((board[0][0] == player && board[2][2] == player) || // Check the main diagonal
            (board[0][2] == player && board[2][0] == player)) { // Check the anti-diagonal
            // If either diagonal has the same non-empty symbol, return true
            return true;
        }
    }

    // If none of the above conditions are met, return false
    return false;
}

// Return true if 9 moves are done and no winner
bool pyramic_XO_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}


bool pyramic_XO_Board::game_is_over () {
    return n_moves >= 9;
}
game::game()
{
    //ctor
}

game::~game()
{
    //dtor
}
Game_3::Game_3 () {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool Game_3::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
void Game_3 ::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
bool Game_3::is_winner() {
    char x;


    char row_win[15], col_win[15], diag_win[18];
    for (int i = 0; i< n_rows ;++i){
        for( int j = 0; j < n_cols -2 ;++j){
            row_win[i] = board[i][j] & board[i][j+1] & board[i][j+2];

        }
    }
    for(int j = 0;j< n_cols ;++j){
        for (int i =0; i< n_rows -2;++i){
            col_win[i] = board[i][j]& board[i+1][j] & board[i+2][j];

        }
    }
    //

    //check diagonal r
    for(int i = 0;i<n_rows-2 ;++i){
        for(int j =0 ; j< n_cols -2 ;++j){
            x= board[i][j]& board[i+1][j+1]& board[i+2][j+2];
            if( x && x == board[i][j] && x=='X'){
                countX_G3++;
            }
            if( x && x == board[i][j] && x=='O'){
                countO_G3++;
            }
        }
    }
    // check diao (l)
    for(int i = 0; i<n_rows-2;++i){
        for( int j= 2 ;j< n_cols;++j){
            x = board[i][j]& board[i+1][j-1]& board[i+2][j-2];

            if( x && x == board[i][j] && x=='X'){
                countX_G3++;
            }
            if( x && x == board[i][j] && x=='O'){
                countO_G3++;
            }


        }
    }

    for(int i:{0,1,2,3,4}){
        if ((row_win[i] and (row_win[i]  == board[i][0]) and row_win[i]=='X') or (col_win[i] and (col_win[i]  == board[0][i]) and row_win[i]=='X') ) {
            countX_G3++;
        }
        if ((row_win[i] and (row_win[i]  == board[i][0]) and row_win[i]=='O') or (col_win[i] and (col_win[i]  == board[0][i]) and row_win[i]=='O') ) {
            countO_G3++;
        }
    }
    return (countX_G3 > countO_G3);
}
bool Game_3::is_draw() {
    return (n_moves == 25);
}//
bool Game_3::game_is_over () {
    return n_moves >= 24;
}
