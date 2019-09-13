#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;



/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<vector<int>> tabVide (0);
vector<vector<int>> tabCarre         = { { 1,  2, 3 },
                                         { 4, 11, 6 },
                                         { 9, 12, 7 } };
vector<vector<int>> tabRectangulaire = { { 1,  2, 3 },
                                         { 9, 12, 7 } };
vector<vector<int>> tabBizarre       = { { 1,  2, 3 },
                                         { 4,  5 },
                                         { 6,  7, 8, 10 } };

/** renvoie le nombre de lignes d'un tableau 2D d'entiers
 * @param t le tableau 2D d'entiers
 * @return le nombre de lignes du tableau t
 **/
int nombreDeLignes(vector<vector<int>> t) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction nombreDeLignes non implanté ligne 27");
}

void nombreDeLignesTest() {
    ASSERT( nombreDeLignes(tabVide) == 0 );
    ASSERT( nombreDeLignes(tabCarre) == 3 );
    ASSERT( nombreDeLignes(tabRectangulaire) == 2 );
    ASSERT( nombreDeLignes(tabBizarre) == 3 );
}

/** renvoie le nombre de colonnes d'un tableau 2D d'entiers
 * @param t le tableau 2D d'entiers
 * @return le nombre de colonnes du tableau t
 **/
int nombreDeColonnes(vector<vector<int>> t) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction nombreDeColonnes non implanté ligne 43");
}

void nombreDeColonnesTest() {
    ASSERT( nombreDeColonnes(tabVide) == 0 );
    ASSERT( nombreDeColonnes(tabCarre) == 3 );
    ASSERT( nombreDeColonnes(tabRectangulaire) == 3 );
    ASSERT( nombreDeColonnes(tabBizarre) == 3 );
}

/** affiche tous les elements de la ligne l de t.
 * @param t le tableau 2D d'entiers
 * @param l un entier
 **/
void afficheLigne(vector<vector<int>> t, int l) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction afficheLigne non implanté ligne 59");
}

/** affiche tous les elements de la colonne c de t.
 * @param t le tableau 2D d'entiers
 * @param c un entier
 **/
void afficheColonne(vector<vector<int>> t, int c) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction afficheColonne non implanté ligne 68");
}

/** affiche tous les éléments de la première diagonale de t (supposé carré).
 * @param t le tableau 2D d'entiers
 **/
void afficheDiagonale(vector<vector<int>> t) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction afficheDiagonale non implanté ligne 76");
}

/** affiche tous les elements de t.
 * @param t le tableau 2D d'entiers
 **/
void affiche(vector<vector<int>> t) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction affiche non implanté ligne 84");
}

/** Test d'appartenance
 * @param t un tableau d'entiers à deux dimensions
 * @param x un entier
 * @return un booleen: true si x apparaît dans t, false sinon
 **/
bool appartient(vector<vector<int>> t, int x) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction appartient non implanté ligne 94");
}

void appartientTest() {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction appartientTest non implanté ligne 99");
}

int main() {
    cout << "Lancement tests de nombreDeLignes" << endl;
    nombreDeLignesTest();
    cout << "Lancement tests de nombreDeColonnes" << endl;
    nombreDeColonnesTest();
    cout << "Appel de afficheLigne:" << endl;
    afficheLigne(tabCarre, 1);
    cout << "Appel de afficheColonne:" << endl;
    afficheColonne(tabCarre, 2);
    cout << "Appel de afficheDiagonale:" << endl;
    afficheDiagonale(tabCarre);
    cout << "Appel de affiche:" << endl;
    affiche(tabCarre);

    cout << "Lancement tests de appartient" << endl;
    nombreDeColonnesTest();
    appartientTest();
}
