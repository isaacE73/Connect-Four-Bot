#include <fstream>
#include <iostream>
#include <cmath>
#include "board.h"
using namespace std;

void creatBoard(int board[7][6], unsigned long long int pos, int turn);
/*
Arguments:
    1. turns to be searched
    2. starting turn
*/
int main(int argc, char* arg[]) {
    unsigned int turns = stoi(arg[1]); //how many turns will be looked at
    unsigned int startingTurn = stoi(arg[2]); //what turn to start at
    unsigned long long int positions; //how many turns will be checked
    unsigned long long int wins;
    int board[7][6];//the game board
    string lastTurn[stoi(arg[1])];

    for (int turn = 0; turn < turns; turn++) { //incument through the number of turns

        wins = 0;

        string name = to_string(turn + startingTurn);

        name += ".bin";

        ofstream file;

        file.open(name, ios::binary);

        positions = pow(7, (startingTurn + turn)); //how many positions will be looked through

        for (unsigned long long int curPos = 0; curPos < positions; curPos++) { //incrament through EVERY position in that turn and check for wins
            system("clear");

            for (int i = 0; i < turn; i++) { //display all the previous turns message
                cout << lastTurn[i] << endl;
            } 

            cout << "Turn: " << turn + startingTurn << "\tPosition: " << curPos << "/" << positions << "\t wins: " << wins << endl;

            initGamePos(board);
            creatBoard(board, curPos, startingTurn + turn); //create the current board position

            if (checkWin(board)) {
                wins++;
                
                int Turn = turn + startingTurn;

                int bytes;
                if (Turn <= 2) {
                    bytes = 1;
                }
                else if (Turn <= 5) {
                    bytes = 2;
                }
                else if (Turn <= 8) {
                    bytes = 3;
                }
                else if (Turn <= 11) {
                    bytes = 4;
                }
                else if (Turn <= 14) {
                    bytes = 5;
                }
                else if (Turn <= 17) {
                    bytes = 6;
                }
                else if (Turn <= 19) {
                    bytes = 7;
                }
                else if (Turn = 20) {
                    bytes = 8;
                }

                file.write(reinterpret_cast<char*>(&Turn), 1);

                file.write(reinterpret_cast<char*>(&curPos), bytes);
            }
        }

        file.close();

        lastTurn[turn] = "Turn: " + to_string(turn + startingTurn) + "\tWins: " + to_string(wins); //generate message at the end of the turn store it in an array
    }
    return 0;
}

void creatBoard(int board[7][6], unsigned long long int pos, int turn) {
    int *moves = new int[turn + 1];

    bool bot = true;

    moves[0] = 4;

    int P;
    unsigned long long int nextPos;
    unsigned long long int currPos = pos;

    for (int i = turn; i > 0; i--) { //determine the series of moves
        P = currPos / 7;
        currPos % 7 != 0 ? nextPos = P + 1 : nextPos = P;

        moves[i] = (currPos - (nextPos * 7 - 6)) + 1;

        currPos = nextPos;
    }

    for (int i = 0; i <= turn; i++) { //make all the moves on the board
        makeMove(moves[i], bot, board);
        bot = !bot;
    }
}