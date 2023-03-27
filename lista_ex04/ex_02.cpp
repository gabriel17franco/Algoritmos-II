// Crie um programa que manipule uma matriz de inteiros m[7][7]. Utilizando funções o
// programa deverá apresentar um menu para acionar as seguintes funcionalidades:
// 1 – Gerar valores para preencher a matriz, não sendo permitido números duplicados e devem
// ser menores que 100.
// 2 – Mostrar a matriz na tela
// 3 - Encontrar o maior elemento de cada linha e passá-lo para a posição da diagonal principal na
// linha e o elemento que estava na diagonal principal para o local do número, exibir a matriz
// original e depois modificada.
// 4 – Verificar se a Matriz é uma matriz simétrica
// 5 – Mostrar os elementos acima e abaixo da diagonal principal


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void gerar_matriz(int matriz[7][7]) {
    srand(time(NULL));
    bool numeros_usados[100] = { false };
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            int valor = rand() % 100;
            while (numeros_usados[valor]) {
                valor = rand() % 100;
            }
            numeros_usados[valor] = true;
            matriz[i][j] = valor;
        }
    }
}

void mostrar_matriz(int matriz[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void encontrar_maior_elemento(int matriz[7][7]) {
    for (int i = 0; i < 7; i++) {
        int maior = matriz[i][0];
        int coluna_maior = 0;
        for (int j = 1; j < 7; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                coluna_maior = j;
            }
        }
        int auxiliar = matriz[i][i];
        matriz[i][i] = matriz[i][coluna_maior];
        matriz[i][coluna_maior] = auxiliar;
    }
}

bool verificar_simetria(int matriz[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < i; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                return false;
            }
        }
    }
    return true;
}

void mostrar_diagonal(int matriz[7][7]) {
    cout << "Elementos acima da diagonal principal:" << endl;
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            cout << matriz[i][j] << " ";
        }
    }
    cout << endl;
    cout << "Elementos abaixo da diagonal principal:" << endl;
    for (int i = 1; i < 7; i++) {
        for (int j = 0; j < i; j++) {
            cout << matriz[i][j] << " ";
        }
    }
    cout << endl;
}

int main() {
    int matriz[7][7];

    int opcao = 0;
    while (opcao != 6) {
        cout << endl << "Escolha uma opcao:" << endl;
        cout << "1 - Gerar valores para preencher a matriz" << endl;
        cout << "2 - Mostrar a matriz na tela" << endl;
        cout << "3 - Encontrar o maior elemento de cada linha e passa-lo para a posicao da diagonal principal na linha e o elemento que estava na diagonal principal para o local do numero, exibir a matriz original e depois modificada" << endl;
        cout << "4 - Verificar se a matriz e uma matriz simetrica" << endl;
        cout << "5 - Mostrar os elementos acima e abaixo da diagonal principal" << endl;
        cout << "6 - Sair" << endl;
        cin >> opcao;

        switch (opcao) {
        case 1:
            gerar_matriz(matriz);
            cout << "Matriz gerada!" << endl;
            break;
        case 2:
            mostrar_matriz(matriz);
            break;
        case 3:
            encontrar_maior_elemento(matriz);
            cout << "Matriz original:" << endl;
            mostrar_matriz(matriz);
            break;
        case 4:
            if (verificar_simetria(matriz)) {
                cout << "A matriz e simetrica!" << endl;
            } else {
                cout << "A matriz nao e simetrica!" << endl;
            }
            break;
        case 5:
            mostrar_diagonal(matriz);
            break;
        case 6:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }
    }

    return 0;
}