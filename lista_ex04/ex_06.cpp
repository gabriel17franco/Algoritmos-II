// – Escreva um programa que apresente os primeiros 20 termos da sequência de Fibonacci: “A
// geração n de Fibonacci retorna 1 quando for até a 2ª geração. Se não, retorna a soma das duas
// últimas gerações anteriores”. Utilize uma função recursiva para resolver este problema.


#include <iostream>

using namespace std;

int fibonacci(int n) {
  // Casos base
  if (n == 0) {
    return 0;
  } else if (n == 1 || n == 2) {
    return 1;
  }
  // Caso recursivo
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  for (int i = 0; i < 20; i++) {
    cout << fibonacci(i) << " ";
  }
  cout << endl;
  return 0;
}
