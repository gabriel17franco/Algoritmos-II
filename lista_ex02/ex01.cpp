// 6 – Escreva um programa que receba um texto qualquer do teclado, em seguida
// apresente:
// - Total de caracteres do texto
// - Total de caracteres em maiúsculo e em minúsculo do texto
// - Total de vogais
// - Total de consoantes
// - Total de números
// - Total de espaços em branco

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
    int caracteres = 0, maiusculo = 0, minusculo = 0, vogais = 0, consoantes = 0, numeros = 0, espaco = 0;

    string texto;

    cout << "Digite um texto: ";
    getline(cin, texto);

    for (char c : texto)
    {
        caracteres++;
        espaco = isspace(c) ? espaco + 1 : espaco;
        numeros = isdigit(c) ? numeros + 1 : espaco;
        maiusculo = isupper(c) ? maiusculo + 1 : maiusculo;
        minusculo = islower(c) ? minusculo + 1 : minusculo;
        c = tolower(c);
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u')
        {
            vogais++;
        }
        else
        {
            consoantes++;
        }
    }

    cout << "Caracteres: " << caracteres << endl;
    cout << "Espacos: " << espaco << endl;
    cout << "Numeros: " << numeros << endl;
    cout << "Caracteres maiusculos: " << maiusculo << endl;
    cout << "Caracteres minusculo: " << minusculo << endl;
    cout << "Vogais: " << vogais << endl;
    cout << "Consoantes: " << consoantes << endl;

    return 0;
}