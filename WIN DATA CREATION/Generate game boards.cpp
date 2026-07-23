#include <iostream>
#include "Game.h"
using namespace std;

void creatBoard(Game *leGame, unsigned long long int pos, int turn) {
    int *moves = new int[turn + 1];

    bool which = true; //player or bot

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
        leGame->makeMove(moves[i], which);
        which = !which;
    }
}

int main(int argc, char* arg[]) {
    Game *leGame = new Game();

    creatBoard(leGame, stoi(arg[2]), stoi(arg[1]));

    leGame->printBoard();

    return 0;
}