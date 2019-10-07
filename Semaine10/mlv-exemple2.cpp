#include <stdexcept>
#include "MLV.h"
using namespace mlv;
using namespace std;

int main() {
    // Crée et affiche une fenêtre de taille 640x480
    window_t fenetre = window_t( "Premier essai", "essai", 640, 480 );

    // Attend que l'utilisateur clique sur le bouton gauche de la souris
    // et stocke les coordonnées du point où a cliqué l'utilisateur dans
    // la variable point.
    point_t point = fenetre.wait_mouse();

    // Affiche les coordonnées du point
    cout << point.x << " " << point.y << endl;

    // Attend que l'utilisateur tape sur une touche
    // et stocke la touche et d'autres informations dans
    // la variable evenement
    event::keyboard_t evenement = fenetre.wait_keyboard();

    // Affiche bonjour si la touche est o
    if ( evenement.key == keyboard::o )
        cout << "Bonjour" << endl;
}
