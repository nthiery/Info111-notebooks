#include <stdexcept>
#include <vector>
#include <iostream>
#include <fstream>
#include "MLV.h"
using namespace std;
using namespace mlv;

typedef vector<vector<vector<int>>> Image;


/** Affiche image
  * @param chemin: une chaîne de caractères contenant le chemin
    du fichier .ppm que l'on souhaite afficher
  * @return image: un tableau 3D contenant en case i,j les
  * couleurs RGB du pixel {i,j} de l'image
 **/
Image read_image(string chemin) {
    ...
}

/** Affiche image
  * @param image: un tableau 3D contenant en case i,j les
  * couleurs RGB du pixel {i,j} d'une image
  * @return une fenêtre de MLV affichant l'image
 **/
void affiche_image(Image image) {
    ...
}

int main () {
    affiche_image(read_image("blackbuck.ppm"));
    exit (0);
}
