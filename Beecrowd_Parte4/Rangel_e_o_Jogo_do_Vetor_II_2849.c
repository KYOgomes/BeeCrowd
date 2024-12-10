#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int numbers[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < Q; i++) {
        int L, R, K, G, D;
        scanf("%d %d %d %d %d", &L, &R, &K, &G, &D);
        L--; R--; K--;

        int subArraySize = R - L + 1;
        int subArray[subArraySize];
        for (int j = 0; j < subArraySize; j++) {
            subArray[j] = numbers[L + j];
        }

        qsort(subArray, subArraySize, sizeof(int), compare);

        int Kth = subArray[K];
        int count = 0;
        for (int j = 0; j < subArraySize; j++) {
            if (subArray[j] == Kth) {
                count++;
            }
        }

        printf("%d %d ", Kth, count);
        if (abs(G - count) < abs(D - count)) {
            printf("G\n");
        } else if (abs(G - count) > abs(D - count)) {
            printf("D\n");
        } else {
            printf("E\n");
        }
    }

    return 0;
}