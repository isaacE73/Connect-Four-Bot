#include <iostream>
#include <string>
#include "board.h"
using namespace std;

int main() {
    int gamePosition[7][6];
    const bool bot = true;
    const bool player = false;

    initGamePos(gamePosition);

    //print the board in the integer form
    for (int y = 0; y < 6; y++) { //incroment the y cord
        for (int x = 0; x < 7; x++) { //increment the x cord
            cout << gamePosition[x][y];
        }
        cout << endl;
    }

    


    return 0;
}