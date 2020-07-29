#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"

Button::Button(sf::RenderWindow& win, sf::Vector2f pos, std::string text) : window(win) {

    this -> pressed = false;
    this -> bgrnd = sf::Color(250, 243, 230);

    if (!arial.loadFromFile("fonts/arialbd.TTF")) { std::cout << "Failed to load font" << std::endl; }

    label.setString(text);
    label.setFont(arial);
    label.setCharacterSize(32);
    label.setFillColor(sf::Color::Black);

    button.setPosition(pos);
    int width = label.getLocalBounds().width + 10;
    button.setSize(sf::Vector2f(width,50));
    button.setFillColor(bgrnd);

    label.setPosition((pos.x + width / 2) - (label.getLocalBounds().width / 2), pos.y + 5);


}

bool Button::mouseOn(int x, int y) {
    int btnXMin = button.getPosition().x;
    int btnYMin = button.getPosition().y;

    int btnXMax = btnXMin + button.getLocalBounds().width;
    int btnYMax = btnYMin + button.getLocalBounds().height;

    if (x < btnXMax && x > btnXMin && y < btnYMax && y > btnYMin) {
        return true;
    }
    return false;

}

void Button::press() {
    if (pressed) {
        button.setFillColor(bgrnd);
        label.setFillColor(sf::Color::Black);
        pressed = false;
    } else {
        button.setFillColor(sf::Color::Black);
        label.setFillColor(bgrnd);
        pressed = true;
    }
}

bool Button::getState() {
    return pressed;
}

void Button::display() {

    window.draw(button);
    window.draw(label);
}
