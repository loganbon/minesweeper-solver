#ifndef MINESWEEPER_PLAYER_H
#define MINESWEEPER_PLAYER_H

#include "Board.h"

class Player {
    public:
        int wins;
        int gamesPlayed;
        Board& b;
        Window& window;

        Player(Board& b, Window& win);
        void cspSolve();
        void firstMove();

};


#endif //MINESWEEPER_PLAYER_H
