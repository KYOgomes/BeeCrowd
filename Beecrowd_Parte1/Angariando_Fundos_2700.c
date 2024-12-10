#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um candidato
typedef struct {
    int B; // Beleza
    int F; // Fortuna
    int D; // Doação
} Candidato;

// Função de comparação para qsort (ordenação)
int comparar(const void *a, const void *b) {
    Candidato *c1 = (Candidato *)a;
    Candidato *c2 = (Candidato *)b;

    // Ordena por beleza decrescente
    if (c1->B != c2->B)
        return c2->B - c1->B;
    
    // Em caso de empate na beleza, ordena por fortuna decrescente
    if (c1->F != c2->F)
        return c2->F - c1->F;
    
    // Em caso de empate na beleza e fortuna, ordena por doação decrescente
    return c2->D - c1->D;
}

int main() {
    int N;
    scanf("%d", &N);

    Candidato candidatos[N];
    
    // Leitura dos candidatos
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &candidatos[i].B, &candidatos[i].F, &candidatos[i].D);
    }

    // Ordenação dos candidatos conforme a estratégia descrita
    qsort(candidatos, N, sizeof(Candidato), comparar);

    // Variável para armazenar a soma máxima das doações
    long long somaMaxima = 0;
    int prevB = -1; // Beleza do convidado anterior
    int prevF = -1; // Fortuna do convidado anterior

    // Seleção dos candidatos que não causam discussões
    for (int i = 0; i < N; i++) {
        if (candidatos[i].B >= prevB && candidatos[i].F >= prevF) {
            somaMaxima += candidatos[i].D;
            prevB = candidatos[i].B; // Atualiza a beleza do convidado anterior
            prevF = candidatos[i].F; // Atualiza a fortuna do convidado anterior
        }
    }

    // Imprime o resultado final
    printf("%lld\n", somaMaxima * 2);

    return 0;
}