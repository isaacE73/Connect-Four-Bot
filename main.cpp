#include <iostream>
#include <string>
#include "generate board.h"
using namespace std;

int main() {
    int gamePosition[7][6];
    const bool bot = true;
    const bool player = false;

    initGamePos(gamePosition);

    for (int y = 0; y < 6; y++) { //incroment the y cord
        for (int x = 0; x < 7; x++) { //increment the x cord
            cout << gamePosition[x][y];
        }
        cout << endl;
    }

    gamePosition[6][5] = 2;

    cout << endl;

    makeMove(7, bot, gamePosition);

    for (int y = 0; y < 6; y++) { //incroment the y cord
        for (int x = 0; x < 7; x++) { //increment the x cord
            cout << gamePosition[x][y];
        }
        cout << endl;
    }

    return 0;
}