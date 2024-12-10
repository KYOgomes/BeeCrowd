#include <stdio.h>
#include <string.h>

#define MAX_TEAMS 100

// Estrutura para armazenar os dados de cada time
typedef struct {
    char nome[21];
    int pontos;
} Time;

// Função para encontrar o índice de um time no vetor de times
int indexOf(Time times[], int numTimes, char nome[]) {
    for (int i = 0; i < numTimes; i++) {
        if (strcmp(times[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1; // Time não encontrado
}

int main() {
    int N; // número de times
    Time times[MAX_TEAMS];

    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        // Leitura dos times e suas pontuações iniciais
        for (int i = 0; i < N; i++) {
            scanf("%s %d", times[i].nome, &times[i].pontos);
        }

        // Processamento dos jogos da última rodada
        int numJogos = N / 2;
        for (int i = 0; i < numJogos; i++) {
            char timeA[21], timeB[21];
            int golsA, golsB;
            scanf("%s %d-%d %s", timeA, &golsA, &golsB, timeB);

            // Encontrar os índices dos times no vetor
            int idxA = indexOf(times, N, timeA);
            int idxB = indexOf(times, N, timeB);

            // Atualizar pontuações conforme o resultado do jogo
            if (golsA > golsB) {
                times[idxA].pontos += golsA * 3 + 5; // 3 pontos por gol + 5 pontos pela vitória
                times[idxB].pontos += golsB * 3; // 3 pontos por gol
            } else if (golsA < golsB) {
                times[idxA].pontos += golsA * 3; // 3 pontos por gol
                times[idxB].pontos += golsB * 3 + 5; // 3 pontos por gol + 5 pontos pela vitória
            } else {
                times[idxA].pontos += golsA * 3; // 3 pontos por gol
                times[idxB].pontos += golsB * 3; // 3 pontos por gol
            }
        }

        // Encontrar o time com maior pontuação (o campeão)
        int idxCampeao = 0;
        for (int i = 1; i < N; i++) {
            if (times[i].pontos > times[idxCampeao].pontos) {
                idxCampeao = i;
            }
        }

        // Determinar a saída conforme especificado
        if (strcmp(times[idxCampeao].nome, "Sport") == 0) {
            printf("O Sport foi o campeao com %d pontos :D\n", times[idxCampeao].pontos);
        } else {
            printf("O Sport nao foi o campeao. O time campeao foi o %s com %d pontos :(\n", times[idxCampeao].nome, times[idxCampeao].pontos);
        }
        printf("\n"); // linha em branco após cada caso de teste
    }

    return 0;
}