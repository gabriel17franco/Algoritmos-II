// 7 - Escreva um programa que recebe uma string qualquer do usuário e imprime a
// mesma string em três formatos: todas as letras em maiúsculo, todas as letras em
// minúsculo e somente as letras iniciais de cada palavra em maiúsculo o restante em
// minúsculo.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <cmath>
#include <ctype.h>

using namespace std;

int main()
{

    string texto, maiusculo, minusculo, camel;
    int lenght = -1;

    cout << "Digite uma palavra" << endl;
    getline(cin, texto);

    for (char c : texto)
    {
        lenght++;
        maiusculo += toupper(c);
        minusculo += tolower(c);
        if (texto[lenght - 1] == ' ' || lenght == 0)
        {
            camel += toupper(c);
        }
        else
        {
            camel += tolower(c);
        }
    }

    cout << "Maiusculo: " << maiusculo << endl;
    cout << "Maiusculo: " << minusculo << endl;
    cout << "Maiusculo: " << camel << endl;

    return 0;
}