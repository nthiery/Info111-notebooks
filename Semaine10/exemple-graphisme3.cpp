#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

#include "primitives.h"

int main(){
	// Créé et affiche la fenêtre
    RenderWindow window(VideoMode(640, 480), "Ma super fenêtre");
    window.clear(Color::White);

	// Dessine des cercles, ellipses, rectangles, lignes et points
    draw_circle(window, {20, 20}, 10, Color::Blue);
    draw_circle(window, {50, 20}, 10, Color::Red);
	draw_rectangle(window, {10, 50}, 40, 20, Color::Blue );
    draw_line(window, {120, 50}, {160, 90}, Color::Black);
    draw_point(window, {10, 110}, Color::Red);

	// Affiche du texte
    draw_text(window, {10, 120}, 14, "Voici un exemple de texte.", Color::Black);

	// Met à jour l'affichage.
    window.display();

	// Attend 10 secondes avant la fin du programme.
    sleep(seconds(10));

	return 0;
}
