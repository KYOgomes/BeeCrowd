#include <stdio.h>

#define MAX_N 500

int prefixBlack[MAX_N][MAX_N];
int prefixWhite[MAX_N][MAX_N];

int main() {
    int N, P;
    scanf("%d %d", &N, &P);

    // Leitura das pedras pretas
    for (int i = 0; i < P; i++) {
        int L, C;
        scanf("%d %d", &L, &C);
        L--; // 1-based to 0-based index
        C--; // 1-based to 0-based index
        prefixBlack[L][C]++;
    }

    // Leitura das pedras brancas
    for (int i = 0; i < P; i++) {
        int L, C;
        scanf("%d %d", &L, &C);
        L--; // 1-based to 0-based index
        C--; // 1-based to 0-based index
        prefixWhite[L][C]++;
    }

    // Construção das matrizes de prefixo
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > 0) {
                prefixBlack[i][j] += prefixBlack[i - 1][j];
                prefixWhite[i][j] += prefixWhite[i - 1][j];
            }
            if (j > 0) {
                prefixBlack[i][j] += prefixBlack[i][j - 1];
                prefixWhite[i][j] += prefixWhite[i][j - 1];
            }
            if (i > 0 && j > 0) {
                prefixBlack[i][j] -= prefixBlack[i - 1][j - 1];
                prefixWhite[i][j] -= prefixWhite[i - 1][j - 1];
            }
        }
    }

    // Contagem das sub-áreas
    int blackAreas = 0;
    int whiteAreas = 0;

    // Percorre todas as possíveis sub-áreas
    for (int size = 1; size <= N; size++) {
        for (int i = 0; i <= N - size; i++) {
            for (int j = 0; j <= N - size; j++) {
                int totalBlack = prefixBlack[i + size - 1][j + size - 1];
                int totalWhite = prefixWhite[i + size - 1][j + size - 1];

                if (i > 0) {
                    totalBlack -= prefixBlack[i - 1][j + size - 1];
                    totalWhite -= prefixWhite[i - 1][j + size - 1];
                }
                if (j > 0) {
                    totalBlack -= prefixBlack[i + size - 1][j - 1];
                    totalWhite -= prefixWhite[i + size - 1][j - 1];
                }
                if (i > 0 && j > 0) {
                    totalBlack += prefixBlack[i - 1][j - 1];
                    totalWhite += prefixWhite[i - 1][j - 1];
                }

                if (totalBlack > 0 && totalWhite == 0) {
                    blackAreas++;
                } else if (totalBlack == 0 && totalWhite > 0) {
                    whiteAreas++;
                }
            }
        }
    }

    // Saída do resultado
    printf("%d %d\n", blackAreas, whiteAreas);

    return 0;
}
