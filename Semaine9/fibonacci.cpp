#include <stdexcept>
/** @file **/
#include <iostream>
#include <vector>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

/** Suite de Fibonacci
 *  @param n un entier strictement positif
 *  @return le n-ième terme de la suite de Fibonacci
 **/
int fibonacci(int n) {
    int u1 = 1;
    int u2 = 1;
    int tmp = 0;
    if ( n == 1 or n == 2 ) {
        return 1;
    } else {
        for ( int i = 3; i <= n; i++ ) {
            tmp = u2;
            u2 = u1 + u2;
            u1 = tmp;
        }
        return u2;
    }
}

/** Les tests de la fonction fibonacci **/
void fibonacciTest() {
    ASSERT( fibonacci(1) == 1 );
    ASSERT( fibonacci(2) == 1 );
    ASSERT( fibonacci(3) == 2 );
    ASSERT( fibonacci(4) == 3 );
    ASSERT( fibonacci(5) == 5 );
    ASSERT( fibonacci(6) == 8 );
}

int main(){
    fibonacciTest();

    int n;
    cout << "Entrez un entier : " << endl;
    cin >> n;
    cout << "Fibonacci(" << n << ") vaut "<< fibonacci(n) << endl;
    return 0;
}

