#ifndef MINESWEEPER_BUTTON_H
#define MINESWEEPER_BUTTON_H
#include <SFML/Graphics.hpp>

class Button {
    public:
        sf::Font arial;
        sf::Text label;
        sf::RectangleShape button;
        sf::RenderWindow& window;
        bool pressed;
        sf::Color bgrnd;

        Button(sf::RenderWindow& win, sf::Vector2f pos, std::string text);
        void display();
        void press();
        bool mouseOn(int x, int y);
        bool getState();

};


#endif //MINESWEEPER_BUTTON_H
