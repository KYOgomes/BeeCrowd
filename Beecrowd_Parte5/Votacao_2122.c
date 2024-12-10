#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 100
#define MAX_VOTES 100000

typedef struct {
    int indice;
    int votos_primeiro;
    int votos_total;
} Candidato;

// Função de comparação para qsort (ordenação)
int compare(const void *a, const void *b) {
    Candidato *c1 = (Candidato *)a;
    Candidato *c2 = (Candidato *)b;

    // Ordena primeiro pelo número total de votos decrescente
    if (c1->votos_total != c2->votos_total) {
        return c2->votos_total - c1->votos_total;
    }
    
    // Em caso de empate nos votos totais, ordena pelos votos no primeiro lugar decrescente
    if (c1->votos_primeiro != c2->votos_primeiro) {
        return c2->votos_primeiro - c1->votos_primeiro;
    }
    
    // Em caso de empate nos votos totais e no primeiro lugar, ordena pelo índice crescente
    return c1->indice - c2->indice;
}

int main() {
    int N, K, V;
    int i, j, k;

    while (scanf("%d %d %d", &N, &K, &V) == 3) {
        // Inicializa a lista de candidatos
        Candidato candidatos[MAX_CANDIDATES];
        for (i = 0; i < K; i++) {
            candidatos[i].indice = i + 1;
            candidatos[i].votos_primeiro = 0;
            candidatos[i].votos_total = 0;
        }

        // Lê os votos dos eleitores
        for (i = 0; i < N; i++) {
            int Li;
            scanf("%d", &Li);

            for (j = 0; j < Li; j++) {
                int voto;
                scanf("%d", &voto);
                if (voto >= 1 && voto <= K) {
                    candidatos[voto - 1].votos_total++;
                    if (j == 0) {
                        candidatos[voto - 1].votos_primeiro++;
                    }
                }
            }
        }

        // Ordena os candidatos conforme as regras especificadas
        qsort(candidatos, K, sizeof(Candidato), compare);

        // Determina quantos candidatos serão eleitos
        int eleitos = 0;
        for (i = 0; i < K; i++) {
            if (eleitos < V && candidatos[i].votos_total > 0) {
                eleitos++;
            } else {
                candidatos[i].votos_total = 0;
            }
        }

        // Imprime os índices dos candidatos eleitos ordenados
        for (i = 0; i < K; i++) {
            if (candidatos[i].votos_total > 0) {
                printf("%d ", candidatos[i].indice);
            }
        }
        printf("\n");
    }

    return 0;
}
