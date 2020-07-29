#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include <SFML/Graphics.hpp>

class Board {
private:
    int level; int numClicks;
    int width, height, numMines, numFlagged;
    int pane[18][32];
    int disPane[18][32];
    int visited[18][32];
    int status;

    sf::RenderWindow& window;

public:
    int iPos; int jPos;

    Board(int level, sf::RenderWindow& window);

    void createBoard();
    int getWidth();
    int getHeight();
    int getStatus();
    void displayBoard();
    void setLevel(int level);
    void clickCell(int x, int y);
    void flagCell(int x, int y);
    void reset();
    bool mouseInBounds(int x, int y);
    bool clickSmiley(int x, int y);
    void changeLevel(int level);
};


#endif //MINESWEEPER_BOARD_H
