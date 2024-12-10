#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    
    while (scanf("%d %d", &N, &M) != EOF) {
        // Leitura do campo inicial
        int campo[N][M];
        int cumsum[N+1][M+1]; // matriz cumulativa
        
        // Inicializa campo e cumsum
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= M; ++j) {
                cumsum[i][j] = 0;
            }
        }
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                scanf("%d", &campo[i][j]);
                cumsum[i+1][j+1] = campo[i][j] + cumsum[i][j+1] + cumsum[i+1][j] - cumsum[i][j];
            }
        }
        
        // Leitura das operações
        int Q;
        scanf("%d", &Q);
        
        for (int q = 0; q < Q; ++q) {
            int R, I1, J1, I2, J2;
            scanf("%d %d %d %d %d", &R, &I1, &J1, &I2, &J2);
            
            if (R == 0) {
                // Movimento de jogador de (I1, J1) para (I2, J2)
                // Convertendo de 1-based para 0-based
                int old_i = I1 - 1, old_j = J1 - 1;
                int new_i = I2 - 1, new_j = J2 - 1;
                
                // Atualiza campo e cumsum
                int delta = campo[old_i][old_j]; // vai de 0 para 1
                campo[old_i][old_j] = 0;
                campo[new_i][new_j] = 1;
                
                // Atualiza cumsum usando a diferença
                for (int i = new_i + 1; i <= N; ++i) {
                    for (int j = new_j + 1; j <= M; ++j) {
                        cumsum[i][j] += delta;
                    }
                }
                
            } else if (R == 1) {
                // Consulta de região entre (I1, J1) e (I2, J2)
                // Convertendo de 1-based para 0-based
                int top_i = I1 - 1, top_j = J1 - 1;
                int bot_i = I2, bot_j = J2;
                
                // Calcula quantidade de jogadores na região usando cumsum
                int total = cumsum[bot_i][bot_j]
                          - cumsum[bot_i][top_j]
                          - cumsum[top_i][bot_j]
                          + cumsum[top_i][top_j];
                
                printf("%d\n", total);
            }
        }
    }
    
    return 0;
}
