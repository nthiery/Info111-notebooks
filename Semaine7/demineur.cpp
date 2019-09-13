#include <stdexcept>
/** @file **/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

typedef vector<vector<char>> GrilleDemineur ; // tableau 2D de caractères
const GrilleDemineur uneGrille = {
    { ' ', 'm', 'o', ' ', 'm', 'M' },
    { 'm', 'm', 'm', 'o', 'm', ' ' },
    { 'm', 'm', 'm', 'o', ' ', 'm' },
    { 'm', 'm', 'm', ' ', 'M', ' ' },
};
const GrilleDemineur uneGrilleGagnante = {
    { ' ', 'm', ' ', ' ', 'm', 'M' },
    { 'm', 'm', 'm', ' ', 'm', ' ' },
    { 'm', 'm', 'm', ' ', ' ', 'm' },
    { 'm', 'm', 'm', ' ', 'M', ' ' },
};

/** Compte le nombre de mines dans une grille
 * @param grille un tableau 2D de caractères (vector<vector<char> >)
 * @return le nombre de mines dans grille
 **/
int nombreMines(GrilleDemineur grille) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction nombreMines non implanté ligne 33");
}

void nombreMinesTest() {
    ASSERT( nombreMines(uneGrille) == 15);
    ASSERT( nombreMines(uneGrilleGagnante) == 15);
}


/** Renvoie un booléen aléatoire qui initialise le tirage aléatoire des mines **/
bool boolAleatoire() {
    string sproba;
    int iproba;
    cout << "Quelle est la probabilité qu'une case contienne une mine ?\n";
    cin >> sproba;
    iproba = atoi(sproba.c_str());
    srand(time(NULL));
    return rand() % 100 + 1 < iproba;
}

/** Construit une grille initiale
 * @param n un entier positif
 * @param m un entier positif
 * @return un tableau de caractères de n lignes et m colonnes rempli
 *  aléatoirement et ne contenant que des 'm' ou 'o'
 **/
vector<vector<char> > grilleInitiale(int n, int m) {
    // Déclaration
    GrilleDemineur result;
    // Allocation
    result = GrilleDemineur(n);
    // Allocation des sous-tableaux
    for (int i = 0; i < n; i++)
        result[i] = vector<char>(m);
    // Initialisation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (boolAleatoire())
                result[i][j] = 'm';
            else
                result[i][j] = 'o';
        }
    }
    return result;
}

/** Teste si une grille est gagnante
 * @param grille un tableau 2D de caractères (vector<vector<char> >)
 * @return un booléen vrai si grille est une grille gagnante, ie si
 *  toutes les cases qui ne sont pas des mines ont été démasquées
 **/
bool grilleEstGagnante(GrilleDemineur grille) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction grilleEstGagnante non implanté ligne 86");
}

void grilleEstGagnanteTest() {
    ASSERT( not grilleEstGagnante(uneGrille) );
    ASSERT(     grilleEstGagnante(uneGrilleGagnante) );
}

/** Renvoie le nombre de mines voisines à ième ligne, jème colonne
 * @param grille un tableau 2D de caractères (vector<vector<char> >)
 * @param i un entier décrivant une ligne de grille
 * @param j un entier décrivant une colonne de grille
 * @return un entier entre 0 et 8 comptant le nombre de mines
 *  adjacentes à grille[i][j]
 **/
int minesVoisines(GrilleDemineur grille, int i, int j) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction minesVoisines non implanté ligne 103");
}

void minesVoisinesTest() {
    ASSERT( minesVoisines(uneGrille, 0, 0) == 3);
    ASSERT( minesVoisines(uneGrille, 2, 1) == 8);
    ASSERT( minesVoisines(uneGrille, 2, 0) == 5);
    ASSERT( minesVoisines(uneGrille, 1, 5) == 4);
    ASSERT( minesVoisines(uneGrille, 3, 5) == 2);
}

/** Dessine une grille
 * @param grille un tableau 2D de caractères (vector<vector<char> >)
 * @return une chaîne de caractères (string) décrivant la grille de
 *  gauche à droite et de bas en haut, un retour à la ligne séparant
 *  chaque ligne de grille
 *
 * Indications:
 * - si s et t sont des chaînes de caractères, s+t est leur concaténation
 * - "\n" représente un saut de ligne
 **/
string dessinGrille(GrilleDemineur grille) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction dessinGrille non implanté ligne 126");
}

void dessinGrilleTest() {
    ASSERT( dessinGrille(uneGrille) == "3  3 M\n     4\n    3 \n   3M2\n");
}

int main() {
    nombreMinesTest();
    grilleEstGagnanteTest();
    minesVoisinesTest();
    dessinGrilleTest();
}
