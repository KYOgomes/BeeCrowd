#include <stdio.h>

#define MODULO 1000007

void calculateFibonacki(int k, int N) {
    int maxN = 2 * 100000; // Valor máximo para N conforme especificado no problema
    int fibonacki[maxN];
    
    // Preencher os primeiros k termos da sequência de Fibonacki
    for (int i = 0; i < k; i++) {
        fibonacki[i] = i; // Iniciar com os primeiros números
    }
    
    // Calcular os termos da sequência de Fibonacki até o N-ésimo termo
    for (int i = k; i < N; i++) {
        fibonacki[i] = 0;
        // Somar os k termos anteriores
        for (int j = 1; j <= k; j++) {
            fibonacki[i] = (fibonacki[i] + fibonacki[i - j]) % MODULO;
        }
    }
    
    // Imprimir o valor do N-ésimo termo da sequência de Fibonacki
    printf("%d\n", fibonacki[N-1]);
}

int main() {
    int T;
    scanf("%d", &T); // Número de casos de teste
    
    while (T--) {
        int k, N;
        scanf("%d %d", &k, &N); // Ler k e N para o caso de teste atual
        calculateFibonacki(k, N);
    }
    
    return 0;
}
