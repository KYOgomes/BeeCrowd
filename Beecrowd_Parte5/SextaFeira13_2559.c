#include <stdio.h>

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int sequencia[200005];
        for (int i = 1; i <= N; i++) {
            scanf("%d", &sequencia[i]);
        }

        int Q;
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++) {
            int op, x, y, z, v;
            scanf("%d", &op);

            if (op == 1) {
                scanf("%d %d", &x, &v);
                sequencia[x] = v;
            } else if (op == 2) {
                scanf("%d %d %d %d", &x, &y, &z, &v);
                for (int j = x; j <= y; j++) {
                    if (sequencia[j] == z) {
                        sequencia[j] = v;
                    }
                }
            } else if (op == 3) {
                scanf("%d %d", &x, &y);
                int soma = 0;
                for (int j = x; j <= y; j++) {
                    soma += sequencia[j];
                }
                printf("%d\n", soma);
            }
        }
    }

    return 0;
}
