#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "primitives.h"
using namespace sf;
using namespace std;  // Pour les exceptions dans la version distribuée

int main()
{
    int delai = 1;
    RenderWindow window(VideoMode(900, 480), "Ma super fenêtre");
    window.clear(Color::Green);

    // Dessine un point noir de coordonnées (418, 143)
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 16");
    window.display();
    sleep(seconds(delai));

    // Dessine un segment blanc entre les points (100,200) et (200,200)
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 22");

    window.display();
    sleep(seconds(delai));

    // Dessine un segment rouge entre les points (200,300) et (200,400)
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 29");

    window.display();
    sleep(seconds(delai));

    // Dessine un rectangle horizontal vide de sommets diagonaux (200,200) et (400,300) et de contour rouge
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 36");

    window.display();
    sleep(seconds(delai));

    // Dessine un rectangle horizontal plein noir de sommets diagonaux (400,150) et (500,200)
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 43");

    window.display();
    sleep(seconds(delai));

    // Dessine un segment rouge entre les points (400,300) et (500,400)
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 50");

    window.display();
    sleep(seconds(delai));

    // Dessine un cercle noir de centre (415,145) et de rayon 10
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 57");

    window.display();
    sleep(seconds(delai));

    // Dessine un disque jaune de centre (700, 100) et de rayon 50
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 64");

    window.display();
    sleep(seconds(10*delai));
    return 0;
}
