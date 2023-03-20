// 8 - Escreva um programa que recebe uma string do usuário e verifica se ela é um
// endereço de e-mail do google válido, sabendo que os endereços de e-mail do google
// seguem o seguinte formato:
// textoqualquer@gmail.com
// Algumas restrições importantes:
// - endereços de e-mail não podem conter espaço em branco
// - obrigatoriamente deve aparecer somente uma vez o caracter @
// - considere que neste caso o endereço de e-mail não pode iniciar por um número
// - endereço de e-mail só pode conter caracteres minúsculos
// - o “_” underline e o “.” ponto podem aparecer entre duas palavras

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
    int lenght = -1, arroba = 0;
    bool valido;

    cout << "Digite uma palavra" << endl;
    getline(cin, texto);

    for (char c : texto)
    {
        lenght++;

        arroba = c == '@' ? +1 : arroba;

        if (c == ' ' && lenght > 0 || (lenght == 0 && isdigit(c)) || isupper(c) || arroba > 1)
        {
            valido = false;
        }
        if (c == '_' || c == '.')
        {
            valido = lenght > 0 ? valido : false;

            valido = (isalpha(texto[lenght - 1]) || isdigit(texto[lenght - 1])) && (isalpha(texto[lenght + 1]) || isdigit(texto[lenght + 1])) ? valido : false;
        }
    }

    string resultado = valido == false ? "Invalido" : "Valido";

    cout << resultado << endl;

    return 0;
}