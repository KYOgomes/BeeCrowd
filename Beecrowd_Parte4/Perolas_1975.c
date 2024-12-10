#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_PEARLS 1000
#define MAX_NAME_LENGTH 101
#define MAX_ANSWER_LENGTH 1001

// Função para encontrar o índice de um aluno no vetor de nomes
int indexOf(char nomes[][MAX_NAME_LENGTH], int numAlunos, char nome[]) {
    for (int i = 0; i < numAlunos; i++) {
        if (strcmp(nomes[i], nome) == 0) {
            return i;
        }
    }
    return -1; // Aluno não encontrado
}

int main() {
    int P, A, R; // número de pérolas, número de alunos, número de respostas por aluno
    char pearls[MAX_PEARLS][MAX_ANSWER_LENGTH];
    char nomes[MAX_ALUNOS][MAX_NAME_LENGTH];
    int ocorrencias[MAX_ALUNOS] = {0};

    while (1) {
        scanf("%d %d %d", &P, &A, &R);
        if (P == 0 && A == 0 && R == 0) break;

        // Ler as pérolas escritas no quadro (não precisamos armazenar)
        for (int i = 0; i < P; i++) {
            scanf(" %[^\n]", pearls[i]);
        }

        // Ler os nomes dos alunos
        for (int i = 0; i < A; i++) {
            scanf(" %[^\n]", nomes[i]);

            // Ler as respostas dos alunos e contar ocorrências de "ERRO"
            for (int j = 0; j < R; j++) {
                char resposta[MAX_ANSWER_LENGTH];
                scanf(" %[^\n]", resposta);

                // Verificar se a resposta contém "ERRO"
                if (strstr(resposta, "ERRO") != NULL) {
                    ocorrencias[i]++;
                }
            }
        }

        // Encontrar o máximo de ocorrências
        int maxOcorrencias = -1;
        for (int i = 0; i < A; i++) {
            if (ocorrencias[i] > maxOcorrencias) {
                maxOcorrencias = ocorrencias[i];
            }
        }

        // Imprimir os alunos com mais ocorrências (em ordem alfabética)
        int primeiro = 1;
        for (int i = 0; i < A; i++) {
            if (ocorrencias[i] == maxOcorrencias) {
                if (!primeiro) {
                    printf(", ");
                }
                printf("%s", nomes[i]);
                primeiro = 0;
            }
        }
        printf("\n\n"); // linha em branco após cada caso de teste
    }
    return 0;
}
