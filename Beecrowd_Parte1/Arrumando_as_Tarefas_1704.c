#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N, H;
    while (scanf("%d %d", &N, &H) != EOF) {
        int v[N + 1], t[N + 1];
        for (int i = 1; i <= N; ++i) {
            scanf("%d %d", &v[i], &t[i]);
        }

        int dp[N + 1][H + 1];
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= H; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (t[i] <= j) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        printf("%d\n", dp[N][H]);
    }
    return 0;
}
