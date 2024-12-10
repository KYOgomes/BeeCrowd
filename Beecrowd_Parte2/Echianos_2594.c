#include <stdio.h>
#include <string.h>

// Função para buscar a palavra no texto e imprimir as posições
void searchWordInText(const char *text, const char *word) {
    int text_len = strlen(text);
    int word_len = strlen(word);
    int i, j;
    int found = 0;

    // Percorre o texto em busca da palavra
    for (i = 0; i <= text_len - word_len; i++) {
        // Verifica se encontrou o início da palavra
        if (text[i] == word[0]) {
            // Verifica se a palavra completa está presente a partir desta posição
            for (j = 1; j < word_len; j++) {
                if (text[i + j] != word[j]) {
                    break;
                }
            }
            // Se j == word_len, encontrou a palavra
            if (j == word_len) {
                if (found > 0) {
                    printf(" ");
                }
                printf("%d", i);
                found++;
            }
        }
    }

    // Se não encontrou nenhuma ocorrência, imprime -1
    if (found == 0) {
        printf("-1");
    }
    printf("\n");
}

int main() {
    int q;
    scanf("%d", &q);
    getchar(); // Captura o caractere de nova linha após o número de casos

    while (q--) {
        char text[129]; // Máximo de 128 caracteres + 1 para o \0
        char word[129]; // Máximo de 128 caracteres + 1 para o \0

        // Leitura do texto
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0'; // Remove o \n no final da string

        // Leitura da palavra
        fgets(word, sizeof(word), stdin);
        word[strcspn(word, "\n")] = '\0'; // Remove o \n no final da string

        // Busca e impressão das posições da palavra no texto
        searchWordInText(text, word);
    }

    return 0;
}
