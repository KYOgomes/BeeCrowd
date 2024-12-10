/*
A. C. Marcos está dando os primeiros passos para ser um compositor de jingles. Ele está tendo alguns problemas, mas ao menos ele está criando melodias agradáveis e ritmos atrativos.

Na música, uma nota tem um tom (sua frequência, resultando em quão grave ou agudo é o som) e uma duração (por quanto tempo a nota soa). Neste problema, estamos interessados apenas na duração das notas.

Um jingle é dividido em uma sequência de compassos, e um compasso é formado de uma série de notas.

A duração de uma nota é indicada pela sua forma. Neste problema, iremos utilizar letras maiúsculas para indicar a duração de uma nota. A seguinte tabela lista todas as notas disponíveis:

A duração de um compasso é a soma da duração de suas notas. Nos jingles de Marcos, cada compasso tem a mesma duração. Como Marcos é apenas um iniciante, seu famoso professor Johann Sebastian III o ensinou que a duração de um compasso deve ser sempre 1.

Por exemplo, Marcos escreveu uma composição contendo cinco compassos, dentre os quais quatro possuem a duração correta e um está errado. No exemplo abaixo, cada compasso é delimitado com barras e cada nota é representada como na tabela acima.

/HH/QQQQ/XXXTXTEQH/W/HW/

Marcos gosta de computadores assim como de música. Ele quer que você escreva um programa que determine, para cada uma de suas composições, quantos compassos possuem a duração correta.

Entrada
A entrada contém vários casos de teste. Cada caso de teste é descrito em uma única linha contendo uma string cujo tamanho está entre 3 e 200 caracteres, inclusive, representando uma composição. Uma composição começa e termina com uma barra '/'. Compassos em uma composição são separados por uma barra '/'. Cada nota em um compasso é representada pela letra correspondente segundo a descrição acima. Você pode assumir que cada composição contém ao menos um compasso e que cada compasso contém ao menos uma nota. Todos os caracteres na entrada serão barras ou uma das sete letras maiúsculas usadas para representar as notas.

O último caso de teste é seguido por uma linha contendo um único asterisco.

Saída
Para cada caso de teste, seu programa deve imprimir uma única linha contendo um único inteiro, o número de compassos que possuem a duração correta.

Exemplo de Entrada
/HH/QQQQ/XXXTXTEQH/W/HW/
/W/W/SQHES/
/WE/TEX/THES/
*

Exemplo de Saída
4
3
0

*/

#include <string.h>
#include <stdio.h>

double duracaoNota(char nota)
{
    if (nota == 'W')
    {
        return 1.0;
    }
    else if (nota == 'H')
    {
        return 0.5;
    }
    else if (nota == 'Q')
    {
        return 0.25;
    }
    else if (nota == 'E')
    {
        return 0.125;
    }
    else if (nota == 'S')
    {
        return 0.0625;
    }
    else if (nota == 'T')
    {
        return 0.03125;
    }
    else if (nota == 'X')
    {
        return 0.015625;
    }

    /*
    switch (nota)
    {
    case 'W':
        return 1.0;
    case 'H':
        return 0.5;
    case 'Q':
        return 0.25;
    case 'E':
        return 0.125;
    case 'S':
        return 0.0625;
    case 'T':
        return 0.03125;
    case 'X':
        return 0.015625;
    }
    */
}

int main()
{
    int resposta;
    double duracao;
    char composicao[1000];

    while (scanf("%[^\n]\n", &composicao) != EOF)
    {
        if (strcmp(composicao, "*") == 0)
            break;

        resposta = 0;
        duracao = 0.0;
        for (int i = 0; i < strlen(composicao); ++i)
        {
            if (composicao[i] == '/')
            {
                if (duracao == 1.0)
                    ++resposta;
                duracao = 0.0;
            }
            else
            {
                duracao += duracaoNota(composicao[i]);
            }
        }

        printf("%d\n", resposta);
    }

    return 0;
}