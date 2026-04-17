#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void generateBoard() { //initial generation of empty board
    const string topbottomLine = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
    const string center = "[]          []          []          []          []          []          []          []";

    system("clear");

    for (int i = 0; i < 6; i++) {
        cout << topbottomLine << endl;

        for (int i = 0; i < 5; i++) {
            cout << center << endl;
        }
    }
    cout << topbottomLine << endl;
}

bool makeMove(int move, bool which, int gamePosition[7][6]) {
    if (which) { //if the bot is making a move 
        for (int i = 5; i >= 0; i--) { //incrament up the column that is being played
            if (gamePosition[move - 1][i] != 0 && i == 0) return false; //will catch if the whole column is full and return false to siginify an illigal move
            if (gamePosition[move - 1][i] != 0) continue; //check if the position in the column is taken

            gamePosition[move - 1][i] = 1; //when an open position is found will set it to 2 representing a player piece
            break;
        }
    }
    else { //if the player is making a move
        for (int i = 5; i >= 0; i--) { //incrament up the column that is being played
            if (gamePosition[move - 1][i] != 0 && i == 0) return false; //will catch if the whole column is full and return false to siginify an illigal move
            if (gamePosition[move - 1][i] != 0) continue; //check if the position in the column is taken

            gamePosition[move - 1][i] = 2; //when an open position is found will set it to 2 representing a player piece
            break;
        }
    }
    return true;
}

void initGamePos(int gamePosition[7][6]) { //initiate gamePos array
    for (int y = 0; y < 6; y++) { //incroment the y cord
        for (int x = 0; x < 7; x++) { //increment the x cord
            gamePosition[x][y] = 0; //sets every value to 0 initially
        }
    }
}