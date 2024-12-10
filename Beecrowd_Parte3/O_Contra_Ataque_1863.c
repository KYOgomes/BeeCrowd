#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 5000

typedef struct Soldier {
    int x, y;
    int strongerCount;
    int* strongerThan;
} Soldier;

Soldier soldiers[MAXN];
int dp[MAXN];
int N, M;

void addStrongerThan(int u, int v) {
    soldiers[u].strongerThan = realloc(soldiers[u].strongerThan, (soldiers[u].strongerCount + 1) * sizeof(int));
    soldiers[u].strongerThan[soldiers[u].strongerCount] = v;
    soldiers[u].strongerCount++;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &soldiers[i].x, &soldiers[i].y);
        soldiers[i].strongerCount = 0;
        soldiers[i].strongerThan = NULL;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addStrongerThan(u, v);
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
    }

    int maxSoldiers = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < soldiers[i].strongerCount; j++) {
            int v = soldiers[i].strongerThan[j];
            if (soldiers[v].x > soldiers[i].x && soldiers[v].y > soldiers[i].y) {
                dp[v] = max(dp[v], dp[i] + 1);
            }
        }
        maxSoldiers = max(maxSoldiers, dp[i]);
    }

    printf("%d\n", maxSoldiers);

    for (int i = 1; i <= N; i++) {
        free(soldiers[i].strongerThan);
    }

    return 0;
}
