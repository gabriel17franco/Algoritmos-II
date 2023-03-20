// Crie programa em C++ que manipule um vetor de inteiros de 10 posições, o programa
// deve apresentar um menu com as seguintes opções:
// 0 – Sair
// 1 – Gerar Valores (Função que gera os valores para preencher o vetor com números entre 20 e
// 50 sem valores repetidos)
// 2 – Mostrar Vetor (Função que recebe o vetor e exibe seus valores na tela)
// 3 – Mostrar Ordenado (Função que recebe o vetor e exibe os seus valores ordenados em ordem
// crescente e decrescente)
// OBS: A opção 2 e 3 do menu só podem ser executadas após a execução da opção 1, ao escolher
// a opção inválida do menu exibir mensagem de “opção inválida”.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <cmath>
#include <ctype.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    void gerarValores(int vetor[], int tam);
    void mostrarVetor(int vetor[], int tam);
    void mostrarOrdenado(int vetor[], int tam);

    int opcao;
    int vetor[10];       
    bool gerouValores = false; 

    do
    {
        cout << "0 - Sair" << endl;
        cout << "1 - Gerar Valores" << endl;
        cout << "2 - Mostrar Vetor" << endl;
        cout << "3 - Mostrar Ordenado" << endl;
       
        cin >> opcao;

        switch (opcao)
        {
        case 0:
            break;
        case 1:
            gerarValores(vetor, 10);
            gerouValores = true;
            cout << "Valores gerados com sucesso." << endl;
            break;
        case 2:
            if (gerouValores)
            {
                mostrarVetor(vetor, 10);
            }
            else
            {
                cout << "Valores nao foram gerados." << endl;
            }
            break;
        case 3:
            if (gerouValores)
            {
                mostrarOrdenado(vetor, 10);
            }
            else
            {
                cout << " Valores nao foram gerados." << endl;
            }
            break;
        default:
            cout << "Opcao invalida." << endl;
            break;
        }
    } while (opcao != 0);

    return 0;
}

void gerarValores(int vetor[], int tam)
{
    srand(time(NULL)); 
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = rand() % 31 + 20;
        for (int j = 0; j < i; j++)
        {
            if (vetor[i] == vetor[j])
            {
                i--; 
                break;
            }
        }
    }
}

void mostrarVetor(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void mostrarOrdenado(int vetor[], int tam)
{
    sort(vetor, vetor + tam); 
    cout << "Ordem crescente: ";
    mostrarVetor(vetor, tam);
    sort(vetor, vetor + tam, greater<int>()); 
    cout << "Ordem decrescente: ";
    mostrarVetor(vetor, tam);
}