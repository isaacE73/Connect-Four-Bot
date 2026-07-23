#pragma once

class Game {
    private:
        unsigned int board[7][6];
    public:
        Game();
        bool makeMove(int move, bool which);
        void printBoard();
        bool checkWin();
        bool checkWin(bool onlyOne);
};