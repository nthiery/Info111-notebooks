#include <stdexcept>
/** @file **/
#include <iostream>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

/** Suite de Fibonacci
 *  @param n un entier strictement positif
 *  @return le n-ième terme de la suite de Fibonacci
 **/
int fibonacci(int n) {
    // À faire: Écrire le code ici!
}

void fibonacciTest() {
    ASSERT( fibonacci(1) == 1 );
    ASSERT( fibonacci(2) == 1 );
    ASSERT( fibonacci(3) == 2 );
    ASSERT( fibonacci(4) == 4 );
    ASSERT( fibonacci(5) == 5 );
    ASSERT( fibonacci(6) == 8 );
}

int main() {
    // lance les tests
    fibonacciTest();

    // Un exemple d'utilisation:
    cout << "fibonacci(5) = " << fibonacci(5) << endl;
}
