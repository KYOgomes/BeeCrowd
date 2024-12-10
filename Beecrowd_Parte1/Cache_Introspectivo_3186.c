#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int objeto;
    int proximoUso;
} CacheItem;

void atualizarProximoUso(int* acessos, int* proximoUso, int A, int atual) {
    for (int i = atual + 1; i < A; i++) {
        if (acessos[i] == acessos[atual]) {
            proximoUso[atual] = i;
            return;
        }
    }
    proximoUso[atual] = A; // Se não houver próximo uso, define como um valor fora do intervalo
}

int encontrarRemovivel(CacheItem* cache, int capacidade, int* proximoUso) {
    int removivel = 0;
    int ultimoUso = -1;
    for (int i = 0; i < capacidade; i++) {
        if (proximoUso[cache[i].objeto] > ultimoUso) {
            ultimoUso = proximoUso[cache[i].objeto];
            removivel = i;
        }
    }
    return removivel;
}

int calculaMinimoLeituras(int capacidade, int* acessos, int A) {
    if (capacidade == 0) return A;

    CacheItem* cache = (CacheItem*)malloc(capacidade * sizeof(CacheItem));
    int* proximoUso = (int*)malloc(A * sizeof(int));
    int cacheSize = 0;
    int leiturasForaDoCache = 0;

    for (int i = 0; i < A; i++) {
        atualizarProximoUso(acessos, proximoUso, A, i);
    }

    for (int i = 0; i < A; i++) {
        int obj = acessos[i];
        int encontradoNoCache = 0;

        for (int j = 0; j < cacheSize; j++) {
            if (cache[j].objeto == obj) {
                encontradoNoCache = 1;
                break;
            }
        }

        if (!encontradoNoCache) {
            leiturasForaDoCache++;
            if (cacheSize < capacidade) {
                cache[cacheSize].objeto = obj;
                cacheSize++;
            } else {
                int removivelIndex = encontrarRemovivel(cache, capacidade, proximoUso);
                cache[removivelIndex].objeto = obj;
            }
        }

        atualizarProximoUso(acessos, proximoUso, A, i);
    }

    free(cache);
    free(proximoUso);

    return leiturasForaDoCache;
}

int main() {
    int C, N, A;
    scanf("%d %d %d", &C, &N, &A);

    int* acessos = (int*)malloc(A * sizeof(int));
    for (int i = 0; i < A; i++) {
        scanf("%d", &acessos[i]);
    }

    int resultado = calculaMinimoLeituras(C, acessos, A);
    printf("%d\n", resultado);

    free(acessos);
    return 0;
}
