#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Board::Board(int level, sf::RenderWindow& win) : window(win){
    this -> numFlagged = 0;
    this -> status = 0;
    this -> numClicks = 0;
    setLevel(level);
    createBoard();
}

void Board::setLevel(int level) {
    this -> level = level;
    switch (level) {
        case 1:
            width = 8; height = 8;
            numMines = 10;
            iPos = 285; jPos = 480;
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
}

void Board::changeLevel(int level) {
    setLevel(level);
    reset();
}

int Board::getWidth() {
    return width;
}

int Board::getHeight() {
    return height;
}

int Board::getStatus() {
    return status;
}

void Board::clickCell(int x, int y) {
    if (status == -1 || status == 1 || visited[x][y] == 1 || disPane[x][y] == 11) return;
    if (pane[x][y] == 9) status = -1;
    disPane[x][y] = pane[x][y];
    visited[x][y] = 1;
    numClicks++;

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
    if (numClicks + numFlagged == (height * width)) { status = 1; }
}

void Board::flagCell(int x, int y) {
    if (status == -1 || status == 1) return;
    if (numFlagged == numMines && numClicks + numFlagged == (height * width)) return;
    if (disPane[x][y] == 11) {
        disPane[x][y] = 10;
        numFlagged--;
    } else if (disPane[x][y] == 10) {
        disPane[x][y] = 11;
        numFlagged++;
    }
}

void Board::reset() {
    createBoard();
    status = 0;
    numFlagged = 0;
    numClicks = 0;
}

bool Board::clickSmiley(int xC, int yC) {
    if ((xC == width / 2 || xC == (width / 2) + 1) && yC == 0) {
        return true;
    }
    return false;
}

bool Board::mouseInBounds(int x, int y) {
    if (x >= jPos && x <= (jPos + (32 * (width + 1))) && y >= iPos && y <= (iPos + (32 * (height + 1)))) {
        return true;
    }
    return false;
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

    // flag counter
    sf::Font arial;
    if (!arial.loadFromFile("fonts/arialbd.TTF")) { std::cout << "Failed to load font" << std::endl; }

    sf::Text flagCount;
    flagCount.setFont(arial);
    flagCount.setString(std::to_string(numMines - numFlagged));
    flagCount.setCharacterSize(42);
    flagCount.setFillColor(sf::Color::Black);
    flagCount.setPosition(jPos + 45, iPos - 45);
    window.draw(flagCount);

    // smiley face & reset button
    sf::Texture menuHead;
    if (status == 1) {
        if (!menuHead.loadFromFile("images/cool.png")) { std::cout << "Failed to load cool face" << std::endl; }
    } else if (status == 0) {
        if (!menuHead.loadFromFile("images/happy.png")) { std::cout << "Failed to load smiley face" << std::endl; }
    } else {
        if (!menuHead.loadFromFile("images/sad.png")) { std::cout << "Failed to load sad face" << std::endl; }
    }
    sf::Sprite head(menuHead);
    head.setScale(sf::Vector2f(2.f, 2.f));
    head.setOrigin(head.getLocalBounds().width/2, head.getLocalBounds().height/2);
    head.setPosition(window.getSize().x/2, iPos - 20);
    window.draw(head);

    // algo & attempts label
    sf::Text algo;
    algo.setString("Algorithm:");
    algo.setFont(arial);
    algo.setCharacterSize(32);
    algo.setFillColor(sf::Color::Black);
    algo.setPosition(35, 750);
    window.draw(algo);

    sf::Text atmpt;
    atmpt.setString("Attempts:");
    atmpt.setFont(arial);
    atmpt.setCharacterSize(32);
    atmpt.setFillColor(sf::Color::Black);
    atmpt.setPosition(45, 850);
    window.draw(atmpt);

    // cell textures
    sf::Texture t;
    if (!t.loadFromFile("images/tiles.jpg")) { std::cout << "Failed to load cell textures" << std::endl; }
    sf::Sprite game(t);

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            game.setTextureRect(sf::IntRect(32*disPane[i][j], 0, 32, 32));
            game.setPosition(jPos + (j*32), iPos + (i*32));
            window.draw(game);
        }
    }
}