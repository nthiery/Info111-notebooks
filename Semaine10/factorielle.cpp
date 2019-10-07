#include <stdexcept>
/** @file **/
#include "factorielle.h"

int factorielle(int n) {
    int resultat = 1;
    for ( int k = 1; k <= n; k++ )
        resultat = resultat * k;
    return resultat;
}
