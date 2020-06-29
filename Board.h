#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Board {
    public:
        int level;
        int width, height, numMines;
        int pane[18][32];
        int disPane[18][32];
        int iPos; int jPos;

        RenderWindow& window;

        Board(int level, RenderWindow& window);
        void createBoard();
        void displayBoard();
        void setLevel(int level);
        void clickCell(int x, int y);
};


#endif //MINESWEEPER_BOARD_H
