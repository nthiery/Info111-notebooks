#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

int mystere(vector<int> t) {
    int m = t[0];
    for ( int i = 1; i < t.size(); i++ ){
        if ( m < t[i] ) {
            m = t[i];
        }
    }
    return m;
}

int main() {
    vector<int> t = { 5, -1, 3, 7, -4, 8, 4 };
    int resultat = mystere(t);
    cout << resultat << endl;
    return 0;
}
