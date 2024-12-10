#include <stdio.h>

int perm[20], target[20], swaps[20], n;

int solve(int idx) {
    if (idx == n - 1) {
        for (int i = 0; i < n; i++) {
            if (perm[i] != target[i]) {
                return 0;
            }
        }
        return 1;
    }
    for (int i = idx; i < n; i++) {
        swap(idx, i);
        swaps[idx] = i;
        if (solve(idx + 1)) {
            return 1;
        }
        swap(idx, i);
    }
    return 0;
}

void swap(int i, int j) {
    int temp = perm[i];
    perm[i] = perm[j];
    perm[j] = temp;
}

int main() {
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            perm[i] = i + 1;
            scanf("%d", &target[i]);
        }
        if (solve(0)) {
            printf("%d", n - 1);
            for (int i = 0; i < n - 1; i++) {
                printf(" %d", swaps[i] + 1);
            }
            printf("\n");
        } else {
            printf("No solution\n");
        }
    }
    return 0;
}