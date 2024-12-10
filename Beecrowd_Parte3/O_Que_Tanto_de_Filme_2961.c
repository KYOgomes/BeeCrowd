#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int erros[4] = {0}; // Índices 0 a 3 para as categorias 1 a 4
    
    for (int ano = 0; ano < N; ano++) {
        // Lendo os palpites
        char palpites[4][101]; // Array para os palpites
        for (int i = 0; i < 4; i++) {
            scanf("%s", palpites[i]);
        }
        
        // Lendo os vencedores
        char vencedores[4][101]; // Array para os vencedores
        for (int i = 0; i < 4; i++) {
            scanf("%s", vencedores[i]);
        }
        
        // Comparando palpites com vencedores
        for (int i = 0; i < 4; i++) {
            if (strcmp(palpites[i], vencedores[i]) != 0) {
                erros[i]++;
            }
        }
    }
    
    // Determinando as categorias com mais erros
    int primeira = 1;
    for (int i = 0; i < 4; i++) {
        if (erros[i] > 0) {
            if (!primeira) {
                printf(" ");
            }
            printf("%d", i + 1); // Índice + 1 para a categoria
            primeira = 0;
        }
    }
    printf("\n");
    
    return 0;
}
