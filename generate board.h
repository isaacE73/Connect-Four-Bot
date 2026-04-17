#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void generateboard() {
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