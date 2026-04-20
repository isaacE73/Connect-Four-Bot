#include <iostream>
#include "board.h"
using namespace std;

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

int main(int argc, char* arg[]) {
    int game[7][6];

    initGamePos(game);

    creatBoard(game, stoi(arg[2]), stoi(arg[1]));

    generateBoard(game);

    return 0;
}