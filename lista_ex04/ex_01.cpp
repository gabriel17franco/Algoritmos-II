// – Crie um programa que manipule uma matriz 3 x 5 de números inteiros, o sistema deverá
// utilizar funções para realizar as ações apresentadas abaixo:
// - Gerar valores para preencher toda a matriz, não sendo permitido números maiores que 50 e
// somente números pares serão aceitos na matriz
// - Mostrar a matriz gerada e sua respectiva matriz transposta.
// - Calcular e mostrar o maior, o menor e a média dos elementos existentes na matriz


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void gerar_matriz(int matriz[3][5]) {
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int valor = rand() % 25 + 2;
            while (valor % 2 != 0) {
                valor = rand() % 25 + 2;
            }
            matriz[i][j] = valor;
        }
    }
}

void mostrar_matriz(int matriz[3][5]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void mostrar_matriz_transposta(int matriz[3][5]) {
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 3; i++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void calcular_maior_menor_media(int matriz[3][5], int& maior, int& menor, float& media) {
    maior = matriz[0][0];
    menor = matriz[0][0];
    int soma = matriz[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
            soma += matriz[i][j];
        }
    }
    media = soma / 15;
}
int main() {
    int matriz[3][5];
    int maior, menor;
    float media;

    gerar_matriz(matriz);
    cout << "Matriz gerada:" << endl;
    mostrar_matriz(matriz);

    cout << "Matriz transposta:" << endl;
    mostrar_matriz_transposta(matriz);

    calcular_maior_menor_media(matriz, maior, menor, media);
    cout << "Maior valor: " << maior << endl;
    cout << "Menor valor: " << menor << endl;
    cout << "Media: " << media << endl;

    return 0;
}