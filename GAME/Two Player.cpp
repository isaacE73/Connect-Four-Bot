#include <iostream>
#include <string>
#include <limits>
#include "board.h"
using namespace std;

void getPlayerName(string &player1, string &player2) {
    cout << "Player 1, what is your name?\n";
    getline(cin, player1);
    system("clear");
    cout << "Player 2, what is your name?\n";
    getline(cin, player2);
    system("clear");
    cout << "Are you ready?\n";
    string randomBS;
    cin >> randomBS;
    cout << "Doesn't matter any way cuz we're starting\n";
}

int main() {
    string player1;
    string player2;

    getPlayerName(player1, player2);

    int game[7][6];

    initGamePos(game);

    bool whoseTurn = true; //true = player1
 
    while(!checkWin(game)) {
        int move;
        generateBoard(game);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (whoseTurn) {
            cout << player1 + ": ";
            cin >> move;

            if (!makeMove(move, true, game)) {
                system("clear");
                cout << "invalid move\n";
                continue;
            }
            else {
                whoseTurn = !whoseTurn;
            }
        }
        else {
            cout << player2 + ": ";
            cin >> move;

            if (!makeMove(move, false, game)) {
                system("clear");
                cout << "invalid move\n";
                continue;
            }
            else {
                whoseTurn = !whoseTurn;
            }
        }
        system("clear");
    }

    if (!whoseTurn) {
        system("clear");
        generateBoard(game);
        cout << player1 + " has won\n" + player2 + " you suck\n";
    } 
    else {
        system("clear");
        generateBoard(game);
        cout << player2 + " has won\n" + player1 + " you suck\n";
    }
    return 0;
}