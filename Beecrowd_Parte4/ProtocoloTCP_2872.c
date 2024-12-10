#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para comparar strings (necessária para qsort)
int comparar_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    char linha[1001]; // Tamanho máximo de cada linha é 1000 caracteres + 1 para o terminador null

    while (1) {
        scanf("%d", &n);
        getchar(); // Consumir o newline após o número

        if (n == 0) {
            break;
        }

        char *lista[100]; // Supondo um máximo de 100 linhas de texto
        int num_linhas = 0;

        fgets(linha, sizeof(linha), stdin);
        linha[strlen(linha) - 1] = '\0'; // Remover o newline do final da linha, se existir

        while (strcmp(linha, "0") != 0) {
            lista[num_linhas] = strdup(linha); // Copiar a linha para a lista
            num_linhas++;
            fgets(linha, sizeof(linha), stdin);
            linha[strlen(linha) - 1] = '\0'; // Remover o newline do final da linha, se existir
        }

        // Ordenar as linhas em ordem lexicográfica
        qsort(lista, num_linhas, sizeof(char *), comparar_strings);

        // Imprimir as linhas ordenadas
        for (int i = 0; i < num_linhas; i++) {
            printf("%s\n", lista[i]);
            free(lista[i]); // Liberar memória alocada por strdup
        }

        printf("\n");
    }

    return 0;
}
