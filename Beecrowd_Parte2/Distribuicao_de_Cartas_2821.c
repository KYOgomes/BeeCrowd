#include <stdio.h>
#include <string.h>

int main() {
    int nCartas, nJogadores;
    scanf("%d %d", &nCartas, &nJogadores);

    int cartas[60];
    for (int i = 0; i < nCartas; i++) {
        char carta[3];
        scanf("%s", carta);
        if (strcmp(carta, "A") == 0) {
            cartas[i] = 1;
        } else if (strcmp(carta, "J") == 0) {
            cartas[i] = 11;
        } else if (strcmp(carta, "Q") == 0) {
            cartas[i] = 12;
        } else if (strcmp(carta, "K") == 0) {
            cartas[i] = 13;
        } else {
            cartas[i] = atoi(carta);
        }
    }

    int soma[10] = {0};
    int count[10] = {0};
    int j = 0;
    for (int i = 0; i < nCartas; i++) {
        soma[j] += cartas[i];
        count[j]++;
        if (j < nJogadores - 1 && soma[j] + cartas[i + 1] > soma[j]) {
            j++;
        }
    }

    int maxCount = 0;
    int maxSoma = 0;
    for (int i = 0; i < nJogadores; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
        }
        if (soma[i] > maxSoma) {
            maxSoma = soma[i];
        }
    }

    printf("%d %d\n", maxCount, maxSoma);

    return 0;
}