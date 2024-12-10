#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Função para calcular a soma de um subarray máximo e o seu tamanho
void encontrar_maximo_subarray(int* contas, int inicio, int fim, int* soma_maxima, int* comprimento_maximo) {
    int soma_atual = 0;
    int melhor_soma = INT_MIN;
    int comprimento_atual = 0;
    int melhor_comprimento = 0;

    for (int i = inicio; i <= fim; i++) {
        soma_atual += contas[i];
        comprimento_atual++;

        if (soma_atual > melhor_soma || (soma_atual == melhor_soma && comprimento_atual > melhor_comprimento)) {
            melhor_soma = soma_atual;
            melhor_comprimento = comprimento_atual;
        }

        if (soma_atual < 0) {
            soma_atual = 0;
            comprimento_atual = 0;
        }
    }

    *soma_maxima = melhor_soma;
    *comprimento_maximo = melhor_comprimento;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        int* contas = (int*)malloc((N + 1) * sizeof(int));
        
        for (int i = 1; i <= N; i++) {
            scanf("%d", &contas[i]);
        }

        int Q;
        scanf("%d", &Q);

        for (int i = 0; i < Q; i++) {
            int A, B;
            scanf("%d %d", &A, &B);

            int soma_maxima, comprimento_maximo;
            encontrar_maximo_subarray(contas, A, B, &soma_maxima, &comprimento_maximo);
            printf("%d %d\n", soma_maxima, comprimento_maximo);
        }

        free(contas);
    }

    return 0;
}
