#include <iostream>
#include <string>
#include <limits>
#include "board.h"
#include "Bot.h"
using namespace std;

void getPlayerName(string &player) {
    cout << "Player, what is your name?\n";
    getline(cin, player);
    system("clear");
    cout << "Are you ready?\n";
    string randomBS;
    cin >> randomBS;
    cout << "Doesn't matter any way cuz we're starting\n";
}

int botMove(int game[7][6], int turn);

int main() {
    string player;

    getPlayerName(player);

    int game[7][6];

    initGamePos(game);

    bool whoseTurn = false; //true = player
    int turn = 1;
 
    while(!checkWin(game)) {
        int move;
        generateBoard(game);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (whoseTurn) {
            cout << player + ": ";
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
        else {
            move = botMove(game, turn);
            makeMove(move, true, game);
        }
        turn++;
    }

    if (!whoseTurn) {
        system("clear");
        generateBoard(game);
        cout << player + " has won\n";
    } 
    else {
        system("clear");
        generateBoard(game);
        cout << "the bot has won\n" + player + " you suck\n";
    }
    return 0;
}