#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

// Função personalizada para leitura até EOF
char scanff(int *a) {
    return scanf("%d", a);
}

int main() {
    int iter;
    
    while (scanff(&iter) != EOF) {
        int vet[101] = {0}; // Vetor para contagem de intervalos
        int i, j, inicio, fim;
        
        // Lê os intervalos e atualiza o vetor vet
        for (i = 0; i < iter; i++) {
            scanf("%d %d", &inicio, &fim);
            for (j = inicio; j <= fim; j++) {
                vet[j]++;
            }
        }
        
        // Lê o número a ser buscado
        scanff(&j);
        
        // Verifica se o número está presente no vetor vet
        if (vet[j] > 0) {
            // Encontra o intervalo onde o número j foi encontrado
            int start = -1, end = -1;
            int acl = 0;
            
            for (i = 1; i <= 100; i++) {
                if (vet[i] > 0) {
                    acl += vet[i];
                    if (i == j) {
                        start = acl - vet[i] + 1;
                        end = acl;
                        break;
                    }
                }
            }
            
            printf("%d found from %d to %d\n", j, start, end);
        } else {
            printf("%d not found\n", j);
        }
    }
    
    return 0;
}
