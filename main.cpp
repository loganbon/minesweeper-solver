#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;


void drawMenu(RenderWindow& window) {

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
    window.create(VideoMode(1500, 1000), "Minesweeper");

    // Tile textures
    Texture t; t.loadFromFile("images/tiles.jpg");
    Sprite s(t);

    int w=32;
    int grid[12][12];
    int sgrid[12][12]; //for showing

    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        {
            sgrid[i][j]=10;
            if (rand()%5==0)  grid[i][j]=9;
            else grid[i][j]=0;
        }

    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        {
            int n=0;
            if (grid[i][j]==9) continue;
            if (grid[i+1][j]==9) n++;
            if (grid[i][j+1]==9) n++;
            if (grid[i-1][j]==9) n++;
            if (grid[i][j-1]==9) n++;
            if (grid[i+1][j+1]==9) n++;
            if (grid[i-1][j-1]==9) n++;
            if (grid[i-1][j+1]==9) n++;
            if (grid[i+1][j-1]==9) n++;
            grid[i][j]=n;
        }


    while (window.isOpen()) {

        Vector2i pos = Mouse::getPosition(window);
        int x = pos.x/w;
        int y = pos.y/w;

        Event e;
        while (window.pollEvent(e)) {

            switch(e.type) {

                case Event::Closed:
                    window.close();
                    break;

                case Event::MouseButtonPressed:
                        if (e.key.code == Mouse::Left) sgrid[x][y]=grid[x][y];
                        else if (e.key.code == Mouse::Right) sgrid[x][y]=11;

            }
        }

        window.clear(Color::White);


        // no
        for (int i=1;i<=10;i++)
            for (int j=1;j<=10;j++)
            {
                if (sgrid[x][y]==9) sgrid[i][j]=grid[i][j];
                s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
                s.setPosition(i*w, j*w);
                window.draw(s);
            }

        drawMenu(window);

        window.display();
    }

    return 0;
}
