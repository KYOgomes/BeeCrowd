#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Aluno
typedef struct {
    char nome[15]; // Assumindo que o nome tem no máximo 14 caracteres (incluindo '\0')
    int habilidade;
} Aluno;

// Função de comparação para qsort (ordenação por habilidade decrescente)
int comparar(const void *a, const void *b) {
    Aluno *alunoA = (Aluno *)a;
    Aluno *alunoB = (Aluno *)b;
    return alunoB->habilidade - alunoA->habilidade;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    getchar(); // Consumir o newline após os inteiros

    // Array de alunos
    Aluno alunos[N];

    // Leitura dos alunos
    for (int i = 0; i < N; i++) {
        scanf("%s %d", alunos[i].nome, &alunos[i].habilidade);
    }

    // Ordenar os alunos por habilidade (decrescente)
    qsort(alunos, N, sizeof(Aluno), comparar);

    // Arrays de times
    char times[T][N][15]; // times[T][N][15] para armazenar até N alunos com nomes de até 14 caracteres
    int numAlunosPorTime[T]; // Contador de alunos por time

    // Inicializar o contador de alunos por time
    for (int i = 0; i < T; i++) {
        numAlunosPorTime[i] = 0;
    }

    // Distribuir os alunos nos times
    for (int i = 0; i < N; i++) {
        int timeIndex = i % T; // Selecionar o time alternadamente
        strcpy(times[timeIndex][numAlunosPorTime[timeIndex]], alunos[i].nome);
        numAlunosPorTime[timeIndex]++;
    }

    // Ordenar os nomes dos alunos nos times
    for (int i = 0; i < T; i++) {
        qsort(times[i], numAlunosPorTime[i], sizeof(times[i][0]), (const void *)strcmp);
    }

    // Imprimir os times
    for (int i = 0; i < T; i++) {
        printf("Time %d\n", i + 1);
        for (int j = 0; j < numAlunosPorTime[i]; j++) {
            printf("%s\n", times[i][j]);
        }
        printf("\n"); // linha em branco após cada time
    }

    return 0;
}
