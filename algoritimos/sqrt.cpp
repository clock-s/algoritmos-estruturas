#include <iostream>

using namespace std;

double sqr(double, double &);

int main() {
  double numero, deducao;
  double square;
  cin >> numero;

  deducao = numero / 2.0;

  cout << sqr(numero, deducao);

  return 0;
}

double sqr(double numero, double &chute) {
  if ((chute * chute) - numero < 0.0000000001)
    return chute;

  chute = (chute + (numero / chute)) * (1.0 / 2.0);

  sqr(numero, chute);

  return chute;
}
