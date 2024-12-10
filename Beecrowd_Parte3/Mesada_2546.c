#include <stdio.h>

int main() {
    int N, Q;
    while (scanf("%d %d", &N, &Q) != EOF) {
        int mesada[105];
        for (int i = 1; i <= N; i++) {
            scanf("%d", &mesada[i]);
        }

        for (int i = 0; i < Q; i++) {
            char op;
            int x, y;
            scanf(" %c %d %d", &op, &x, &y);

            if (op == 'A') {
                int v;
                scanf("%d", &v);
                for (int j = x; j <= y; j++) {
                    mesada[j] += v;
                }
            } else if (op == 'C') {
                int maxMesada = -1;
                int neto = -1;
                for (int j = x; j <= y; j++) {
                    if (mesada[j] > maxMesada) {
                        maxMesada = mesada[j];
                        neto = j;
                    }
                }
                printf("%d\n", neto);
            }
        }
    }

    return 0;
}
