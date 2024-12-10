#include <stdio.h>
//saida errada
int main() {
    while (1) {
        int N, M;
        scanf("%d %d", &N, &M);

        if (N == 0 && M == 0) {
            break;
        }

        int swaps[M];
        for (int i = 0; i < M; i++) {
            scanf("%d", &swaps[i]);
        }

        int sequence[N];
        for (int i = 0; i < N; i++) {
            sequence[i] = N - i;
        }

        for (int i = 0; i < M; i++) {
            int pos = N - 1 - swaps[i];
            int temp = sequence[pos];
            for (int j = pos; j < N - 1; j++) {
                sequence[j] = sequence[j + 1];
            }
            sequence[N - 1] = temp;
        }

        for (int i = 0; i < N; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d", sequence[i]);
        }
        printf("\n");
    }

    return 0;
}