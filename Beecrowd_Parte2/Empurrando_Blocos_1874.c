#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 105
#define MAX_P 105
#define MAX_F 1005

int pilhas[MAX_H][MAX_P];
int alturas[MAX_P];
int fila[MAX_F];

void processaEntrada(int H, int P, int F) {
    // Ler as pilhas
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < P; j++) {
            scanf("%d", &pilhas[i][j]);
        }
    }

    // Ler a fila
    for (int i = 0; i < F; i++) {
        scanf("%d", &fila[i]);
    }

    // Calcular a altura atual de cada pilha
    for (int j = 0; j < P; j++) {
        alturas[j] = 0;
        for (int i = 0; i < H; i++) {
            if (pilhas[i][j] == 1) {
                alturas[j]++;
            }
        }
    }

    // Processar a fila de blocos
    for (int i = 0; i < F; i++) {
        int bloco = fila[i];
        for (int j = P - 1; j >= 0; j--) {
            if (alturas[j] < H) {
                pilhas[alturas[j]][j] = bloco;
                alturas[j]++;
                break;
            }
        }
    }

    // Imprimir o resultado
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < P; j++) {
            if (j > 0) printf(" ");
            printf("%d", pilhas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int H, P, F;

    while (scanf("%d %d %d", &H, &P, &F) == 3) {
        if (H == 0 && P == 0 && F == 0) {
            break;
        }

        processaEntrada(H, P, F);
        printf("\n");
    }

    return 0;
}
