#include <stdexcept>
#ifndef PRIMITIVES__H
#define PRIMITIVES__H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

/** Présentation
 *  ============
 *
 *  primitives.cpp/h est une petite bibliothèque facilitant l'utilisation de la
 *  SFML pour les débutants. Nous vous invitons à lire attentivement sa
 *  documentation puis son implémentation, de manière à la comprendre et pouvoir
 *  par la suite s'en passer.
 *
 *  La documentation de la SFML est à tout moment accessible :
 *  - en Français : https://www.sfml-dev.org/learn-fr.php
 *  - en Anglais : https://www.sfml-dev.org/learn.php
 */


/** Notes sur la compilation
 *  ========================
 *
 *  Tout fichier utilisant cette bibliothèque doit être compilé de la manière
 *  suivante :
 *  info-111 g++ autre_fichier.cpp primitives.cpp -lsfml-system -lsfml-window -lsfml-graphics -o prog
 */


/**
 * Type Point, représentant les coordonnées d'un point
 * Peut être initialisé comme un tableau. Chaque coordonnée peut être accédée
 * avec .x et .y.
 * Exemple :
 * Point p = {42, 400};
 * int x = p.x; int y = p.y;
 *
 * Note : la coordonnée {0, 0} désigne le coin *supérieur* gauche de l'image
 */
using Point = Vector2f;

/** Notes sur les couleurs :
 *  ======================
 *
 * Il existe quelques couleurs définies par défaut :
 * Color::White, Color::Black, Color::Red, Color::Green, Color::Blue,
 * Color::Yellow, Color::Magenta, Color::Cyan
 *
 * Vous pouvez définir votre propre couleur en connaissant la quantité de rouge,
 * de vert et de bleu qu'elle contient. Par exemple :
 * Color purple(83, 0, 169);
 */

/** Affiche un point de couleur à une coordonnée donnée
 * @param w une fenêtre ouverte dans laquelle dessiner
 * @param pos les coordonnées du point
 * @param color la couleur du point
 */
void draw_point           (RenderWindow& w, Point pos, Color color);

/** Affiche une ligne de couleur entre deux positions données
 * @param w une fenêtre ouverte dans laquelle dessiner
 * @param pos1 les coordonnées du premier point de la ligne
 * @param pos1 les coordonnées du dernier point de la ligne
 * @param color la couleur de la ligne
 */
void draw_line            (RenderWindow& w, Point pos1, Point pos2, Color color);

/** Affiche un rectangle coloré vide
 * @param w une fenêtre ouverte dans laquelle dessiner
 * @param pos la position du coin supérieur gauche du rectangle
 * @param width la largeur du rectangle
 * @param height la hauteur du rectangle
 * @param color la couleur du trait
 */
void draw_rectangle       (RenderWindow& w, Point pos, int width, int height, Color color);

/** Affiche un rectangle coloré plein
 * @param w une fenêtre ouverte dans laquelle dessiner
 * @param pos la position du coin supérieur gauche du rectangle
 * @param width la largeur du rectangle
 * @param height la hauteur du rectangle
 * @param color la couleur du trait et du remplissage
 */
void draw_filled_rectangle(RenderWindow& w, Point pos, int width, int height, Color color);

/** Affiche un cercle coloré vide
 * @param w une fenêtre ouverte dans laquelle dessiner
 * @param center la position du centre du cercle
 * @param r le rayon du cercle
 * @param color la couleur du trait
 */
void draw_circle          (RenderWindow& w, Point center, int r, Color color);

/** Affiche un cercle coloré plein 
 * @param w une fenêtre ouverte dans laquelle dessiner
 * @param center la position du centre du cercle
 * @param r le rayon du cercle
 * @param color la couleur du trait et du remplissage
 */
void draw_filled_circle   (RenderWindow& w, Point center, int r, Color color);

/** Affiche du texte coloré à une position donnée
 * @param w une fenêtre ouverte dans laquelle dessiner
 * @param pos la position du texte
 * @param size la hauteur (en pixels) du texte
 * @param str la chaîne de caractères à afficher
 * @param color la couleur du texte
 */
void draw_text            (RenderWindow& w, Point pos, int size, string str, Color color);

/** Attend que l'utilisateur appuie sur le clic gauche de la souris
 * @param w la fenêtre dans laquelle l'utilisateur doit cliquer
 * @return la position dans la fenêtre où l'utilisateur a cliqué
 */
Point wait_mouse(RenderWindow& w);

/** Attend que l'utilisateur appuie sur une touche du clavier
 * @param w la fenêtre concernée
 * @return la touche sur laquelle l'utilisateur a appuyé
 * La liste des codes de touches est accessibles ici:
 * https://huit.re/sfml_key_codes
 */
Event::KeyEvent wait_keyboard(RenderWindow& w);

#endif
