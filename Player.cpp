#include "Player.h"
#include <vector>
#include <thread>
#include <iostream>

Player::Player(Board& board, sf::Window& win) : b(board), window(win) {
    this -> wins = 0;
    this -> gamesPlayed = 0;
};

void Player::setMethod(char method) { this -> method = method; }

char Player::getMethod() { return method; }

void Player::firstMove() {

    int corners[4][2] = {{1, 1}, {1, b.getWidth()}, {b.getHeight(), 1}, {b.getHeight(), b.getWidth()}};
    int rIdx = rand() % 4;
    b.clickCell(corners[rIdx][0], corners[rIdx][1]);
    
}

bool isBorder(int x, int y) { return true;
}


void Player::tankSolve() {

    firstMove();

    std::vector<std::vector<int>> borderTiles;

    for (int i = 1; i <= b.getHeight(); i++) {
        for (int j = 1; j <= b.getWidth(); j++) {

        }
    }


}
void Player::delayClick(int x, int y) {
    sf::Clock Clock;
    while  (Clock.getElapsedTime() < sf::microseconds(200000)) { }
    b.clickCell(x, y);
    b.displayBoard();
    window.display();
}

void Player::randomSolve() {

    sf::Clock Clock;

    while (b.getStatus() != -1 || b.getStatus() == 1) {
        while  (Clock.getElapsedTime() < sf::microseconds(200000)) { }
        int x = (rand() % b.getHeight()) + 1;
        int y = (rand() % b.getWidth()) + 1;
        b.clickCell(x, y);
        std::cout << x << ", " << y << std::endl;

        Clock.restart();
        b.displayBoard();
        window.display();
    }



}

void Player::play() {

    randomSolve();

    //if (b.status == -1 || b.status == 1) { b.reset(); }



}