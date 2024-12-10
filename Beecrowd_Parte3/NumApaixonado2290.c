#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100005

int compare(const void *a, const void *b) {
    return (*(long long int *)a - *(long long int *)b);
}

int main() {
    int N;
    long long int A[MAX_N];
    
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        
        for (int i = 0; i < N; ++i) {
            scanf("%lld", &A[i]);
        }
        
        // Ordena o vetor de números
        qsort(A, N, sizeof(long long int), compare);
        
        // Encontra os números apaixonados
        long long int apaixonado1 = 0, apaixonado2 = 0;
        bool found_first = false;
        
        for (int i = 0; i < N; ++i) {
            if (i + 1 < N && A[i] == A[i + 1]) {
                // Par encontrado, pula para o próximo par
                i++;
            } else {
                // Encontrou um número solitário
                if (!found_first) {
                    apaixonado1 = A[i];
                    found_first = true;
                } else {
                    apaixonado2 = A[i];
                    break;  // Encontrou os dois números, podemos parar
                }
            }
        }
        
        // Imprime os números apaixonados em ordem crescente
        printf("%lld %lld\n", apaixonado1, apaixonado2);
    }
    
    return 0;
}
