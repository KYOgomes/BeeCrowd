#include <stdio.h>
#include <stdlib.h>

// Função para comparar dois inteiros (necessária para qsort)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int t; // número de casos de teste
    scanf("%d", &t);

    for (int caseNum = 1; caseNum <= t; caseNum++) {
        int n; // número de lojas
        scanf("%d", &n);

        int positions[n]; // array para armazenar as posições das lojas

        // Lê as posições das lojas
        for (int i = 0; i < n; i++) {
            scanf("%d", &positions[i]);
        }

        // Ordena as posições das lojas
        qsort(positions, n, sizeof(int), compare);

        // Calcula a menor distância entre a primeira e a última posição
        int minDistance = positions[n-1] - positions[0];

        // Imprime a menor distância para este caso de teste
        printf("%d\n", minDistance * 2);
    }

    return 0;
}
