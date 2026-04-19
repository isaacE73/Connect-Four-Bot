#include <fstream>
#include <iostream>
#include <cmath>
#include "board.h"
using namespace std;

void creatBoard(int board[7][6], unsigned long long int pos, int turn);
void save(int turn, unsigned long long int pos);

/*
Arguments:
    1. turns to be searched
    2. starting turn
    3. what incrament will winConditions array be dynamically expanded
    4. max num of index will winPositions array be allowed to have (each index is 8 bytes, recomended is 250e6 making it about 2GB large at its largest) 
*/
int main(int argc, char* arg[]) {
    int turns = stoi(arg[1]); //how many turns will be looked at
    int startingTurn = stoi(arg[2]); //what turn to start at
    unsigned long long int positions; //how many turns will be checked
    unsigned long long int *winPositons = nullptr; //will point to a dynamicaly allocated array that will store all the win positions
    int board[7][6];//the game board

    for (int turn = 0; turn < turns; turn++) { //incument through the number of turns

        positions = pow(7, (startingTurn + turn)); //how many positions will be looked through
        
        int size = stoi(arg[3]);
        winPositons = new unsigned long long int[stoi(arg[3])]; //allocate 1000 positions for win positions

        int numWins = 0;

        for (unsigned long long int curPos = 0; curPos < positions; curPos++) { //incrament through EVERY turn and check for wins

            initGamePos(board);
            creatBoard(board, curPos, startingTurn + turn);

            if (checkWin(board)) {
                if (numWins > stoi(arg[4])) {
                    save((startingTurn + turn), winPositons);
                    numWins = 0;
                }
                else if (numWins > stoi(arg[3])) {
                    unsigned long long int *temp = new unsigned long long int[size];

                    *temp = *winPositons;

                    delete[] winPositons;

                    size += stoi(arg[3]);

                    winPositons = new unsigned long long int[size];

                    for (int i = 0; i < (size - stoi(arg[3])); i++) {
                        winPositons[i] = temp[i];
                    }

                    delete[] temp;
                }

                winPositons[numWins] = curPos;
                numWins++;
            }
            
        }
    }
}

void save(int turn, unsigned long long int *winPositions) {

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