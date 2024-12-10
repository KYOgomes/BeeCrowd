#include <stdio.h>
#include <stdlib.h>

#define MAX 101

int grid[MAX][MAX];

// Função para calcular a soma dentro da distância Manhattan d a partir de (x, y)
int manhattanSum(int x, int y, int d) {
    int sum = 0;
    // Percorrendo as células dentro do quadrado manhattan de lado 2*d+1
    for (int i = x - d; i <= x + d; i++) {
        for (int j = y - (d - abs(x - i)); j <= y + (d - abs(x - i)); j++) {
            // Verificando se (i, j) está dentro dos limites da matriz
            if (i >= 0 && i < MAX && j >= 0 && j < MAX) {
                sum += grid[i][j];
            }
        }
    }
    return sum;
}

int main() {
    int q;
    while (scanf("%d", &q) == 1 && q != 0) {
        while (q--) {
            int type, x, y, d;
            scanf("%d %d %d", &type, &x, &y);
            if (type == 1) {
                grid[x][y] = 1; // Marcando como ocupada
            } else if (type == 2) {
                grid[x][y] = 0; // Marcando como livre
            } else if (type == 3) {
                scanf("%d", &d);
                int result = manhattanSum(x, y, d);
                printf("%d\n", result);
            }
        }
    }
    return 0;
}
