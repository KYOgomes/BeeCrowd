#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//tudo errado 
#define MAX_PRESENTES 100

// Estrutura para representar um presente
typedef struct {
    char nome[101];
    double preco;
    int preferencia;
} Presente;

// Função de comparação para qsort
int compara_presentes(const void *a, const void *b) {
    Presente *presenteA = (Presente *)a;
    Presente *presenteB = (Presente *)b;

    // Ordenar por preferência decrescente
    if (presenteA->preferencia != presenteB->preferencia) {
        return presenteB->preferencia - presenteA->preferencia;
    }
    // Ordenar por preço crescente
    else if (presenteA->preco != presenteB->preco) {
        return (presenteA->preco > presenteB->preco) ? 1 : -1;
    }
    // Ordenar por nome alfabeticamente
    else {
        return strcmp(presenteA->nome, presenteB->nome);
    }
}

int main() {
    char nomeDono[101];
    int Q;
    Presente presentes[MAX_PRESENTES];

    while (scanf("%s %d", nomeDono, &Q) == 2 && Q > 0) {
        // Leitura dos presentes
        for (int i = 0; i < Q; i++) {
            scanf("%s %lf %d", presentes[i].nome, &presentes[i].preco, &presentes[i].preferencia);
        }

        // Ordenação dos presentes
        qsort(presentes, Q, sizeof(Presente), compara_presentes);

        // Impressão conforme especificado
        printf("Lista de %s\n", nomeDono);
        for (int i = 0; i < Q; i++) {
            printf("%s - R$%.2f\n", presentes[i].nome, presentes[i].preco);
        }
        printf("\n"); // linha em branco após cada lista
    }

    return 0;
}
