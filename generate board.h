#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void generateboard() { //initial generation of empty board
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

bool generateboard(int move, bool bot, int gamePosition[6][7]) {
    const string TOP_LINE = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
    const string EMPTY_CENTER_LINE = "[]          []";
    string centerLine;

    ifstream file;

    file.open("ascii art.txt");

    if (bot) {


        for (int i = 5; i >= 0; i--) {
            if (gamePosition[i][move - 1] != 0 && i == 0) return false;
            if (gamePosition[i][move - 1] != 0) continue;

            gamePosition[i][move - 1] = 1;

            break;
        }
    }
    else {

    }

    file.close();

    return false;
}

void initGamePos(int gamePosition[6][7]) { //initiate gamePos array
    for (int y = 0; y < 6; y++) { //incroment the y cord
        for (int x = 0; x < x; x++) { //increment the x cord
            gamePosition[y][x] = 0; //sets every value to 0 initially
        }
    }
}