#include "Player.h"

Player::Player(Board& board, Window& win) : b(board), window(win) {
    this -> wins = 0;
    this -> gamesPlayed = 0;

};

void Player::firstMove() {

    int corners[4][2] = {{1, 1}, {1, b.width}, {b.height, 1}, {b.height, b.width}};
    int rIdx = rand() % 4; //generates a random number between 0 and 3
    b.clickCell(corners[rIdx][0], corners[rIdx][1]);
}


void Player::cspSolve() {

    firstMove();

    if (b.status == -1) {
        b.reset();
    }

}