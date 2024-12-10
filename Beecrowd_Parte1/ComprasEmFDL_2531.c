#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int precos[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &precos[i]);
        }

        int Q;
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++) {
            int op, x, y;
            scanf("%d %d %d", &op, &x, &y);
            if (op == 1) {
                // Alteração de preço
                precos[x - 1] = y;
            } else if (op == 2) {
                // Consulta
                int maxPreco = precos[x - 1];
                int minPreco = precos[x - 1];
                for (int j = x; j < y; j++) {
                    maxPreco = maxPreco > precos[j] ? maxPreco : precos[j];
                    minPreco = minPreco < precos[j] ? minPreco : precos[j];
                }
                printf("%d\n", maxPreco - minPreco);
            }
        }
    }

    return 0;
}
