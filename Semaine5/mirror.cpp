#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

vector<int> mystere(vector<int> t) {
    int n = t.size();
    vector<int> r(n);
    for (int i=0; i<n; i++) {
        r[i] = t[n-1-i];
    }
    return r;
}

int main(){
    vector<int> t = {1,2,3,4,5,6,7,8,9};
    t = mystere(t);
    for ( int i = 0; i < t.size(); i++ ) {
        cout << t[i] << endl;
    }
    return 0;
}
