#include <stdexcept>
#include "primitives.h"
#include <assert.h>
#include <cmath>
#include <iostream>

void draw_point(RenderWindow& w, Point pos, Color color) {
    Vertex p[] = { Vertex(pos, color) };
    w.draw(p, 1, sf::Points);
}

void draw_line(RenderWindow& w, Point pos1, Point pos2, Color color) {
    Vertex p[] = { Vertex(pos1, color), Vertex(pos2, color) };
    w.draw(p, 2, sf::Lines);
}

void draw_circle(RenderWindow& w, Point center, int r, Color color) {
    CircleShape shape(r);
    shape.setPosition(center);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(color);
    shape.setFillColor(Color::Transparent);
    w.draw(shape);
}

void draw_filled_circle(RenderWindow& w, Point center, int r, Color color) {
    CircleShape shape(r);
    shape.setPosition(center);
    shape.setOutlineThickness(0.f);
    shape.setFillColor(color);
    w.draw(shape);
}

void draw_rectangle(RenderWindow& w, Point pos, int width, int height, Color color) {
    RectangleShape shape(Vector2f(width, height));
    shape.setPosition(pos); //Top-left position
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(color);
    shape.setFillColor(Color::Transparent);
    w.draw(shape);
}

void draw_filled_rectangle(RenderWindow& w, Point pos, int width, int height, Color color) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("code non implanté ligne 45");
}

Font minipax;
bool loadfont() {
    static bool loaded = false;
    /**
     * Using the Minipax font, by Raphaël Ronot
     * Under the SIL Open Font License
     * Retrieved on Velvetyne Type Foundry
     */
    if(!loaded) loaded = minipax.loadFromFile("minipax.ttf");
    if(!loaded)
        cerr << "ERREUR: Le fichier 'minipax.ttf' n'a pas été trouvé dans le dossier."
             << "Le programme ne pourra pas afficher de texte !" << endl;
    return loaded;
}

void draw_text(RenderWindow& w, Point pos, int size, string str, Color co) {
    if(loadfont()) {
        sf::Text text;
        text.setFont(minipax);
        text.setString(str);
        text.setCharacterSize(size);
        text.setFillColor(co);
        text.setPosition(pos.x, pos.y);
        w.draw(text);
    }
}

Point wait_mouse(RenderWindow& w) {
    Event e;
    do w.waitEvent(e);
    while(e.type != Event::MouseButtonPressed or
            e.mouseButton.button != Mouse::Button::Left);
    return Point(e.mouseButton.x, e.mouseButton.y);
}

Event::KeyEvent wait_keyboard(RenderWindow& w) {
    Event e;
    do w.waitEvent(e);
    while(e.type != Event::KeyPressed);
    return e.key;
}
