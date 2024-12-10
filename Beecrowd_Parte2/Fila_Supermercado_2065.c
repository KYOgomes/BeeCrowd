#include <stdio.h>

#define MAX_N 10005

int main() {
    int N, M;
    int vi[MAX_N], cj[MAX_N];
    
    // Leitura de N e M
    scanf("%d %d", &N, &M);
    
    // Leitura dos tempos vi
    for (int i = 0; i < N; i++) {
        scanf("%d", &vi[i]);
    }
    
    // Leitura dos números de itens cj
    for (int i = 0; i < M; i++) {
        scanf("%d", &cj[i]);
    }
    
    // Vetor para armazenar o tempo em que cada funcionário estará livre
    int tempo_livre[MAX_N] = {0};
    
    // Variável para guardar o tempo total
    long long tempo_total = 0;
    
    // Processamento de cada cliente
    for (int j = 0; j < M; j++) {
        // Encontrar o funcionário livre mais rápido
        int funcionario_mais_rapido = 0;
        for (int k = 1; k < N; k++) {
            if (tempo_livre[k] < tempo_livre[funcionario_mais_rapido]) {
                funcionario_mais_rapido = k;
            }
        }
        
        // Tempo de atendimento deste cliente pelo funcionário escolhido
        tempo_livre[funcionario_mais_rapido] += vi[funcionario_mais_rapido] * cj[j];
        
        // Atualiza o tempo total, se necessário
        if (tempo_livre[funcionario_mais_rapido] > tempo_total) {
            tempo_total = tempo_livre[funcionario_mais_rapido];
        }
    }
    
    // Imprime o tempo total necessário para atender todos os clientes
    printf("%lld\n", tempo_total);
    
    return 0;
}
