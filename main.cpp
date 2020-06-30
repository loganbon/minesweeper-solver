#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Board.h"
using namespace sf;

bool contains(FloatRect button, Vector2f coord) {
    if (button.contains(coord)) {
        return true;
    }
    return false;
}

int main() {

    srand(time(0));

    RenderWindow window;
    window.create(VideoMode(1280, 960), "Minesweeper", Style::Titlebar | Style::Close);

    Board b(3, window);

    while (window.isOpen()) {

        Vector2i mPos = Mouse::getPosition(window);
        int yC = (mPos.y - b.iPos) / 32;
        int xC = (mPos.x - b.jPos) / 32;


        //std::cout << xC << ", " << yC << std::endl;


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
                }
            }
        }

        Color bgrnd(250, 243, 230);
        window.clear(bgrnd);

        b.displayBoard();

        window.display();
    }

    return 0;
}
