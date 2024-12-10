#include <stdio.h>
#include <string.h>

#define MAXN 200
#define MAXSUM 20000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int T, N, gifts[2*MAXN+1], totalSum, dp[MAXSUM+1], halfSum;

    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        totalSum = 0;

        for (int i = 0; i < 2*N; i++) {
            scanf("%d", &gifts[i]);
            totalSum += gifts[i];
        }

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int i = 0; i < 2*N; i++) {
            for (int j = totalSum; j >= gifts[i]; j--) {
                dp[j] = max(dp[j], dp[j - gifts[i]]);
            }
        }

        halfSum = totalSum / 2;
        while (!dp[halfSum]) {
            halfSum--;
        }

        printf("%d\n", totalSum - 2*halfSum);
    }

    return 0;
}