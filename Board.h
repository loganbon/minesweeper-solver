#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Board {
    public:
        int level; int numClicks;
        int width, height, numMines, numFlagged;
        int pane[18][32];
        int disPane[18][32];
        int visited[18][32];
        int iPos; int jPos;
        int status;

        RenderWindow& window;

        Board(int level, RenderWindow& window);

        void createBoard();
        void displayBoard();
        void setLevel(int level);
        void clickCell(int x, int y);
        void flagCell(int x, int y);
        void reset();
        bool mouseInBounds(int x, int y);
        bool clickSmiley(int x, int y);
};


#endif //MINESWEEPER_BOARD_H
