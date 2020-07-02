#ifndef MINESWEEPER_BUTTON_H
#define MINESWEEPER_BUTTON_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Button {
    public:
        Font arial;
        Text label;
        RectangleShape button;
        RenderWindow& window;
        bool pressed;
        Color bgrnd;

        Button(RenderWindow& win, Vector2f pos, std::string text);
        void display();
        void press();
        bool mouseOn(int x, int y);
        bool getState();

};


#endif //MINESWEEPER_BUTTON_H
