#include "Player.h"
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

Player::Player(Board& board, sf::Window& win) : b(board), window(win) {
    this -> wins = 0;
    this -> gamesPlayed = 0;
    borderTiles.reserve(b.getNumMines() * 8);
};

void Player::delayClick(int x, int y) {
    sf::Clock Clock;
    while (Clock.getElapsedTime() < sf::microseconds(20000)) { }
    b.clickCell(x, y);
    b.displayBoard();
    window.display();
    std::cout << x << ", " << y << std::endl;
}

void Player::firstMove() {
    int corners[4][2] = {{1, 1}, {1, b.getWidth()}, {b.getHeight(), 1}, {b.getHeight(), b.getWidth()}};
    int rIdx = rand() % 4;
    b.clickCell(corners[rIdx][0], corners[rIdx][1]);
}

void Player::refreshBorderTiles() {
    borderTiles.clear();

    for (int i = 1; i < b.getHeight() + 1; i++) {
        for (int j = 1; j < b.getWidth() + 1; j++) {
            if (isBorder(i, j))
                borderTiles.emplace_back(std::make_pair(i, j));
        }
    }
}

bool Player::isBorder(int x, int y) {
    if (b.getCell(x, y) != 10)
        return false;

    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            if (x + i > 0 && x + i < b.getHeight() + 1 && y + j > 0 && y + j < b.getWidth() + 1) {
                int neigh = b.getCell(x + i, y + j);
                if (neigh != 10) {
                    return true;
                }
            }
    return false;
}

int Player::countCoveredNeighbors(int x, int y) {
    int count = 0;

    for (auto& neigh : neighbors) {
        if (x + neigh[0] > 0 && x + neigh[0] < b.getHeight() + 1 && y + neigh[1] > 0 && y + neigh[1] < b.getWidth() + 1) {
            if (b.getCell(x + neigh[0], y + neigh[1]) == 10 || b.getCell(x + neigh[0], y + neigh[1]) == 11)
                count++;
        }
    }
    return count;
}

int Player::countFlaggedNeighbors(int x, int y) {
    int count = 0;

    for (auto& neigh : neighbors) {
        if (x + neigh[0] > 0 && x + neigh[0] < b.getHeight() + 1 && y + neigh[1] > 0 && y + neigh[1] < b.getWidth() + 1) {
            if (b.getCell(x + neigh[0], y + neigh[1]) == 11)
                count++;
        }
    }
    return count;
}

std::vector<std::string> permute(int size) {

    std::vector<std::string> vec;
    if (size < 1) return vec;

    vec.emplace_back("1");
    vec.emplace_back("0");

    while (size > vec[0].size()) {
        for (int i = 0; i < vec.size(); i += 2) {
            vec.insert(vec.begin() + i, vec[i]);
        }

        for (int i = 0; i < vec.size(); i++) {
            if (i % 2 == 0)
                vec[i].append("1");
            else
                vec[i].append("0");
        }
    }
    return vec;
}




void Player::solve() {
    // STEPS
    // 1. make first move based on probability
    // 2a. find all squares with same covered neighbors as cell count
    // 2b. click all covered neighbor squares of cells that have equal flag count to cell count
    // 3. enumerate all possible mine positions click cells with 0 or lowest possible to max probability
    // 4. end game tricks

    // 1)
    firstMove();

    bool stepSuccess;

    int k = 0;
    while (b.getStatus() == 0) {

        // get all border tiles
        refreshBorderTiles();

        // 2a)
        for (int i = 1; i < b.getHeight() + 1; i++) {
            for (int j = 1; j < b.getWidth() + 1; j++) {
                if (b.getCell(i, j) > 0 && b.getCell(i, j) < 10) {
                    if (b.getCell(i, j) == countCoveredNeighbors(i, j)) {
                        for (auto& neigh : neighbors)
                            if (!b.isFlagged(i + neigh[0], j + neigh[1]))
                                if (i + neigh[0] > 0 && i + neigh[0] < b.getHeight() + 1 && j + neigh[1] > 0 &&
                                    j + neigh[1] < b.getWidth() + 1) {
                                    b.flagCell(i + neigh[0], j + neigh[1]);
                                    stepSuccess = true;
                                }
                    }
                }
            }
        }

        // 2b)
        for (int i = 1; i < b.getHeight() + 1; i++) {
            for (int j = 1; j < b.getWidth() + 1; j++) {
                if (b.getCell(i, j) == countFlaggedNeighbors(i, j)) {
                    for (auto& neigh : neighbors) {
                        if (b.getCell(i + neigh[0], j + neigh[1]) == 10) {
                            if (i + neigh[0] > 0 && i + neigh[0] < b.getHeight() + 1 && j + neigh[1] > 0 &&
                                j + neigh[1] < b.getWidth() + 1) {
                                delayClick(i + neigh[0], j + neigh[1]);
                                stepSuccess = true;
                            }
                        }
                    }
                }
            }
        }

        // return to step if step 2 worked
        // if (stepSuccess)
        //    continue;

        refreshBorderTiles();

        // 3)

        // create vector of permutations
        //std::vector<std::string> permutations = permute(borderTiles.size());

        // segment border tiles
        std::vector<std::vector<std::string>> segments;

        std::pair<int, int> start = borderTiles[0];


        //for (auto& str : permutations)
            //std::cout << str << std::endl;

        //std::cout << permutations.size() << std::endl;


        int enumTiles[borderTiles.size()];
        for (auto& tile : enumTiles)
            tile = 0;

        #if 0
            for (auto& borderTile : borderTiles)
                std::cout << borderTile.first << ", " << borderTile.second << std::endl;
        #endif


        //permutations.clear();
        borderTiles.clear();

        //b.displayBoard();
        //window.display();

        std::cout << "---------------------" << std::endl;
        std::cout << k << std::endl;

        if (k > 9) break;
        k++;
    }
}

void Player::randomSolve() {

    while (b.getStatus() != -1 || b.getStatus() == 1) {
        int x = (rand() % b.getHeight()) + 1;
        int y = (rand() % b.getWidth()) + 1;
        delayClick(x, y);
        std::cout << x << ", " << y << std::endl;

        //b.displayBoard();
        //window.display();
    }
}

void Player::play() {

    // random solver
    //randomSolve();
    solve();
    //std::cout << b.getCell(1, 1) << std::endl;

    //if (b.status == -1 || b.status == 1) { b.reset(); }

}

