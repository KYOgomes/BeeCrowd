#include <stdio.h>

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int fibra[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &fibra[i]);
        }

        long long totalCardapios = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    if (fibra[i] > fibra[j] && fibra[j] > fibra[k]) {
                        totalCardapios++;
                    }
                }
            }
        }

        printf("%lld\n", totalCardapios);
    }

    return 0;
}
