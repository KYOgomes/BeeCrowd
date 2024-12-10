#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[21];
    int idade;
} Duende;

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    Duende *duendeA = (Duende *)a;
    Duende *duendeB = (Duende *)b;
    if (duendeB->idade != duendeA->idade) {
        return duendeB->idade - duendeA->idade;  // Decrescente por idade
    } else {
        return strcmp(duendeA->nome, duendeB->nome);  // Crescente por nome
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    Duende duendes[N];
    
    // Lendo os nomes e idades dos duendes
    for (int i = 0; i < N; i++) {
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
    }
    
    // Ordenando a lista de duendes
    qsort(duendes, N, sizeof(Duende), comparar);
    
    // Número de times
    int T = N / 3;
    
    // Formando e imprimindo os times
    for (int i = 0; i < T; i++) {
        printf("Time %d\n", i + 1);
        printf("%s %d\n", duendes[i].nome, duendes[i].idade);
        printf("%s %d\n", duendes[i + T].nome, duendes[i + T].idade);
        printf("%s %d\n", duendes[i + 2 * T].nome, duendes[i + 2 * T].idade);
        printf("\n");
    }
    
    return 0;
}
