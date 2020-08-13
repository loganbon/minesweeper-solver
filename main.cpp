#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <iostream>
#include "Player.h"
#include "Button.h"

int main() {

    srand(time(0));

    sf::Color bgrnd(250, 243, 230);

    sf::RenderWindow window;
    window.create(sf::VideoMode(1280, 960), "Minesweeper", sf::Style::Titlebar | sf::Style::Close);

    Board b(1, window);
    Player p(b, window);

    Button begBtn(window, sf::Vector2f(30, 20), "Beginner");
    Button intBtn(window, sf::Vector2f(190, 20), "Intermediate");
    Button expBtn(window, sf::Vector2f(400, 20), "Expert");
    begBtn.press();

    Button atmptTen(window, sf::Vector2f(950, 20), "10");
    Button atmptTwentyFive(window, sf::Vector2f(1000, 20), "25");
    Button atmptFifty(window, sf::Vector2f(1050, 20), "50");
    atmptTen.press();

    Button gameOn(window, sf::Vector2f(615, 745), "Go");

    while (window.isOpen()) {

        sf::Vector2i mPos = sf::Mouse::getPosition(window);

        // find cell locations
        int yC = (mPos.y - b.iPos) / 32;
        int xC = (mPos.x - b.jPos) / 32;

        sf::Event e;
        while (window.pollEvent(e)) {

            if (e.type == sf::Event::Closed) {
                window.close();

            } else if (e.type == sf::Event::MouseButtonPressed) {

                if (!gameOn.getState()) {
                    if (b.mouseInBounds(mPos.x, mPos.y) && (int) e.key.code == (int) sf::Mouse::Left) {
                        b.clickCell(yC, xC);

                    } else if (b.mouseInBounds(mPos.x, mPos.y) && (int) e.key.code == (int) sf::Mouse::Right) {
                        b.flagCell(yC, xC);

                    } else if (b.clickSmiley(xC, yC)) {
                        b.reset();

                    } else if (begBtn.mouseOn(mPos.x, mPos.y)) {
                        if (intBtn.getState()) intBtn.press();
                        if (!begBtn.getState()) begBtn.press();
                        if (expBtn.getState()) expBtn.press();
                        b.changeLevel(1);

                    } else if (intBtn.mouseOn(mPos.x, mPos.y)) {
                        if (!intBtn.getState()) intBtn.press();
                        if (begBtn.getState()) begBtn.press();
                        if (expBtn.getState()) expBtn.press();
                        b.changeLevel(2);

                    } else if (expBtn.mouseOn(mPos.x, mPos.y)) {
                        if (intBtn.getState()) intBtn.press();
                        if (begBtn.getState()) begBtn.press();
                        if (!expBtn.getState()) expBtn.press();
                        b.changeLevel(3);

                    } else if (atmptTwentyFive.mouseOn(mPos.x, mPos.y)) {
                        if (atmptTen.getState()) atmptTen.press();
                        if (!atmptTwentyFive.getState()) atmptTwentyFive.press();
                        if (atmptFifty.getState()) atmptFifty.press();

                    } else if (atmptTen.mouseOn(mPos.x, mPos.y)) {
                        if (!atmptTen.getState()) atmptTen.press();
                        if (atmptTwentyFive.getState()) atmptTwentyFive.press();
                        if (atmptFifty.getState()) atmptFifty.press();

                    } else if (atmptFifty.mouseOn(mPos.x, mPos.y)) {
                        if (atmptTen.getState()) atmptTen.press();
                        if (atmptTwentyFive.getState()) atmptTwentyFive.press();
                        if (!atmptFifty.getState()) atmptFifty.press();

                    } else if (gameOn.mouseOn(mPos.x, mPos.y)) {
                        if (!gameOn.getState()) {
                            gameOn.press();
                            p.play();
                            gameOn.press();
                        }
                    }
                }
            }
        }

        window.clear(bgrnd);

        // flag counter
        sf::Font arial;
        if (!arial.loadFromFile("fonts/arialbd.TTF")) { std::cout << "Failed to load font" << std::endl; }

        sf::Text flagCount;
        flagCount.setFont(arial);
        flagCount.setString(std::to_string(b.getNumMines() - b.getNumFlagged()));
        flagCount.setCharacterSize(42);
        flagCount.setFillColor(sf::Color::Black);
        flagCount.setPosition(b.jPos + 45, b.iPos - 45);
        window.draw(flagCount);

        begBtn.display();
        intBtn.display();
        expBtn.display();

        atmptFifty.display();
        atmptTen.display();
        atmptTwentyFive.display();

        gameOn.display();

        b.displayBoard();
        window.display();
    }

    return 0;
}
