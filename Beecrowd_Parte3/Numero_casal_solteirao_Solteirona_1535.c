#include <stdio.h>
#include <math.h>

// Verifica se o número N é um "número casal quadrado" e imprime a e b se for
// Caso contrário, imprime "Bachelor Number." ou "Spinster Number."
void processSingleNumber(int n) {
    if (n < 0) {
        printf("Bachelor Number.\n");
        return;
    }

    // Verifica se é possível representar n como a^2 - b^2
    int a = 1;
    while (1) {
        int a2 = a * a;
        int b2 = a2 - n;
        if (b2 >= 0) {
            int b = (int) sqrt(b2);
            if (b * b == b2 && a > b) {
                printf("%d %d\n", a, b);
                return;
            }
        }
        a++;
        if (a2 > n) {
            break;
        }
    }

    if (n % 2 == 0) {
        printf("Bachelor Number.\n");
    } else {
        printf("Spinster Number.\n");
    }
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        processSingleNumber(n);
    }

    return 0;
}