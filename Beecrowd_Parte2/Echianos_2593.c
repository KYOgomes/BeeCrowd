#include <stdio.h>
#include <string.h>

int main() {
    char texto[10001]; // Considerando o texto com no máximo 10.000 caracteres
    char palavras[128][51]; // Array de palavras com no máximo 128 palavras de até 50 caracteres cada
    
    // Leitura do texto
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0'; // Remove o newline lido por fgets
    
    // Leitura da quantidade de palavras
    int qtdPalavras;
    scanf("%d", &qtdPalavras);
    getchar(); // Consumir o caractere newline após o número de palavras
    
    // Leitura das palavras
    for (int i = 0; i < qtdPalavras; i++) {
        scanf("%s", palavras[i]);
    }
    
    // Processamento das palavras
    for (int i = 0; i < qtdPalavras; i++) {
        char *posicao = strstr(texto, palavras[i]);
        if (posicao != NULL) {
            // Imprimir a primeira posição encontrada
            while (posicao != NULL) {
                int pos = posicao - texto;
                printf("%d ", pos);
                posicao = strstr(posicao + 1, palavras[i]);
            }
        } else {
            // Se a palavra não foi encontrada, imprimir -1
            printf("-1");
        }
        printf("\n");
    }
    
    return 0;
}
