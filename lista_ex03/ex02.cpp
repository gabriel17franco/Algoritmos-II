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

using namespace std;

int main()
{
    int valor, i;
    int quantidade[7] = {0, 0, 0, 0, 0, 0, 0};
    int notas[7] = {2, 5, 10, 20, 50, 100, 200};

    int valorSaque();

    int *qdtNotas(int valor, int qtd[], int notas[]);

    valor = valorSaque();

    if (valor < 2 || valor == 3)
    {
        cout << "Saque não permitido:" << endl;
    }
    else
    {
        qdtNotas(valor, quantidade, notas);
        cout << "Retire seu dinheiro:" << endl;
        for (i = 6; i >= 0; i--)
        {
            if (quantidade[i] > 0)
            {
                cout << quantidade[i] << " notas de " << notas[i] << endl;
            }
        }
    }
    return 0;
}

int valorSaque()
{
    int valor;

    cout << "Digite o valor do saque: ";
    cin >> valor;

    return valor;
}

int *qdtNotas(int valor, int quantidade[], int notas[])
{

    int valorRestante, i;

    valorRestante = valor;
    for (i = 6; i >= 0; i--)
    {
        quantidade[i] = valorRestante / notas[i];
        valorRestante = valorRestante % notas[i];
    }

    return quantidade;
}
