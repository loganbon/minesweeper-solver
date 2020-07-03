#ifndef MINESWEEPER_PLAYER_H
#define MINESWEEPER_PLAYER_H

#include "Board.h"

class Player {
    public:
        int wins;
        int gamesPlayed;
        char method;
        Board& b;
        Window& window;

        Player(Board& b, Window& win);
        void setMethod(char method);
        char getMethod();
        void delayClick(int x, int y);
        void randomSolve();
        void tankSolve();
        void firstMove();
        void play();

};


#endif //MINESWEEPER_PLAYER_H
