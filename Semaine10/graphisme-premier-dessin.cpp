#include <stdexcept>
#include "MLV.h"
#include <cmath>
using namespace mlv;
using namespace std;  // Pour les exceptions dans la version distribuée

int main() {
    int delai = 1;

    window_t fenetre = window_t( "Premier dessin", "Premier dessin", 900, 480 );
    fenetre.clear( color::lightgreen );

    // Dessine un point noir de coordonnées (418, 143)
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 15");
    fenetre.update();
    fenetre.wait_seconds( delai );

    // Dessine un segment marron entre les points (100,200) et (200,200)
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 21");
    fenetre.update();
    fenetre.wait_seconds( delai );

    // Dessine un segment marron entre les points (200,300) et (200,400)
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 27");
    fenetre.update();
    fenetre.wait_seconds( delai );

    // Dessine un rectangle horizontal vide de sommets diagonaux (200,200) et (400,300) et de contour marron
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 33");
    fenetre.update();
    fenetre.wait_seconds( delai );

    // Dessine un rectangle horizontal plein marron de sommets diagonaux (400,150) et (500,200)
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 39");
    fenetre.update();
    fenetre.wait_seconds( delai );

    // Dessine un segment marron entre les points (400,300) et (500,400)
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 45");
    fenetre.update();
    fenetre.wait_seconds( delai );

    // Dessine un cercle marron de centre (415,145) et de rayon 10
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 51");
    fenetre.update();
    fenetre.wait_seconds( delai );

    // Dessine un disque rouge de centre (700, 100) et de rayon 50
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 57");
    fenetre.update();
    fenetre.wait_seconds( delai );
    return 0;
}
