#include <stdexcept>
#include <iostream>
using namespace std;

int max(int a, int b) {
    if ( a > b ) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int x = 0;
    for ( int i = 0; i < 5; i++ )
        x = x * i;
    x = max(x, 40);
    float resultat;
    for ( int i = 0; i < 50; i++ )
        resultat = resultat + 1/(x-i);
    cout << resultat << endl;
    return 0;
}
