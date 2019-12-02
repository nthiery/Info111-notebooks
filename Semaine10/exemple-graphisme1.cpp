#include <stdexcept>
#include <SFML/Graphics.hpp>
using namespace sf;

#include "primitives.h"

int main()
{
    // Crée une fenêtre de taille 640x480
    RenderWindow window(VideoMode(640, 480), "Ma super fenêtre");

    // Remplit la fenêtre de blanc
    window.clear(Color::White);

    draw_point(window, {120, 5}, Color::Red);

    // Actualise la fenêtre
    window.display();

    // Attend 10 secondes
    sleep(seconds(10));

    return 0;
}

