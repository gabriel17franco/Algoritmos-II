// 9 - Um pangrama é uma frase que contém todas as letras de um determinado alfabeto.
// Em português, um pangrama pode incluir também letras acentuadas, mas neste
// problema vamos desconsiderar os acentos (mesmo que isso torne a frase mal escrita!),
// também vamos considerar o seguintes alfabeto:
// a b c d e f g h i j l m n o p q r s t u v x z
// Não consideramos as letras k, w ou y. Note ainda que as frases não contêm letras
// acentuadas mas podem conter símbolos gráficos como espaço em branco, vírgula, ponto
// e dois pontos.
// Entrada
// Uma única linha da entrada conténdo uma cadeia de caracteres C.
// Saída
// Seu programa deve produzir uma única linha, contendo um único caractere, que deve
// ser S se a frase for um pangrama ou N caso contrário.
// Restrições
// A cadeia de caracteres C tem no mínimo um e no máximo 200 caracteres. Os únicos
// caracteres em C são as letras minúsculas do alfabeto mostrado acima, podem existir
// caracteres repetidos, espaços em branco, vírgulas, ponto e o caractere dois pontos

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
    typedef struct
    {
        bool existe;
        char caractere;
    } letra;

    string texto;

    int lenght = 0, i;
    bool valido = true;
    char c;

    letra alfabeto[26];

    for (c = 'a'; c <= 'z'; c++)
    {
        alfabeto[lenght].caractere = c;
        alfabeto[lenght].existe = false;
        lenght++;
    }

    for (i = 0; i < lenght; i++)
    {
        cout << alfabeto[i].caractere;
    }

    cout << endl;

    cout << lenght << endl;

    lenght = 0;

    getline(cin, texto);

    cout << texto << endl;

    for (char c : texto)
    {
        if (c == alfabeto[lenght].caractere)
        {
            alfabeto[lenght].existe = true;
        }
        else {
            cout << c << "<>" << alfabeto[lenght].caractere << endl;
        }
        lenght++;
    }

    char resultado = valido == false ? 'n' : 's';

    cout << resultado << endl;

    return 0;
}