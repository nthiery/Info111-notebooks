#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;



/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

/** Construit un tableau 2D L x C dont les valeurs sont initialisées à v
 * @param L un entier: le nombre de lignes
 * @param C un entier: le nombre de colonnes
 * @param v un entier pour initialiser les valeurs
 * @return le tableau 2D d'entiers
 **/
vector<vector<int>> tableau2DInitialise(int L, int C, int v) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction tableau2DInitialise non implanté ligne 19");
}

int main() {
    ASSERT( tableau2DInitialise(0, 0, 1) == vector<vector<int>>({}) );
    ASSERT( tableau2DInitialise(3, 4, 1) ==
            vector<vector<int>>({ { 1,1,1,1 },
                                  { 1,1,1,1 },
                                  { 1,1,1,1 } }) );
}
