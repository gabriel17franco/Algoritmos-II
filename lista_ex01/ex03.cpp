// 3 - Elabore um programa que possibilite a realização dos seguintes cálculos:
// 1 – Potenciação (entrada dois valores inteiros e positivos)
// 2 – Raiz quadrada (entrada um valor inteiro e positivo)
// 3 - Arredondar o valor seguindo o critério da primeira casa decimal e mostrar na tela
// (entrada um valor float)
// 4 – Verificar se um valor é primo ou não (entrada um valor inteiro positivo)
// 5 – Verificar se um valor é um número perfeito ou não (entrada um valor inteiro positivo).
// O sistema deverá apresentar um menu com as opções e conforme a opção desejada será
// solicitado os dados de entrada.

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
    bool sair = false;
    int funcao;

    setlocale(LC_ALL, "Portuguese");

    while (sair == false)
    {
        cout << "Escolha uma opcao:" << endl;
        cout << "1 - Potenciacao" << endl;
        cout << "2 - Raiz quadrada" << endl;
        cout << "3 - Arredondar valor" << endl;
        cout << "4 - Verificar se e primo" << endl;
        cout << "5 - Verificar se e numero perfeito" << endl;
        cout << "0 - Sair" << endl;
        cin >> funcao;

        switch (funcao)
        {
        case 0:
            sair = true;
            break;
        case 1:
        {
            int base, expoente;
            cout << "Digite a base: ";
            cin >> base;
            cout << "Digite o expoente: ";
            cin >> expoente;
            cout << "Resultado: " << pow(base, expoente) << endl;
            break;
        }
        case 2:
        {
            int n;
            cout << "Digite o numero: ";
            cin >> n;
            cout << "Resultado: " << sqrt(n) << endl;
            break;
        }
        case 3:
        {
            float n;
            cout << "Digite o numero: ";
            cin >> n;
            cout << "Resultado: " << round(n * 10) / 10 << endl;
            break;
        }
        case 4:
        {
            int n;
            cout << "Digite o numero: ";
            cin >> n;
            if (n <= 1)
            {
                cout << "Nao e primo" << endl;
            }
            for (int i = 2; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    cout << "Nao e primo" << endl;
                }
            }
            cout << "É primo" << endl;
            break;
        }
        case 5:
        {
            int n;
            cout << "Digite o numero: ";
            cin >> n;
            int j = 1;
            for (int i = 2; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    j += i;
                    if (i != n / i)
                    {
                        j += n / i;
                    }
                }
            }
            if (j == n && n != 1)
            {
                cout << "E numero perfeito" << endl;
            }
            else
            {
                cout << "Nao e numero perfeito" << endl;
            }
            break;
        }
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}