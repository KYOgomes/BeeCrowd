#include <stdio.h>
#include <stdlib.h>

#define MAXN 1001

int prefix_sum[MAXN][MAXN];

void update_prefix_sum(int n, int x, int y) {
    for (int i = x; i <= n; i += (i & -i)) {
        for (int j = y; j <= n; j += (j & -j)) {
            prefix_sum[i][j]++;
        }
    }
}

int query_prefix_sum(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
        for (int j = y; j > 0; j -= (j & -j)) {
            sum += prefix_sum[i][j];
        }
    }
    return sum;
}

int query_region(int i1, int j1, int i2, int j2) {
    return query_prefix_sum(i2, j2) - query_prefix_sum(i1 - 1, j2) - query_prefix_sum(i2, j1 - 1) + query_prefix_sum(i1 - 1, j1 - 1);
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        // Initialize the prefix sum matrix
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                prefix_sum[i][j] = 0;
            }
        }

        // Read initial board state and populate the prefix sum matrix
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int value;
                scanf("%d", &value);
                if (value == 1) {
                    update_prefix_sum(n, i, j);
                }
            }
        }

        // Process each round
        for (int k = 0; k < m; k++) {
            int i, j;
            int I1, J1, I2, J2;

            // Read the new azeitona addition
            scanf("%d %d", &i, &j);
            update_prefix_sum(n, i, j);

            // Read the query for the sub-region
            scanf("%d %d %d %d", &I1, &J1, &I2, &J2);
            int result = query_region(I1, J1, I2, J2);
            printf("%d\n", result);
        }
    }

    return 0;
}
