#ifndef MINESWEEPER_PLAYER_H
#define MINESWEEPER_PLAYER_H

#include "Board.h"

class Player {
private:
    int wins;
    int gamesPlayed;
    Board& b;
    sf::Window& window;
    std::vector<std::pair<int, int>> borderTiles;

    void refreshBorderTiles();

    const int neighbors[8][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void delayClick(int x, int y);
    bool isBorder(int x, int y);
    int countCoveredNeighbors(int x, int y);
    int countFlaggedNeighbors(int x, int y);
    void randomSolve();
    void solve();
    void firstMove();

public:
    Player(Board& b, sf::Window& win);
    void play();
};


#endif //MINESWEEPER_PLAYER_H
