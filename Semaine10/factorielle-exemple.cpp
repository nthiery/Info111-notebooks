#include <stdexcept>
/** @file
    Un exemple de programme utilisant la bibliothèque factorielle
 **/

#include <iostream>
#include "factorielle.h"
using namespace std;

int main() {
    int n;
    cout << "Entrez un entier n" << endl;
    cin >> n;
    cout << n << "! = " << factorielle(n) << endl;
    return 0;
}
