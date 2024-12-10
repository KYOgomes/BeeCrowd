#include <stdio.h>
#include <stdlib.h>

// Função de comparação para ordenação decrescente
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int t;
    scanf("%d", &t); // número de casos de teste
    
    while (t--) {
        int n;
        scanf("%d", &n); // número de coretos
        
        int X[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &X[i]); // leitura das quantidades de vírus em cada coreto
        }
        
        // Ordena o vetor X em ordem decrescente
        qsort(X, n, sizeof(int), compare);
        
        // Calcula o número máximo de vírus que podem ser eliminados
        long long totalVirusEliminated = 0;
        for (int i = 0; i < n; i++) {
            totalVirusEliminated += (long long)X[i] * (n - i);
        }
        
        // Imprime o resultado para o caso de teste atual
        printf("%lld\n", totalVirusEliminated);
    }
    
    return 0;
}
