#include <stdio.h>

#define MAXN 500010

int BIT[MAXN], indices[MAXN], result[MAXN], N;

void update(int idx, int delta) {
    while (idx <= N) {
        BIT[idx] += delta;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &indices[i]);
    }

    for (int i = N - 1; i >= 0; i--) {
        int idx = indices[i];
        result[i] = query(idx - 1);
        update(idx, 1);
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}