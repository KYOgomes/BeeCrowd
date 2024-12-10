#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 201 // máximo de caracteres por linha, incluindo o '\0'
#define MAX_WORDS 5000      // máximo de palavras distintas a serem armazenadas

// Função para comparar strings (necessária para qsort)
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *words[MAX_WORDS]; // array de ponteiros para armazenar as palavras
    int numWords = 0;
    
    while (fgets(line, sizeof(line), stdin) != NULL) {
        char *token = strtok(line, " \t\r\n"); // dividir linha em palavras
        
        while (token != NULL) {
            // converter palavra para minúsculas
            for (int i = 0; token[i] != '\0'; i++) {
                token[i] = tolower(token[i]);
            }
            
            // adicionar palavra ao array de palavras (se ainda não estiver cheio)
            if (numWords < MAX_WORDS) {
                words[numWords] = strdup(token);
                numWords++;
            }
            
            token = strtok(NULL, " \t\r\n");
        }
    }
    
    // Ordenar as palavras alfabeticamente
    qsort(words, numWords, sizeof(char *), compareStrings);
    
    // Imprimir palavras distintas
    for (int i = 0; i < numWords; i++) {
        printf("%s\n", words[i]);
        free(words[i]); // liberar memória alocada por strdup
    }
    
    return 0;
}
