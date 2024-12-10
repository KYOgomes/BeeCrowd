#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_N 50
#define MAX_LEN 21 // 20 characters + null terminator

// Função para contar as diferenças entre duas strings de assinatura
int countDifferences(char *original, char *present) {
    int len = strlen(original);
    int differences = 0;
    
    for (int i = 0; i < len; i++) {
        char c1 = original[i];
        char c2 = present[i];
        
        // Consider upper to lower and lower to upper as differences
        if ((isupper(c1) && islower(c2)) || (islower(c1) && isupper(c2))) {
            differences++;
        }
    }
    
    return differences;
}

int main() {
    int N, M;
    
    while (1) {
        scanf("%d", &N);
        
        if (N == 0) {
            break;
        }
        
        // Arrays para armazenar nomes e assinaturas
        char nomes[MAX_N][MAX_LEN];
        char assinaturas[MAX_N][MAX_LEN];
        
        // Lê os nomes e assinaturas originais
        for (int i = 0; i < N; i++) {
            scanf("%s", nomes[i]);
            scanf("%s", assinaturas[i]);
        }
        
        scanf("%d", &M);
        
        int falsas = 0;
        
        // Lê os nomes e assinaturas na lista de presença
        for (int i = 0; i < M; i++) {
            char nome[MAX_LEN], assinatura[MAX_LEN];
            scanf("%s", nome);
            scanf("%s", assinatura);
            
            // Procura a assinatura original correspondente ao nome na lista de presença
            int encontrado = 0;
            for (int j = 0; j < N; j++) {
                if (strcmp(nomes[j], nome) == 0) {
                    // Encontrou o aluno, compara as assinaturas
                    int diffs = countDifferences(assinaturas[j], assinatura);
                    
                    // Se houver mais de uma diferença, considera falsa
                    if (diffs > 1) {
                        falsas++;
                    }
                    
                    encontrado = 1;
                    break;
                }
            }
            
            // Se o aluno não estiver na lista original, apenas ignora
        }
        
        // Imprime o número de assinaturas falsas encontradas para este caso de teste
        printf("%d\n", falsas);
    }
    
    return 0;
}
