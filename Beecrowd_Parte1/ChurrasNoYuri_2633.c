#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar cada peça de carne
typedef struct {
    char nome[21]; // Nome da carne (máximo de 20 caracteres + 1 para '\0')
    int validade;  // Data de validade da carne
} Carne;

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    Carne *carneA = (Carne *)a;
    Carne *carneB = (Carne *)b;
    return carneA->validade - carneB->validade;
}

int main() {
    int N;

    while (scanf("%d", &N) != EOF) {
        if (N == 0) break; // Condição de saída

        Carne carnes[N];

        // Leitura das carnes
        for (int i = 0; i < N; i++) {
            scanf("%s %d", carnes[i].nome, &carnes[i].validade);
        }

        // Ordenação das carnes pela data de validade
        qsort(carnes, N, sizeof(Carne), comparar);

        // Saída das carnes ordenadas
        for (int i = 0; i < N; i++) {
            printf("%s", carnes[i].nome);
            if (i < N - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }

    return 0;
}
