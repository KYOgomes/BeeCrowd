#include <stdio.h>

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    int array[N + 1];

    for (int i = 1; i <= N; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < Q; i++) {
        int operation;
        scanf("%d", &operation);
        if (operation == 1) {
            int X, W;
            scanf("%d %d", &X, &W);
            array[X] = W;
        } else if (operation == 2) {
            int X, Y, W;
            scanf("%d %d %d", &X, &Y, &W);
            int count = 0;
            for (int j = X; j <= Y; j++) {
                if (array[j] != W) {
                    count++;
                }
            }
            printf("%d\n", count);
        }
    }

    return 0;
}