/*
Dona Parcinova costuma ir regularmente à feira para comprar frutas e legumes. Ela pediu então à sua filha, Mangojata, que a ajudasse com as contas e que fizesse um programa que calculasse o valor que precisa levar para poder comprar tudo que está em sua lista de compras, considerando a quantidade de cada tipo de fruta ou legume e os preços destes itens.

Entrada
A primeira linha de entrada contém um inteiro N que indica a quantidade de idas à feira de dona Parcinova (que nada mais é do que o número de casos de teste que vem a seguir). Cada caso de teste inicia com um inteiro M que indica a quantidade de produtos que estão disponíveis para venda na feira. Seguem os M produtos com seus preços respectivos por unidade ou Kg. A próxima linha de entrada contém um inteiro P (1 ≤ P ≤ M) que indica a quantidade de diferentes produtos que dona Parcinova deseja comprar. Seguem P linhas contendo cada uma delas um texto (com até 50 caracteres) e um valor inteiro, que indicam respectivamente o nome de cada produto e a quantidade deste produto.

Saída
Para cada caso de teste, imprima o valor que será gasto por dona Parcinova no seguinte formato: R$ seguido de um espaço e seguido do valor, com 2 casas decimais, conforme o exemplo abaixo.

Exemplo de Entrada	
2
4
mamao 2.19
cebola 3.10
tomate 2.80
uva 2.73
3
mamao 2
tomate 1
uva 3
5
morango 6.70
repolho 1.12
brocolis 1.71
tomate 2.80
cebola 2.81
4
brocolis 2
tomate 1
cebola 1
morango 1

Exemplo de Saída
R$ 15.37
R$ 15.73
*/
#include <string.h>
#include <stdio.h>

int main()
{
    int N, M, P, quantidade;
    char fruta[50], frutas[100][50];
    double resposta, precos[100];

    scanf("%d", &N);

    for (int k = 0; k < N; ++k)
    {
        scanf("%d", &M);

        for (int i = 0; i < M; ++i)
        {
            scanf("%s %lf\n", &frutas[i], &precos[i]);
        }

        scanf("%d", &P);

        resposta = 0.0;
        for (int i = 0; i < P; ++i)
        {
            scanf("%s %d\n", &fruta, &quantidade);

            for (int j = 0; j < M; ++j)
            {
                if (strcmp(fruta, frutas[j]) == 0)
                {
                    resposta += quantidade * precos[j];
                    break;
                }
            }
        }

        printf("R$ %.2lf\n", resposta);
    }

    return 0;
}