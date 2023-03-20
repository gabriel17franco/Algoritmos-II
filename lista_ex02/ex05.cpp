// 10 - Uma palavra A é um anagrama de outra palavra B se podemos transformar a
// palavra A na palavra B apenas trocando de posição as letras da palavra A. Por exemplo,
// "iracema" é um anagrama de "america", e "estudo" é um anagrama de "duetos".
// Sabendo deste conceito escreva um programa que receba duas palavras diferentes
// quaisquer e verifique se elas são um anagrama exibindo como resposta “SIM”, caso não
// são um anagrama exibir “NÃO”

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <cmath>
#include <ctype.h>
#include <iterator>

using namespace std;

int main()
{

    int i1, lenght1, i2, lenght2;

    bool anagrama;

    string texto1, texto2;

    cout << "Digite uma palavra" << endl;
    getline(cin, texto1);

    cout << "Digite outra palavra" << endl;
    getline(cin, texto2);

    if (sizeof(texto1) != sizeof(texto2))
    {
        cout << "Não" << endl;
        cout << "1" << endl;
    }
    else
        lenght1 = sizeof(texto1) / sizeof(char);
        lenght2 = lenght1;

    cout << lenght1 << endl;

    {
        for (i1 = 0; i1 <= lenght1; i1++)
        {
            for (i2 = lenght2; i2 >= 0; i2--)
            {
                anagrama = texto1[i1] != texto2[i2] ? false : anagrama;
            }
        }
    }

    if (anagrama == false)
    {
        cout << "Não" << endl;
    }
    else
    {
        cout << "Sim" << endl;
    }

    return 0;
}
