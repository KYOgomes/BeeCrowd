#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100005

typedef struct FenwickTree {
    int size;
    int tree[MAX_N];
} FenwickTree;

void fenwickTree_init(FenwickTree *ft, int size) {
    ft->size = size;
    for (int i = 1; i <= size; i++) {
        ft->tree[i] = 0;
    }
}

void fenwickTree_update(FenwickTree *ft, int index, int delta) {
    while (index <= ft->size) {
        ft->tree[index] += delta;
        index += index & -index;
    }
}

int fenwickTree_query(FenwickTree *ft, int index) {
    int sum = 0;
    while (index > 0) {
        sum += ft->tree[index];
        index -= index & -index;
    }
    return sum;
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int athletes[N + 1];
        for (int i = 1; i <= N; i++) {
            scanf("%d", &athletes[i]);
        }

        FenwickTree fenwickTree;
        fenwickTree_init(&fenwickTree, N);

        long long totalHighFives = 0;

        for (int i = 1; i <= N; i++) {
            int athleteNumber = athletes[i];
            totalHighFives += fenwickTree_query(&fenwickTree, N) - fenwickTree_query(&fenwickTree, athleteNumber);
            fenwickTree_update(&fenwickTree, athleteNumber, 1);
        }

        printf("%lld\n", totalHighFives);
    }

    return 0;
}
