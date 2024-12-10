#include <stdio.h>
#include <stdlib.h>

// Função para inicializar os times nas casas
void initializeTeams(int N, int F, int A, int B, int C, int *teams) {
    teams[0] = A % F;
    for (int i = 1; i < N; ++i) {
        teams[i] = (B * teams[i - 1] + C) % F;
    }
}

// Função para encontrar a próxima casa com o mesmo time no sentido horário
int findClockwise(int *teams, int N, int start, int team) {
    for (int i = 1; i < N; ++i) {
        int index = (start + i) % N;
        if (teams[index] == team) {
            return i;
        }
    }
    return N;
}

// Função para encontrar a próxima casa com o mesmo time no sentido anti-horário
int findCounterClockwise(int *teams, int N, int start, int team) {
    for (int i = 1; i < N; ++i) {
        int index = (start - i + N) % N;
        if (teams[index] == team) {
            return i;
        }
    }
    return N;
}

int main() {
    int N, F;
    scanf("%d %d", &N, &F);

    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    // Array para armazenar os times das casas
    int *teams = (int *)malloc(N * sizeof(int));
    initializeTeams(N, F, A, B, C, teams);

    int M;
    scanf("%d", &M);

    for (int i = 0; i < M; ++i) {
        int I, E;
        scanf("%d %d", &I, &E);
        --I; // Ajustar para índice zero

        teams[I] = E;

        int dcw = findClockwise(teams, N, I, E);
        int dccw = findCounterClockwise(teams, N, I, E);

        printf("%d %d\n", dccw, dcw);
    }

    free(teams);
    return 0;
}
