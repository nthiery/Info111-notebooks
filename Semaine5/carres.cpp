#include <stdexcept>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v;                       // Declaration
    v = vector<int>(5);                  // Allocation
    for ( int i = 0; i < v.size(); i++ ) // Initialisation
        v[i] = i*i;
    cout << v[0] << v[1] << v[2] << v[3] << v[4] << endl;
    return 0;
}
