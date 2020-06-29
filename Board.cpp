#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Board::Board(int level, RenderWindow& win) : window(win){
    this -> level = level;
    this -> numFlagged = 0;
    switch (level) {
        case 1:
            width = 8; height = 8;
            numMines = 10;
            iPos = 280; jPos = 476;
            break;
        case 2:
            width = 16; height = 16;
            numMines = 40;
            iPos = 160; jPos = 352;
            break;
        default:
            width = 30; height = 16;
            numMines = 99;
            iPos = 160; jPos = 128;
            break;
    }
    createBoard();
}

void Board::setLevel(int level) { this -> level = level; }

void Board::clickCell(int x, int y) {
    disPane[x][y] = pane[x][y];
    visited[x][y] = 1;
    
    if (pane[x][y] == 0) {
        if (!visited[x + 1][y]) clickCell(x + 1, y);
        if (!visited[x - 1][y]) clickCell(x - 1, y);
        if (!visited[x + 1][y + 1]) clickCell(x + 1, y + 1);
        if (!visited[x - 1][y + 1]) clickCell(x - 1, y + 1);
        if (!visited[x + 1][y - 1]) clickCell(x + 1, y - 1);
        if (!visited[x - 1][y - 1]) clickCell(x - 1, y - 1);
        if (!visited[x][y + 1]) clickCell(x, y + 1);
        if (!visited[x][y - 1]) clickCell(x, y - 1);
    }
}

void Board::flagCell(int x, int y) {
    if (disPane[x][y] == 11) {
        disPane[x][y] = 10;
        numFlagged--;
    } else {
        disPane[x][y] = 11;
        numFlagged++;
    }
}

void Board::createBoard() {

    for (int i = 0; i <= height + 1; i++) {
        for (int j = 0; j <= width + 1; j++) {
            disPane[i][j] = 10;
            pane[i][j] = 0;
            visited[i][j] = 0;
            if (i == 0 || j == 0 || i == height + 1 || j == width + 1) {
                pane[i][j] = -1;
                visited[i][j] = -1;
            }
        }
    }

    int minesPlaced = 0;
    srand(time(0));

    while (minesPlaced < numMines) {

        int i = (rand() % height) + 1;
        int j = (rand() % width) + 1;

        if (pane[i][j] != 9) {
            pane[i][j] = 9;
            minesPlaced++;
        }
    }

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            int n = 0;
            if (pane[i][j] != 9) {
                if (pane[i + 1][j] == 9) n++;
                if (pane[i][j + 1] == 9) n++;
                if (pane[i - 1][j] == 9) n++;
                if (pane[i][j - 1] == 9) n++;
                if (pane[i + 1][j + 1] == 9) n++;
                if (pane[i - 1][j - 1] == 9) n++;
                if (pane[i - 1][j + 1] == 9) n++;
                if (pane[i + 1][j - 1] == 9) n++;
                pane[i][j] = n;
            }
        }
    }

}

void Board::displayBoard(){

    Texture t; t.loadFromFile("images/tiles.jpg");
    Sprite game(t);

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            game.setTextureRect(IntRect(32*disPane[i][j], 0, 32, 32));

            game.setPosition(jPos + (j*32), iPos + (i*32));
            
            window.draw(game);
        }
    }

}