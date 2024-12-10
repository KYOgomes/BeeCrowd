#include <stdio.h>
#include <stdlib.h>

#define MAX 100010

int road[MAX];

int distinctMonsters(int L, int R) {
    int monsters[51] = {0};
    int count = 0;
    for (int i = L; i <= R; i++) {
        if (monsters[road[i]] == 0) {
            monsters[road[i]] = 1;
            count++;
        }
    }
    return count;
}

int main() {
    int N, Q, M;
    scanf("%d %d %d", &N, &Q, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &road[i]);
    }
    while (Q--) {
        int type, L, R;
        scanf("%d %d %d", &type, &L, &R);
        if (type == 1) {
            printf("%d\n", distinctMonsters(L, R));
        } else {
            road[L] = R;
        }
    }
    return 0;
}