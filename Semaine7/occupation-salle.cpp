#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

vector<string> jours = {"lundi", "mardi", "mercredi", "jeudi", "vendredi"};

typedef vector<vector<bool>>  TableauOccupation;  // tableau 2D de booleens

void afficheOccupation(TableauOccupation s) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction afficheOccupation non implanté ligne 12");
}

double tauxOccupation(TableauOccupation s) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction tauxOccupation non implanté ligne 17");
}

int main() {
    vector<vector<bool>> occupationSalle;
    occupationSalle = vector<vector<bool>>(5);

    for (int i = 0; i < occupationSalle.size(); i++) {
        occupationSalle[i] = vector<bool> (11);
    }

    occupationSalle[1][1] = true;
    afficheOccupation(occupationSalle);
    cout << "taux occupation = " << tauxOccupation(occupationSalle) << "%" <<
         endl;

    return 0;
}
