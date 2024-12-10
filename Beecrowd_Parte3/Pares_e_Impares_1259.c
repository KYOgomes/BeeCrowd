/*
Considerando a entrada de valores inteiros não negativos, ordene estes valores segundo o seguinte critério:

Primeiro os Pares
Depois os Ímpares
Sendo que deverão ser apresentados os pares em ordem crescente e depois os ímpares em ordem decrescente.

Entrada
A primeira linha de entrada contém um único inteiro positivo N (1 < N <= 105) Este é o número de linhas de entrada que vem logo a seguir. As próximas N linhas conterão, cada uma delas, um valor inteiro não negativo.

Saída
Apresente todos os valores lidos na entrada segundo a ordem apresentada acima. Cada número deve ser impresso em uma linha, conforme exemplo abaixo.

Exemplo de Entrada	
10
4
32
34
543
3456
654
567
87
6789
98

Exemplo de Saída
4
32
34
98
654
3456
6789
567
543
87

*/

#include <stdlib.h>
#include <stdio.h>

int comp(const void *a, const void *b)
{
    int A = *(int *)a, B = *(int *)b;

    if (A % 2 == 0)
        if (B % 2 == 0)
            return A - B;
        else
            return -1;
    else if (B % 2 == 0)
        return 1;
    else
        return B - A;
}

int main()
{
    int n, numeros[100000];

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &numeros[i]);
    }

    qsort(numeros, n, sizeof(int), comp);

    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", numeros[i]);
    }

    return 0;
}