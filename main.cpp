#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

int main() {

    srand(time(0));

    RenderWindow app(VideoMode(500, 500), "Minesweeper");

    while (app.isOpen()) {

        Event e;

        while (app.pollEvent(e)) {

            if (e.type == Event::Closed)
                app.close();
        }

        app.display();
    }

    return 0;
}
