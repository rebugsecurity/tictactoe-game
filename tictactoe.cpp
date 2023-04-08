#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row, column;
bool draw = false;

void display_board() {
    cout << "*********************" << endl;
    cout << "  TIC TAC TOE GAME  " << endl;
    cout << "*********************" << endl;
    cout << endl;
    
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl << endl;
}

void player_turn() {
    int choice;
    if (turn == 'X') {
        cout << "Player 1 (X) turn: ";
    }
    else if (turn == 'O'){
        cout << "Player 2 (O) turn: ";
    }
    cin >> choice;

    switch(choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid Move" << endl;
            player_turn();
    }

    if (turn == 'X' && board[row][column] == ' ') {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] == ' ') {
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        cout << "The cell is already occupied" << endl;
        player_turn();
    }
}

bool game_over() {
    // check win
    for (int i=0; i<3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || 
        board[0][i] == board[1][i] && board[0][i] == board[2][i] || 
        board[0][0] == board[1][1] && board[0][0] == board[2][2] || 
        board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return true;
        }
    }
    // check draw
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    draw = true;
    return true;
}

int main() {
    while (!game_over()) {
        display_board();
        player_turn();
        game_over();
    }

    display_board();

    if (turn == 'X' && !draw) {
        cout << "Player 2 (O) Wins!" << endl;
    }
    else if (turn == 'O' && !draw) {
        cout << "Player 1 (X) Wins!" << endl;
    }
    else {
        cout << "Draw!" << endl;
    }

    return 0;
}