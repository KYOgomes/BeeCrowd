#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int dp[105][105];
char grid[105][105];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        scanf("%s", grid[i] + 1);
    }

    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                continue; // Pular para o próximo j
            }
            if (grid[i][j] != '0') {
                for (int k = 0; k < j; k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
            if (grid[i][j] != '1') {
                for (int k = j + 1; k <= M; k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= M; i++) {
        result = (result + dp[N][i]) % MOD;
    }
    printf("%d\n", result + 6);

    return 0;
}
