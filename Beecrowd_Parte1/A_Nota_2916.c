#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Função de comparação para o min-heap (para usar com qsort)
int cmpfunc(const void *a, const void *b) {
    return (*(long *)b - *(long *)a);
}

// Função para encontrar a soma das K-ésimas maiores notas
long long findKthLargestSum(long long notas[], int N, int K) {
    // Ordenar as notas em ordem decrescente
    qsort(notas, N, sizeof(long long), cmpfunc);
    
    // Calcular a soma das K maiores notas
    long long sum = 0;
    for (int i = 0; i < K; i++) {
        sum = (sum + notas[i]) % MOD;
    }
    
    return sum;
}

int main() {
    int N, K;
    
    // Ler N e K
    while (scanf("%d %d", &N, &K) == 2) {
        // Ler as N notas
        long long notas[N];
        for (int i = 0; i < N; i++) {
            scanf("%lld", &notas[i]);
        }
        
        // Encontrar a soma das K-ésimas maiores notas
        long long resultado = findKthLargestSum(notas, N, K);
        
        // Imprimir o resultado
        printf("%lld\n", resultado);
    }
    
    return 0;
}
