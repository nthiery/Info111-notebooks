#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

#include "primitives.h"

int main()
{
    // Crée une fenêtre de taille 640x480
    RenderWindow window(VideoMode(640, 480), "Ma super fenêtre");
    window.clear(Color::White);
    window.display();

    // Attend que l'utilisateur clique sur le bouton gauche de la souris
    // et stocke les coordonnées du point où a cliqué l'utilisateur dans
    // la variable point.
    Point point = wait_mouse(window);

    // Affiche les coordonnées du point
    cout << point.x << " " << point.y << endl;

    // Attend que l'utilisateur tape sur une touche
    // et stocke la touche et d'autres informations dans
    // la variable evenement
    Event::KeyEvent evenement = wait_keyboard(window);

    // Affiche bonjour si la touche est o
    if ( evenement.code == Keyboard::Key::O )
        cout << "Bonjour" << endl;

    return 0;
}

