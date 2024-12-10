#include <stdio.h>
#include <limits.h>

#define MAXN 200005

int main() {
    int N, B;

    while (scanf("%d %d", &N, &B) != EOF) {
        int notas[MAXN];
        for (int i = 0; i < N; i++) {
            scanf("%d", &notas[i]);
        }

        long long resultado = 0;

        for (int i = 0; i <= N - B; i++) {
            int minNota = INT_MAX, maxNota = INT_MIN;
            long long soma = 0;

            for (int j = i; j < i + B; j++) {
                soma += notas[j];
                if (notas[j] < minNota) {
                    minNota = notas[j];
                }
                if (notas[j] > maxNota) {
                    maxNota = notas[j];
                }
            }

            resultado += (soma - minNota - maxNota);
        }

        printf("%lld\n", resultado);
    }

    return 0;
}
