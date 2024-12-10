#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para comparar strings (necessária para qsort)
int comparar_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // Consumir o newline após o número

    for (int i = 0; i < n; i++) {
        char linha[1001]; // Tamanho máximo de cada linha é 1000 caracteres + 1 para o terminador null
        fgets(linha, sizeof(linha), stdin);

        // Remover o newline do final da string se existir
        if (linha[strlen(linha) - 1] == '\n') {
            linha[strlen(linha) - 1] = '\0';
        }

        // Dividir a linha em palavras
        char *palavras[100]; // Supondo um máximo de 100 palavras por linha
        int num_palavras = 0;

        char *token = strtok(linha, " ");
        while (token != NULL) {
            palavras[num_palavras++] = token;
            token = strtok(NULL, " ");
        }

        // Ordenar as palavras em ordem lexicográfica
        qsort(palavras, num_palavras, sizeof(char *), comparar_strings);

        // Imprimir palavras únicas na linha
        char ultimo[21] = ""; // Supondo um máximo de 20 caracteres por palavra + 1 para o terminador null

        for (int j = 0; j < num_palavras; j++) {
            if (strcmp(palavras[j], ultimo) != 0) {
                printf("%s ", palavras[j]);
                strcpy(ultimo, palavras[j]);
            }
        }
        
        printf("\n");
    }

    return 0;
}
