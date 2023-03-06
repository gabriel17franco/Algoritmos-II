// 5 – Na papelaria “Livro e Cia” a volta as aulas é um momento de realizar promoções, os itens
// descritos abaixo estão com o respectivo desconto e percentual

// Descrição Código Valor R$ Desconto %
// Folha branca A4 com 500 1 28.00 7%
// Caneta Bic ponta fina 2 6.30 5%
// Caderno 10 matérias 3 22.00 5%
// Caneta marca texto 4 17.80 6%
// Cola bastão 5 5.50 7%
// Corretor ortográfico 6 11.00 10%
// Lápis preto 7 4.50 2%
// Mochila com repartimento 8 138.00 7%
// Caderno de desenho 9 8.00 5%

// Escreva um programa que auxilie o dono da papelaria a realizar as compras dos clientes, o
// programa deve possibilitar que o atendente informe o código do item e a quantidade solicitada,
// sendo possível incluir vários itens na mesma compra, para tanto a cada item solicitado o
// sistema deverá apresentar as seguintes possibilidades:
// 1 – Incluir mais um item
// 2 – Encerrar a compra
// Se a opção for incluir mais um item (1) permite informar o código e a quantidade do próximo
// item, caso a opção seja encerrar a compra (2) deverá exibir os itens da compra, com as
// respectivas quantidades, o valor do item e ao final o valor total da compra, como no exemplo:
// Descrição QTD Valor do Item Desconto Total Item
// Folha branca A4 com 500 1 28.00 1.96 26.04
// Caderno 10 matérias 2 44.00 2.20 41.80
// Cola bastão 1 5.50 0.38 5.12
// Total da compra:....................................................................................................72.96
// OBS:
// - Validar para aceitar somente itens pertencentes à lista apresentada.
// - Exibir a compra com os alinhamentos e os valores numéricos formatados conforme no
// exemplo.
// - Aplicar o desconto em cada item, conforme a tabela de promoções

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
    typedef struct
    {
        int codigo;
        char descrição[200];
        float valor;
        float desconto;
    } Produto;

    Produto estoque[10] = {
        {1, "Folha branca A4 com 500", 28.00, 0.07},
        {2, "Caneta Bic ponta fina", 6.30, 0.05},
        {3, "Caderno 10 materias", 22.00, 0.05},
        {4, "Caneta marca texto", 17.80, 0.06},
        {5, "Cola bastao", 5.50, 0.07},
        {6, "Corretor ortografico", 11.00, 0.10},
        {7, "Lápis preto", 4.50, 0.02},
        {8, "Mochila com repartimento", 138.00, 0.07},
        {9, "Caderno de desenho", 8.00, 0.05},
    };

    bool finalizar, mudei;
    int i, itens = 0, itens_final = 0, j;
    float total = 0, total_desconto = 0;

    Produto carrinho[10], final[10];

    do
    {
        int opcao;
        cout << "1 - Inserir produto: " << endl;
        cout << "2 - Finalizar compra: " << endl;

        cin >> opcao;

        switch (opcao)
        {

        case 1:
        {
            int cod, qtd;
            bool valido;
            cout << "Informe o codigo do produto: " << endl;
            cin >> cod;

            cout << "Informe a quantidade do produto: " << endl;
            cin >> qtd;

            for (i = 0; i <= 9; i++)
            {
                if (estoque[i].codigo == cod)
                {
                    for (j = 1; j <= qtd; j++)
                    {
                        carrinho[itens] = estoque[i];
                        valido = true;
                        itens++;
                    }
                }
            }

            if (valido)
            {
                cout << "Produto inserido!" << endl;
            }
            else
            {
                cout << "Codigo do produto nao existente" << endl;
            }

            break;
        }
        case 2:
        {
            finalizar = true;
            break;
        }
        default:
            cout << "Opção invalida!" << endl;
            break;
        }

    } while (finalizar != true);

    cout << "Itens do carrinho" << endl;
    cout << endl;

    for (i = 0; i < itens; i++)
    {
        total += carrinho[i].valor;
        total_desconto += carrinho[i].valor * carrinho[i].desconto;
    }

    do
    {
        mudei = false;

        for (i = 0; i < itens; i++)
        {
            if (carrinho[i].codigo > carrinho[i + 1].codigo)
            {
                Produto aux = carrinho[i + 1];
                carrinho[i + 1] = carrinho[i];
                carrinho[i] = aux;
                mudei = true;
            }
        }

    } while (mudei);
    
    for (i = 0; i < itens; i++)
    {
        if(carrinho[i].codigo != carrinho[i+1].codigo ){
            final[itens_final] = carrinho[i+1];
            itens_final++;
        }   
            
    }

    for (i = 0; i < itens_final; i++)
    {
        cout << "| Codigo: " << final[i].codigo << " | Produto: " << final[i].descrição << " | Valor: "
             << fixed << setprecision(2) << final[i].valor << " | Desconto: " << final[i].desconto * 100 << "%"
             << " |" << endl;
    }
    cout << endl;
    cout << "Valor Total: " << fixed << setprecision(2) << total << " | "
         << "Valor total desconto: " << fixed << setprecision(2) << total_desconto << endl;

    return 0;
}