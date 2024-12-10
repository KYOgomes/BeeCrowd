#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_PARTICIPANTES 1000

// Função para comparar strings (para qsort)
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char participantes[MAX_PARTICIPANTES][MAX_LENGTH];
    char participantes_no[MAX_PARTICIPANTES][MAX_LENGTH]; // Array para participantes que disseram "NO"
    char amigo[MAX_LENGTH];
    int index = 0;
    int index_no = 0; // Índice para o array de participantes que disseram "NO"
    int i;

    while (1) {
        char entrada[MAX_LENGTH];
        scanf("%s", entrada);

        if (strcmp(entrada, "FIM") == 0) {
            break;
        }

        char nome[MAX_LENGTH];
        char status[MAX_LENGTH];
        sscanf(entrada, "%s %s", nome, status);

        if (strcmp(status, "YES") == 0) {
            // Verifica se o nome já está na lista de participantes YES
            int encontrado = 0;
            for (i = 0; i < index; i++) {
                if (strcmp(participantes[i], nome) == 0) {
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                strcpy(participantes[index], nome);
                if (strlen(nome) > strlen(amigo)) {
                    strcpy(amigo, nome);
                }
                index++;
            }
        } else {
            // Verifica se o nome já está na lista de participantes NO
            int encontrado = 0;
            for (i = 0; i < index_no; i++) {
                if (strcmp(participantes_no[i], nome) == 0) {
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                strcpy(participantes_no[index_no], nome);
                index_no++;
            }
        }
    }

    // Ordena os participantes YES lexicograficamente
    qsort(participantes, index, sizeof(participantes[0]), compare);

    // Imprime os participantes YES
    printf("Participantes que disseram YES:\n");
    for (i = 0; i < index; i++) {
        printf("%s\n", participantes[i]);
    }

    // Imprime os participantes NO
    printf("\nParticipantes que disseram NO:\n");
    for (i = 0; i < index_no; i++) {
        printf("%s\n", participantes_no[i]);
    }

    // Imprime o amigo do Habay
    printf("\nAmigo do Habay:\n");
    printf("%s\n", amigo);

    return 0;
}
