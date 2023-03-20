// 14 – Escreva um programa em C++ que manipule uma matriz de inteiros M[8][8] e acione as
// seguintes funções:
// A) Função que gere valores aleatórios, menores que 100 para preencher a matriz.
// B) Função que receba a matriz por parâmetro e exiba os seus valores na tela.
// C) Função que receba a matriz M e um vetor V[8] o qual deve ser formado pela soma dos
// elementos de cada linha da matriz, apresente o vetor na tela.
// D) Função que recebe a matriz e apresenta os elementos da diagonal principal e diagonal
// secundária.

#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int main()
{
    int gerarvalor();

    void mostrar(int *m);


    int m[8][8];
    int i,j;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            m[i][j] = gerarvalor();
        }
    }
    mostrar(&m[0][0]);
}

int gerarvalor()
{
    srand(time(NULL));
    return (int)rand() / 100;
}

void mostrar(int *m){
    int i,j;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
           cout << m[j+i] << endl;
        }
    }
}