// 13 – Escreva um programa que utilizando uma função leia um número inteiro qualquer, a seguir
// execute outra função que receba o valor por parâmetro e gere e apresente na tela os primeiros
// 5 números primos maiores que o valor informado.

// 12 - Escreva um programa que simule um caixa eletrônico, sabendo que o caixa dispõe das
// seguintes notas: 2, 5, 10, 20, 50, 100 e 200. O caixa deve priorizar (sempre que possível) a
// entrega das notas de maior valor, por exemplo:
// Saque 75,00: uma nota de 50, uma nota de 20 e uma nota de 5
// Saque 11,00: uma nota de 5, 3 notas de 2
// Caso seja solicitado um valor inválido para saque deverá informar uma mensagem com tal
// informação e solicitar a leitura de outro valor.
// O valor do saque deve ser lido e validado utilizando função
// O cálculo das notas deverá ser realizado utilizando uma função que recebe como parâmetro o
// valor do saque e a nota e retornar a quantidade de notas do referido valor

#include <iostream>
#include <cmath>


using namespace std;

int main()
{

    int primo(int numero);

    int numero, i, primos = 1;

    cout << "Informe o número:" << endl;
    cin >> numero;

    i = numero;

    while (primos <= 5)
    {   
        int v1 = primo(i);

        if(v1 > 0){
            cout << v1 << endl;
            primos++;
        }
        i++;
    }
    

    return 0;
}

int primo(int numero)
{
    for (int i = 2; i <= sqrt(numero); i++)
    {
        if (numero % i == 0)
        {
            return 0;
        }
    }
    return numero;

    return 0;
}