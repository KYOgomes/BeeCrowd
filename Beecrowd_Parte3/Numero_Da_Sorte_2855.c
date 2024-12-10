#include <stdio.h>
#include <stdlib.h>

int is_lucky(int *sequence, int N, int M) {
    int index = -1;
    for (int i = 0; i < N; i++) {
        if (sequence[i] == M) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return 0;
    }

    int step = 2;
    while (index >= step) {
        for (int i = step - 1; i < N; i += step) {
            for (int j = i; j < N - 1; j++) {
                sequence[j] = sequence[j + 1];
            }
            N--;
            i--;
        }
        index = -1;
        for (int i = 0; i < N; i++) {
            if (sequence[i] == M) {
                index = i;
                break;
            }
        }
        step++;
    }

    return index != -1;
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int *sequence = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &sequence[i]);
        }
        int M;
        scanf("%d", &M);

        if (is_lucky(sequence, N, M)) {
            printf("Y\n");
        } else {
            printf("N\n");
        }

        free(sequence);
    }

    return 0;
}