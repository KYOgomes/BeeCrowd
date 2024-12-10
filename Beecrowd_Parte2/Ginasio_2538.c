#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um analógimôn
typedef struct {
    int PC; // Poder de Combate
    int NA; // Número de Ataques
} Analogimon;

// Função de comparação para ordenar os analógimôns por PC
int compare(const void *a, const void *b) {
    return ((Analogimon *)a)->PC - ((Analogimon *)b)->PC;
}

int main() {
    int IP, M;
    while (scanf("%d %d", &IP, &M) != EOF) {
        Analogimon ginasio[100005]; // Ginásio com no máximo 100005 analógimôns
        int numAnalogimons = 0; // Número atual de analógimôns no ginásio

        for (int i = 0; i < M; i++) {
            int PC, NA;
            scanf("%d %d", &PC, &NA);

            // Verifica quantos analógimôns já estão no ginásio com PC no intervalo [PC-IP, PC+IP]
            int count = 0;
            for (int j = 0; j < numAnalogimons; j++) {
                if (abs(ginasio[j].PC - PC) <= IP) {
                    count++;
                }
            }

            // Se a quantidade é menor ou igual ao NA, adiciona o analógimôn ao ginásio
            if (count <= NA) {
                ginasio[numAnalogimons].PC = PC;
                ginasio[numAnalogimons].NA = NA;
                numAnalogimons++;
            }
        }

        printf("%d\n", numAnalogimons);
    }

    return 0;
}
