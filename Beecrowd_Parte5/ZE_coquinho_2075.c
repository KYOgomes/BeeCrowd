#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 51

char* memo[MAX_LEN][MAX_LEN * MAX_LEN];
int memo_size[MAX_LEN];

void generate_malformed_sculptures(int N) {
    if (N == 0 || memo_size[N] > 0) {
        return;
    }

    if (N == 1) {
        memo[N][memo_size[N]++] = "()";
        return;
    }

    generate_malformed_sculptures(N - 1);

    for (int i = 0; i < memo_size[N - 1]; i++) {
        char* s = (char*) malloc(MAX_LEN * sizeof(char));
        sprintf(s, "(%s)", memo[N - 1][i]);
        memo[N][memo_size[N]++] = s;
    }

    if (N > 2) {
        generate_malformed_sculptures(N - 2);
        for (int i = 0; i < memo_size[N - 2]; i++) {
            char* s = (char*) malloc(MAX_LEN * sizeof(char));
            sprintf(s, "()%s", memo[N - 2][i]);
            memo[N][memo_size[N]++] = s;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        int N, K;
        scanf("%d %d", &N, &K);

        generate_malformed_sculptures(N);

        if (K >= memo_size[N]) {
            printf("-1\n");
        } else {
            printf("%s\n", memo[N][K]);
        }
    }

    return 0;
}