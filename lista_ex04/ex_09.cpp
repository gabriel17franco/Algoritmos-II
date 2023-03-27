// Escreva um programa que gere randomicamente valores inteiros menores que 11 para
// preencher uma matriz 3 x 3 de tal forma que a matriz resultante forme um quadrado mágico.
// Quadrado mágico ocorre se a soma dos elementos de cada linha, a soma dos elementos de cada
// coluna e a soma dos elementos das diagonais principal e secundária são todas iguais.
// A matriz abaixo forma um quadrado mágico:
// 8 0 7
// 4 5 6
// 3 10 2
// O sistema deverá contar quantas matrizes foram geradas até gerar a matriz que resultou no
// quadrado mágico. Caso em 10 tentativas não foi gerado o quadrado mágico o sistema deverá
// permitir que o usuário informe valores para a matriz, utilize funções e passagem de parâmetro
// para resolver este exercício.


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void gerarMatriz(int M[][3]) {
  // Gera valores aleatórios para preencher a matriz
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      M[i][j] = rand() % 11;
    }
  }
}

void mostrarMatriz(int M[][3]) {
  // Mostra a matriz na tela
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
}

bool ehQuadradoMagico(int M[][3]) {
  // Verifica se a matriz é um quadrado mágico
  int somaDiagPrincipal = 0;
  int somaDiagSecundaria = 0;
  for (int i = 0; i < 3; i++) {
    int somaLinha = 0;
    int somaColuna = 0;
    for (int j = 0; j < 3; j++) {
      somaLinha += M[i][j];
      somaColuna += M[j][i];
      if (i == j) {
        somaDiagPrincipal += M[i][j];
      }
      if (i + j == 2) {
        somaDiagSecundaria += M[i][j];
      }
    }
    if (somaLinha != somaColuna || somaLinha != somaDiagPrincipal || somaLinha != somaDiagSecundaria) {
      return false;
    }
  }
  return true;
}

void preencherMatriz(int M[][3]) {
  // Permite ao usuário informar valores para a matriz
  cout << "Informe os valores da matriz: " << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> M[i][j];
    }
  }
}

int main() {
  srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
  int cont = 0;
  int M[3][3];
  bool encontrado = false;
  while (cont < 10 && !encontrado) {
    gerarMatriz(M);
    if (ehQuadradoMagico(M)) {
      cout << "Matriz gerada: " << endl;
      mostrarMatriz(M);
      encontrado = true;
    }
    cont++;
  }
  if (!encontrado) {
    cout << "Nenhuma matriz que forma um quadrado mágico foi gerada aleatoriamente." << endl;
    preencherMatriz(M);
  }
  return 0;
}