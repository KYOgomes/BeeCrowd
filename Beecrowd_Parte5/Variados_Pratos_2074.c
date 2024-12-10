#include <stdio.h>

#define MAX_N 100
#define MAX_K 6
#define MOD 1000000007

long long dp[MAX_N][MAX_N];

void calculate_valid_permutations(int N, int K) {
    // Initialize dp array
    for (int i = 0; i < N; ++i) {
        dp[0][i] = 1; // All single element permutations are valid
    }

    // Fill dp array for lengths 2 to N
    for (int len = 1; len < N; ++len) {
        for (int j = 0; j < N; ++j) {
            dp[len][j] = 0;
            for (int k = j - K; k <= j + K; ++k) {
                if (k >= 0 && k < N) {
                    dp[len][j] += dp[len - 1][k];
                    dp[len][j] %= MOD;
                }
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);

        // Calculate valid permutations
        calculate_valid_permutations(N, K);

        // Sum all dp[N-1][j] for 0 <= j < N
        long long result = 0;
        for (int j = 0; j < N; ++j) {
            result += dp[N - 1][j];
            result %= MOD;
        }

        // Print the result
        printf("%lld\n", result);
    }

    return 0;
}
