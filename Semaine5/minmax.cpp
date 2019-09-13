#include <stdexcept>
#include <iostream>
using namespace std;

int max(int a, int b) {
    if (a < b) {
        return b;
    } else {
        return a;
    }
}

int main() {
    int a = 5;
    int b = 8;
    cout << "Le maximum de " << a << " et " << b << " est " << max(a,b) << endl;
}
