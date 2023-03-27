// Dado um vetor V[10] implemente um programa com as seguintes funções:
// - Função para gerar valores para o vetor sem número repetidos e menores que 100.
// - Função para mostrar os elementos do vetor na tela.
// - Função RECURSIVA que recebe o vetor por parâmetro, percorrendo todo o vetor e retornando
// o maior elemento existente no vetor, não é permitido o uso de laços de repetição para percorrer
// o vetor.
// OBS: As três funções devem ser acionadas na respectiva ordem no programa principal.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void gerarVetor(int V[], int tam) {
  // Gera valores aleatórios sem repetição e menores que 100
  bool valores[100] = {false};
  int count = 0;
  while (count < tam) {
    int num = rand() % 100;
    if (!valores[num]) {
      V[count] = num;
      valores[num] = true;
      count++;
    }
  }
}

void mostrarVetor(int V[], int tam) {
  // Mostra os elementos do vetor na tela
  for (int i = 0; i < tam; i++) {
    cout << V[i] << " ";
  }
  cout << endl;
}

int maiorElementoRecursivo(int V[], int tam, int maior) {
  // Caso base
  if (tam == 0) {
    return maior;
  }
  // Caso recursivo
  if (V[tam-1] > maior) {
    maior = V[tam-1];
  }
  return maiorElementoRecursivo(V, tam-1, maior);
}

int main() {
  srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
  const int TAM = 10;
  int V[TAM];
  gerarVetor(V, TAM);
  cout << "Vetor gerado: ";
  mostrarVetor(V, TAM);
  int maior = V[TAM-1];
  maior = maiorElementoRecursivo(V, TAM-1, maior);
  cout << "Maior elemento do vetor: " << maior << endl;
  return 0;
}
