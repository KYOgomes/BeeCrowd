#include <stdio.h>

#define MAX_N 100005

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Array para armazenar as pilhas de Pomekons
    int pilhas[N + 1];
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &pilhas[i]);
    }

    // Processamento das alterações nas pilhas
    for (int i = 0; i < M; ++i) {
        int X, Y, V;
        scanf("%d %d %d", &X, &Y, &V);
        
        // Aplicando a alteração diretamente nas pilhas
        for (int j = X; j <= Y; ++j) {
            pilhas[j] = V;
        }
    }

    // Verificação se Dabriel pode garantir a vitória
    int odd_count = 0;
    for (int i = 1; i <= N; ++i) {
        if (pilhas[i] % 2 != 0) {
            odd_count++;
        }
    }

    // Determinando se é possível para Dabriel ganhar sempre
    if (odd_count % 2 == 0) {
        printf("Possivel\n");
    } else {
        printf("Impossivel\n");
    }

    return 0;
}
