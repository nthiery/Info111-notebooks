#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

/** Trouve la dernière apparition d'un entier dans un tableau
 * @param v un tableau d'entiers
 * @param x un entier
 * @return la position de la dernière occurrence de x dans v,
 *         ou -1 s'il n'y a pas de telle occurrence
 **/
int dernierePosition( vector<int> v, int x ) {
    for ( int i = v.size()-1; i >= 0; i-- ){
        if ( v[i] == x ){
            return i;
        }
    }
    return -1;
}

int main() {
    cout << dernierePosition({3,1,2,5,76,3,2,3,4,1,2,3,4,2}, 9) << endl;
    cout << dernierePosition({3,1,2,5,76,3,2,3,4,1,2,3,4,2}, 1) << endl;
    return 0;
}
