#include <stdexcept>
#include "MLV.h"
using namespace mlv;

int main() {
    // Crée et affiche une fenêtre de taille 640x480
    window_t fenetre = window_t( "Premier essai", "essai", 640, 480 );
    // Dessine un point rouge de coordonnées x=120 et y=50
    fenetre.draw_point( {120, 50}, color::red );
    // Actualise la fenêtre
    fenetre.update();
    // Attend 10 secondes
    fenetre.wait_seconds( 10 );
}
