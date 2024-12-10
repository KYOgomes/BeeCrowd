#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 10000

// Estrutura para armazenar os números
typedef struct {
    int numero;
    int modulo;
} Numero;

// Função de comparação para qsort
int compara(const void *a, const void *b) {
    Numero *num1 = (Numero *)a;
    Numero *num2 = (Numero *)b;

    if (num1->modulo != num2->modulo) {
        return num1->modulo - num2->modulo;
    } else {
        // Mesmo módulo, aplicar as regras adicionais
        if (abs(num1->numero) % 2 != abs(num2->numero) % 2) {
            // Se um é ímpar e o outro é par, o ímpar vem antes
            return (abs(num1->numero) % 2) ? -1 : 1;
        } else {
            // Ambos são pares ou ambos são ímpares
            if (abs(num1->numero) % 2 == 1) {
                // Ambos são ímpares
                return num2->numero - num1->numero; // maior ímpar vem antes
            } else {
                // Ambos são pares
                return num1->numero - num2->numero; // menor par vem antes
            }
        }
    }
}

int main() {
    int N, M;
    Numero numeros[MAX_N];

    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) {
            break;
        }

        // Leitura dos números e cálculo dos módulos
        for (int i = 0; i < N; i++) {
            scanf("%d", &numeros[i].numero);
            numeros[i].modulo = abs(numeros[i].numero) % M;
        }

        // Ordenação dos números de acordo com as regras
        qsort(numeros, N, sizeof(Numero), compara);

        // Impressão do resultado para este caso de teste
        printf("%d %d\n", N, M);
        for (int i = 0; i < N; i++) {
            printf("%d\n", numeros[i].numero);
        }
    }

    return 0;
}
