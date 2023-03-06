// 1 – Escreva um programa que simule um caixa eletrônico que dispõem das seguintes notas: 2,
// 5, 10, 20, 50, 100 e 200 o programa deverá receber o valor do saque e, sendo possível realizar
// o saque, deverá apresentar a quantidade e quais notas devem ser entregues, sempre
// priorizando as notas maiores.
// Não é permitido saque de valores menores que 2 e igual a 3 os demais valores é possível
// realizar o saque:
// Exemplo: Valor do saque R$: 11.00
// Retire seu dinheiro:
// 3 notas de 2
// 1 nota de 5

#include <iostream>

using namespace std;

int main() {
    int notas[7] = {2, 5, 10, 20, 50, 100, 200}; 
    int quantidade[7] = {0, 0, 0, 0, 0, 0, 0}; 
    int valor, valorRestante, i;

    cout << "Digite o valor do saque: ";
    cin >> valor;

    if (valor < 2 || valor == 3) {
        cout << "Saque não permitido:" << endl;
    } else {
        valorRestante = valor;
        for (i = 6; i >= 0; i--) {
            quantidade[i] = valorRestante / notas[i];
            valorRestante = valorRestante % notas[i];
        }
        cout << "Retire seu dinheiro:" << endl;
        for (i = 6; i >= 0; i--) {
            if (quantidade[i] > 0) {
                cout << quantidade[i] << " notas de " << notas[i] << endl;
            }
        }
    }
    return 0;
}