//  – Faça um programa que receba dois valores inteiros e positivos, referentes a uma base e
// um expoente, após crie uma função recursiva para realizar o cálculo e retornar o valor
// resultante.

#include <iostream>

using namespace std;

int potencia(int base, int expoente) {
  if (expoente == 0) {
    return 1;
  }
  return base * potencia(base, expoente - 1);
}

int main() {
  int base, expoente;
  cout << "Digite a base: ";
  cin >> base;
  cout << "Digite o expoente: ";
  cin >> expoente;
  cout << "Resultado: " << potencia(base, expoente) << endl;
  return 0;
}