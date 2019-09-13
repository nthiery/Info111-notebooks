#include <stdexcept>
#include "MLV.h"
using namespace mlv;

int main(){
	// Créé et affiche la fenêtre
	window_t fenetre( "Base graphique", "essai", 640, 480 );

	// Dessine des cercles, ellipses, rectangles, lignes et points
	fenetre.draw_circle          ( {20, 20}, 10, color::purple );
	fenetre.draw_filled_circle   ( {50, 20}, 10, color::brown );
	fenetre.draw_ellipse         ( {100, 20}, 30, 10, color::cyan );
	fenetre.draw_filled_ellipse  ( {170, 20}, 30, 10, color::pink );
	fenetre.draw_rectangle       ( {10, 50}, 40, 20, color::blue );
	fenetre.draw_filled_rectangle( {70, 50}, 40, 20, color::green );
	fenetre.draw_line            ( {120, 50}, {160, 90}, color::white );
	fenetre.draw_point           ( {10, 110}, color::red );

	// Affiche du texte
	fenetre.draw_text( point_t(10, 120), "Voici un exemple de texte.", color::magenta );

	// Met à jour l'affichage.
	fenetre.update();

	// Attend 10 secondes avant la fin du programme.
	fenetre.wait_seconds( 10 );

	return 0;
}
