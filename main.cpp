#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include "Button.h"
using namespace sf;

int main() {

    srand(time(0));

    Color bgrnd(250, 243, 230);

    RenderWindow window;
    window.create(VideoMode(1280, 960), "Minesweeper", Style::Titlebar | Style::Close);

    Board b(2, window);
    Player p(b, window);

    Button begBtn(window, Vector2f(30, 20), "Beginner");
    Button intBtn(window, Vector2f(190, 20), "Intermediate");
    Button expBtn(window, Vector2f(430, 20), "Expert");

    while (window.isOpen()) {

        Vector2i mPos = Mouse::getPosition(window);

        // find cell locations
        int yC = (mPos.y - b.iPos) / 32;
        int xC = (mPos.x - b.jPos) / 32;

        Event e;
        while (window.pollEvent(e)) {

            if (e.type == Event::Closed) {
                window.close();

            } else if (e.type == Event::MouseButtonPressed) {

                if (b.mouseInBounds(mPos.x, mPos.y) && e.key.code == Mouse::Left) {
                    b.clickCell(yC, xC);

                } else if (b.mouseInBounds(mPos.x, mPos.y) && e.key.code == Mouse::Right) {
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
                }
            }
        }

        window.clear(bgrnd);

        // p.cspSolve();

        begBtn.display();
        intBtn.display();
        expBtn.display();

        b.displayBoard();
        window.display();
    }

    return 0;
}
