#include <stdexcept>
#include <iostream>
#include <vector>
#include <cstdlib>
#define ASSERT(C) if ( !(C) ) { std::cerr << "Test failed: "#C << std::endl; }

using namespace std;
typedef vector<int> tableau;

int aleaint(int a, int b) {
    return (rand() % (b - a + 1) + a);
}

// Mettez ici les différentes fonctions nécessaires au jeu de Yams :





/*
int pointsFigureBrelan(vector<int> des) {
  vector<int> compte = compteDes(des);

  int valeur = (chercheDansTab(3, compte) + 1)
                      + (chercheDansTab(4, compte) + 1)
                      + (chercheDansTab(5, compte) + 1);

  if (valeur > 0) return (valeur * 3) + 10;
  else return 0;
}

int pointsFigure(vector<int> des, string figure) {
  if(figure == "brelan") {
    return pointsFigureBrelan(des);
  } else if(figure == "full") {
    return pointsFigureFull(des);
  } else if(figure == "carre") {
    return pointsFigureCarre(des);
  } else if(figure == "yams") {
    return pointsFigureYams(des);
  }
  return 0;
}*/

int main() {
    cout << pointsFigureYams({1, 1, 1, 1, 1}) << endl;
    return 0;
}
