#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 80

// Struct para armazenar palavras do dicionário
typedef struct {
    char japanese[MAX_LENGTH];
    char portuguese[MAX_LENGTH];
} DictionaryEntry;

int main() {
    int T;
    scanf("%d", &T);
    getchar(); // Captura o newline após T

    while (T--) {
        int M, N;
        scanf("%d %d", &M, &N);
        getchar(); // Captura o newline após M e N

        DictionaryEntry dictionary[MAX_WORDS];

        // Lê e armazena o dicionário
        for (int i = 0; i < M; i++) {
            fgets(dictionary[i].japanese, MAX_LENGTH, stdin);
            dictionary[i].japanese[strcspn(dictionary[i].japanese, "\n")] = '\0'; // Remove a quebra de linha
            fgets(dictionary[i].portuguese, MAX_LENGTH, stdin);
            dictionary[i].portuguese[strcspn(dictionary[i].portuguese, "\n")] = '\0'; // Remove a quebra de linha
        }

        // Traduzindo e imprimindo a letra da música
        for (int i = 0; i < N; i++) {
            char line[MAX_LENGTH];
            fgets(line, MAX_LENGTH, stdin);
            line[strcspn(line, "\n")] = '\0'; // Remove a quebra de linha

            char *token = strtok(line, " ");
            int first_word = 1;

            while (token != NULL) {
                int found_translation = 0;
                for (int j = 0; j < M; j++) {
                    if (strcmp(token, dictionary[j].japanese) == 0) {
                        printf("%s", dictionary[j].portuguese);
                        found_translation = 1;
                        break;
                    }
                }

                if (!found_translation) {
                    printf("%s", token);
                }

                token = strtok(NULL, " ");
                if (token != NULL) {
                    printf(" ");
                }
            }

            printf("\n");
        }

        if (T > 0) {
            printf("\n"); // Imprime linha em branco entre instâncias
        }
    }

    return 0;
}
