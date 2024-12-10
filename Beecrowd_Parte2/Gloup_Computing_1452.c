#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPS 101
#define MAX_NAME_LENGTH 21

int main() {
    int N, M, i, j, k;
    char serverApps[200][MAX_APPS][MAX_NAME_LENGTH];
    char clientApps[200][MAX_APPS][MAX_NAME_LENGTH];
    int serverAppCounts[200], clientAppCounts[200];

    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;

        // Leitura dos servidores
        for (i = 0; i < N; i++) {
            scanf("%d", &serverAppCounts[i]);
            for (j = 0; j < serverAppCounts[i]; j++) {
                scanf("%s", serverApps[i][j]);
            }
        }

        // Leitura dos clientes
        for (i = 0; i < M; i++) {
            scanf("%d", &clientAppCounts[i]);
            for (j = 0; j < clientAppCounts[i]; j++) {
                scanf("%s", clientApps[i][j]);
            }
        }

        // Contagem das conexões únicas
        int totalConnections = 0;
        for (i = 0; i < M; i++) { // para cada cliente
            for (j = 0; j < N; j++) { // para cada servidor
                int isConnected = 0;
                for (k = 0; k < clientAppCounts[i]; k++) {
                    int l;
                    for (l = 0; l < serverAppCounts[j]; l++) {
                        if (strcmp(clientApps[i][k], serverApps[j][l]) == 0) {
                            isConnected = 1;
                            break;
                        }
                    }
                    if (isConnected) break;
                }
                if (isConnected) totalConnections++;
            }
        }

        // Imprime resultado para este caso de teste
        printf("%d\n", totalConnections);
    }

    return 0;
}