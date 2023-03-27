// Implemente um programa para manipular uma matriz de 5 x 5 de números inteiros,
// deverá ser possível realizar as seguintes ações:
// - Gerar valores para a matriz, não sendo permitido números duplicados.
// - Mostrar os elementos da matriz
// - Mostrar os elementos da diagonal principal da matriz
// - Mostrar os elementos da diagonal secundária da matriz
// - Encontrar o maior elemento da matriz e exibir sua posição (linha, coluna) onde se encontra
// OBS: utilize funções e passagem de parâmetro para resolver cada parte deste exercício.


#include <iostream>
#include <ctime>
#include <set>
using namespace std;

void gerar_matriz(int matriz[5][5]) {
    srand(time(nullptr));
    bool numeros_usados[200] = { false };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int novo_numero = rand() % 25 + 1;
            while (numeros_usados[novo_numero]) {
                novo_numero = rand() % 25 + 1;
            }
            numeros_usados[novo_numero] = true;
            matriz[i][j] = novo_numero;
        }
    }
}

void mostrar_matriz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void mostrar_diagonal_principal(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        cout << matriz[i][i] << " ";
    }
    cout << endl;
}

void mostrar_diagonal_secundaria(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        cout << matriz[i][5 - 1 - i] << " ";
    }
    cout << endl;
}

void encontrar_maior_elemento(int matriz[5][5]) {
    int maior = matriz[0][0];
    int linha_maior = 0;
    int coluna_maior = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                linha_maior = i;
                coluna_maior = j;
            }
        }
    }
    cout << "O maior elemento da matriz e: " << maior << endl;
    cout << "Ele se encontra na posicao [" << linha_maior << "][" << coluna_maior << "]" << endl;
}

int main() {
    int matriz[5][5];
    gerar_matriz(matriz);

    cout << "Matriz gerada:" << endl;
    mostrar_matriz(matriz);

    cout << "Diagonal principal:" << endl;
    mostrar_diagonal_principal(matriz);

    cout << "Diagonal secundaria:" << endl;
    mostrar_diagonal_secundaria(matriz);

    encontrar_maior_elemento(matriz);

    return 0;
}