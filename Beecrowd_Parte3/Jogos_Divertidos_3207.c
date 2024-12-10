#include <stdio.h>

// Função para determinar o vencedor para um caso de teste
char* determineWinner(double X, double F[], int K) {
    // Verifica se o tamanho atual do planeta é menor ou igual a 1 gob
    if (X <= 1.0) {
        // Se já está menor ou igual a 1, Nils ganha porque foi a última jogada válida
        return "Nils";
    }

    // Verifica se há alguma jogada vencedora para Nils
    for (int i = 0; i < K; i++) {
        double novoTamanho = X * F[i];
        if (novoTamanho <= 1.0) {
            return "Nils";
        }
    }

    // Se não houver jogada vencedora para Nils, Mikael ganha
    return "Mikael";
}

int main() {
    int N; // número de casos de teste
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        double X; // tamanho inicial do planeta
        int K; // número de armas-FATOR disponíveis
        scanf("%lf %d", &X, &K);

        double F[K]; // array para armazenar os valores das armas-FATOR
        for (int j = 0; j < K; j++) {
            scanf("%lf", &F[j]);
        }

        // Determina o vencedor para o caso de teste atual
        char* winner = determineWinner(X, F, K);
        printf("%s\n", winner);
    }

    return 0;
}
