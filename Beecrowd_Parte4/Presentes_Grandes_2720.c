#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    long long volume;
} Present;

int compare(const void *a, const void *b) {
    Present *presentA = (Present *)a;
    Present *presentB = (Present *)b;
    if (presentB->volume != presentA->volume) {
        return presentB->volume - presentA->volume;
    } else {
        return presentA->id - presentB->id;
    }
}

int compareInt(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int T, N, K, H, W, L;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d %d", &N, &K);
        Present presents[N];

        for (int i = 0; i < N; i++) {
            scanf("%d %d %d %d", &presents[i].id, &H, &W, &L);
            presents[i].volume = (long long)H * W * L;
        }

        qsort(presents, N, sizeof(Present), compare);

        int ids[K];
        for (int i = 0; i < K; i++) {
            ids[i] = presents[i].id;
        }

        qsort(ids, K, sizeof(int), compareInt);

        for (int i = 0; i < K; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d", ids[i]);
        }

        printf("\n");
    }

    return 0;
}