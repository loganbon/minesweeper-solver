#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include <vector>

class Board {
public:
    int width, height, numMines;
    std::vector<int> pane;

    Board(int level);
};


#endif //MINESWEEPER_BOARD_H
