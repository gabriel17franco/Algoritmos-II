// Crie um programa que, utilizando uma função recursiva, inverta um número inteiro
// qualquer.
// Exemplo:
// Número informado: 123
// Resultado exibido: 321

#include <iostream>
#include <ctime>
#include <set>
using namespace std;


 void inverter(string num, int index)
{
   
   if(num.length() != index ){
       index++;
       inverter(num, index);
   }
   
   cout << num[index-1];
}

int main()
{
    string num, numinv;

    cout << "Informe um numero: " << endl;
    cin >> num;

    inverter(num, 0);

    return 0;
}