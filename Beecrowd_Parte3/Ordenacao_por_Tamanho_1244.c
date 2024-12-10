/*
Crie um programa para ordenar um conjunto de strings pelo seu tamanho. Seu programa deve receber um conjunto de strings e retornar este mesmo conjunto ordenado pelo tamanho das palavras, se o tamanho das strings for igual, deve-se manter a ordem original do conjunto.

Entrada
A primeira linha da entrada possui um único inteiro N, que indica o número de casos de teste. Cada caso de teste poderá conter de 1 a 50 strings inclusive, e cada uma das strings poderá conter entre 1 e 50 caracteres inclusive. Os caracteres poderão ser espaços, letras, ou números.

Saída
A saída deve conter o conjunto de strings da entrada ordenado pelo tamanho das strings. Um espaço em branco deve ser impresso entre duas palavras.

Exemplo de Entrada	
4
Top Coder comp Wedn at midnight
one three five
I love Cpp
sj a sa df r e w f d s a v c x z sd fd

Exemplo de Saída
midnight Coder comp Wedn Top at
three five one
love Cpp I
sj sa df sd fd a r e w f d s a v c x z
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int tam;
char palavras[100][100];

int comp(char *a, char *b)
{
    return strlen(b) - strlen(a);
}

void insertionSort()
{
    char aux[100];

    for (int i = 1; i < tam; ++i)
    {
        int j = i, k = j - 1;

        while (k > -1 && comp(palavras[j], palavras[k]) < 0)
        {
            strcpy(aux, palavras[j]);
            strcpy(palavras[j], palavras[k]);
            strcpy(palavras[k], aux);
            --j, --k;
        }
    }
}

int main()
{
    int N;
    char frase[10000], *ptr;

    scanf("%d\n", &N);

    for (int k = 0; k < N; ++k)
    {
        scanf("%[^\n]\n", &frase);

        tam = 0;
        ptr = strtok(frase, " ");
        while (ptr != NULL)
        {
            strcpy(palavras[tam++], ptr);
            ptr = strtok(NULL, " ");
        }

        insertionSort(&palavras, tam);

        printf("%s", palavras[0]);
        for (int i = 1; i < tam; ++i)
        {
            printf(" %s", palavras[i]);
        }
        printf("\n");
    }

    return 0;
}