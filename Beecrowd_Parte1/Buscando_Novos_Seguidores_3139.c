#include <stdio.h>
#include <math.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int Di[30];
    for (int i = 0; i < 30; i++) {
        scanf("%d", &Di[i]);
    }

    // Calcular a média dos últimos 30 dias
    int soma = 0;
    for (int i = 0; i < 30; i++) {
        soma += Di[i];
    }
    int avg30 = (int) ceil((double) soma / 30);

    // Calcular o número de dias necessários
    int days = 0;
    if (N >= M) {
        days = 0; // N já é maior ou igual a M
    } else {
        days = (int) ceil((double) (M - N) / avg30);
    }

    // Imprimir o resultado
    printf("%d\n", days);

    return 0;
}
