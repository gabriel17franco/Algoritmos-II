// Crie um programa que manipule um vetor V[10] que deve ser preenchido randomicamente
// com valores inteiros entre 15 e 50, sem números repetidos.
// Após gerar o vetor o programa deverá:
// - Exibir o vetor na tela
// - Exibir o vetor em ordem crescente
// - Exibir a quantidade de valores pares e ímpares existentes no vetor
// - Exibir o percentual de valores pares e o percentual de valores ímpares no vetor
// - Exibir a média dos valores do vetor com duas casas decimais.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <cmath>
#include <locale.h>

using namespace std;

int main()
{
    int vetor[10];
    int i, j, par = 0, impar = 0, media = 0;
    bool valid, mudei;

    srand(time(NULL));

    for (i = 0; i <= 9; i++)
    {
        int num = rand() % (50 - 15 + 1);
        for (j = 0; j <= 9; j++)
        {
            if (vetor[j] == num)
            {
                valid = false;
            }
        }
        if (valid == false)
        {
            i = i - 1;
            valid = true;
        }
        else
        {
            vetor[i] = num;
        }
    }
    do
    {
        mudei = false;

        for (i = 0; i <= 9; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                int aux = vetor[i + 1];
                vetor[i + 1] = vetor[i];
                vetor[i] = aux;
                mudei = true;
            }
        }

    } while (mudei);

    for (i = 0; i <= 9; i++)
    {
        if ((vetor[i] % 2) == 0)
        {
            par += 1;
        }
        else
        {
            impar += 1;
        }
        media += vetor[i];

        cout << vetor[i] << endl;
    }

    cout << "Numeros pares:" << par << "|" << (par * 100) / 10 << "%" << endl;
    cout << "Numeros impares:" << impar << "|" << (impar * 100) / 10 << "%" << endl;
    cout << "Media:" << media / 10 << endl;

    return 0;
}