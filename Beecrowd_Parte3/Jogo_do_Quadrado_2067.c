#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Leitura do retângulo
    int retangulo[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &retangulo[i][j]);
        }
    }

    // Leitura do número de consultas
    int Q;
    scanf("%d", &Q);
    int consultas[Q];
    for (int i = 0; i < Q; i++) {
        scanf("%d", &consultas[i]);
    }

    // Processamento de cada consulta
    for (int q = 0; q < Q; q++) {
        int S = consultas[q];
        int encontrouProdutoNaoZero = 0; // 0: falso, 1: verdadeiro

        // Iterar sobre todos os possíveis quadrados SxS no retângulo
        for (int i = 0; i <= N - S; i++) {
            for (int j = 0; j <= M - S; j++) {
                // Calcular o produto dos elementos do quadrado SxS
                long long produto = 1;
                for (int di = 0; di < S; di++) {
                    for (int dj = 0; dj < S; dj++) {
                        produto *= retangulo[i + di][j + dj];
                        if (produto == 0) {
                            // Se encontrou um quadrado com produto zero, interrompe o cálculo
                            di = S; // sai do loop di
                            dj = S; // sai do loop dj
                        }
                    }
                }

                // Verificar se o produto foi diferente de zero
                if (produto != 0) {
                    encontrouProdutoNaoZero = 1;
                    break;
                }
            }
            if (encontrouProdutoNaoZero) {
                break;
            }
        }

        // Saída para essa consulta
        if (encontrouProdutoNaoZero) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
