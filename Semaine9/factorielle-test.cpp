#include <stdexcept>
/** @file **/
#include <iostream>
#include "factorielle.h"
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " \
         << __FILE__ << " line " << __LINE__ << ": " #test << endl

/** Les tests de la fonction factorielle **/
void factorielleTest() {
    ASSERT( factorielle(0) == 1  );
    ASSERT( factorielle(1) == 1  );
    ASSERT( factorielle(2) == 2  );
    ASSERT( factorielle(3) == 6  );
    ASSERT( factorielle(4) == 24 );
}

/** Cette fonction main ne sert qu'à lancer les tests **/
int main() {
    factorielleTest();
    return 0;
}
