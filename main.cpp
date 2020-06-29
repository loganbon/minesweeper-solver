#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Board.h"
using namespace sf;


void drawMenu(RenderWindow &window) {

    Sprite btn1;
    btn1.setTextureRect(IntRect(100, 100, 100, 100));
    //btn1.setPosition(Vector2f(100, 100));
    btn1.setColor(Color(150, 50, 250));

    window.draw(btn1);
}

bool click(FloatRect button, Vector2f coord) {
    if (button.contains(coord)) {
        return true;
    }
    return false;
}

int main() {

    srand(time(0));

    RenderWindow window;
    window.create(VideoMode(1280, 960), "Minesweeper");

    Board b(3, window);

    while (window.isOpen()) {

        Vector2i mPos = Mouse::getPosition(window);
        int x = mPos.x/32;
        int y = mPos.y/32;

        Event e;
        while (window.pollEvent(e)) {

            switch(e.type) {

                case Event::Closed:
                    window.close();
                    break;

                case Event::MouseButtonPressed:
                        if (e.key.code == Mouse::Left) {
                            b.clickCell(mPos.x, mPos.y);

                        } else if (e.key.code == Mouse::Right) {

                        }

            }
        }

        window.clear(Color::White);

        b.displayBoard();

        window.display();
    }

    return 0;
}
