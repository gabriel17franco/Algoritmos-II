// 2 – Escreva um programa que manipule um vetor VET[20] de números float, os valores para
// preencher o vetor devem ser gerados randomicamente, mostre o vetor gerado na tela, exibindo

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    float vetor[20];
    int i;
    int j = 0;

    srand(time(NULL));

    for (i = 0; i <= 19; i++)
    {
        vetor[i] = (float)rand() / 1000;
    }

    for (i = 0; i <= 19; i++)
    {
        j++;
        if (j == 5)
        {
            cout << fixed << setprecision(3) << vetor[i] << ", " << endl;
            j = 0;
        }
        else
        {
            cout << fixed << setprecision(3) << vetor[i] << ", ";
        }
    }

    cout << endl;

    for (i = 0; i <= 19; i++)
    {
        j++;
        if (j == 5)
        {
            cout << round(vetor[i] * 10) / 10 << ", " << endl;
            j = 0;
        }
        else
        {
            cout << round(vetor[i] * 10) / 10 << ", ";
        }
    }

    return 0;
}