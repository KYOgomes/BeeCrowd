#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Palavra
typedef struct {
    char nome[101];
    int valor;
} Palavra;

// Função para comparar duas palavras (usada para ordenar)
int comparaPalavras(const void *a, const void *b) {
    return strcmp(((Palavra *)a)->nome, ((Palavra *)b)->nome);
}

// Função para comparar duas strings (usada para ordenar)
int comparaStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Função recursiva para somar valores
int soma(Palavra *palavras, int m, char **descricao, int n, int total) {
    if (m == 0 || n == 0) {
        return total;
    } else if (strcmp(palavras[0].nome, descricao[0]) == 0) {
        return soma(palavras, m, descricao + 1, n - 1, total + palavras[0].valor);
    } else if (strcmp(palavras[0].nome, descricao[0]) < 0) {
        return soma(palavras + 1, m - 1, descricao, n, total);
    } else {
        return soma(palavras, m, descricao + 1, n - 1, total);
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    Palavra *palavras = (Palavra *)malloc(m * sizeof(Palavra));
    for (int i = 0; i < m; i++) {
        scanf("%s %d", palavras[i].nome, &palavras[i].valor);
    }

    qsort(palavras, m, sizeof(Palavra), comparaPalavras);

    for (int i = 0; i < n; i++) {
        char entrada[101];
        char **descricao = NULL;
        int descSize = 0;

        // Lê a descrição
        while (scanf("%s", entrada), strcmp(entrada, ".") != 0) {
            descSize++;
            descricao = (char **)realloc(descricao, descSize * sizeof(char *));
            descricao[descSize - 1] = (char *)malloc((strlen(entrada) + 1) * sizeof(char));
            strcpy(descricao[descSize - 1], entrada);
        }

        qsort(descricao, descSize, sizeof(char *), comparaStrings);

        // Calcula e imprime a soma
        printf("%d\n", soma(palavras, m, descricao, descSize, 0));

        for (int j = 0; j < descSize; j++) {
            free(descricao[j]);
        }
        free(descricao);
    }

    free(palavras);

    return 0;
}
