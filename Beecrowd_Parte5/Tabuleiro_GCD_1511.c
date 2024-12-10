#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001 // 500 (máximo |x| ou |y|) * 2 + 1 (para incluir o zero)

int grid[MAX_SIZE][MAX_SIZE];

// Função para calcular o GCD (Maior Divisor Comum)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}

// Função para realizar a operação SET
void set(int x, int y, int d, int value) {
    for (int dx = -d; dx <= d; ++dx) {
        for (int dy = -d; dy <= d; ++dy) {
            int nx = x + dx;
            int ny = y + dy;
            if (abs(nx) <= 500 && abs(ny) <= 500) {
                grid[nx + 500][ny + 500] = value;
            }
        }
    }
}

// Função para realizar a operação QUERY
int query(int x, int y, int d) {
    int result = -1;
    for (int dx = -d; dx <= d; ++dx) {
        for (int dy = -d; dy <= d; ++dy) {
            int nx = x + dx;
            int ny = y + dy;
            if (abs(nx) <= 500 && abs(ny) <= 500 && grid[nx + 500][ny + 500] != 0) {
                if (result == -1) {
                    result = grid[nx + 500][ny + 500];
                } else {
                    result = gcd(result, grid[nx + 500][ny + 500]);
                }
            }
        }
    }
    return result == -1 ? 0 : result;
}

int main() {
    char op[10];
    int x, y, d, value;
    int Q;

    while (scanf("%d", &Q) == 1) {
        while (Q--) {
            scanf("%s %d %d %d", op, &x, &y, &d);
            if (op[0] == 'S') {
                scanf("%d", &value);
                set(x, y, d, value);
            } else if (op[0] == 'Q') {
                printf("%d\n", query(x, y, d));
            }
        }
    }

    return 0;
}