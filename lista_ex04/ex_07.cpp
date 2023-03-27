//  Crie um programa que calcula o n-ésimo número harmônico que é calculado pela seguinte
// fórmula: H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n, sendo (n >=1). Escreva uma função
// recursiva que calcula H(n).

#include <iostream>

using namespace std;

double harmonico(int n) {
  // Caso base
  if (n == 1) {
    return 1.0;
  }
  // Caso recursivo
  return 1.0 / n + harmonico(n - 1);
}

int main() {
  int n;
  cout << "Digite um valor inteiro para n: ";
  cin >> n;
  if (n < 1) {
    cout << "Erro: n deve ser maior ou igual a 1" << endl;
    return 1;
  }
  cout << "H(" << n << ") = " << harmonico(n) << endl;
  return 0;
}