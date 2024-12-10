#include <stdio.h>
#include <string.h>

// Função para calcular o Shortest Common Supersequence (SCS)
void calculateSCS(char s1[], char s2[], char result[]) {
    int m = strlen(s1);
    int n = strlen(s2);
    
    // Tabela para armazenar o tamanho do SCS de s1[0..i-1] e s2[0..j-1]
    int dp[m+1][n+1];
    
    // Preenche a tabela dp
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }
    
    // Tamanho do SCS é dp[m][n]
    int scsLength = dp[m][n];
    
    // Constrói o SCS usando a tabela dp
    int index = scsLength; // índice para o resultado
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            result[--index] = s1[i-1];
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            result[--index] = s1[i-1];
            i--;
        } else {
            result[--index] = s2[j-1];
            j--;
        }
    }
    
    // Adiciona os caracteres restantes de s1 e s2
    while (i > 0) {
        result[--index] = s1[i-1];
        i--;
    }
    while (j > 0) {
        result[--index] = s2[j-1];
        j--;
    }
    
    // Imprime o SCS
    printf("%s\n", result);
}

int main() {
    char s1[101], s2[101];
    int testNumber = 1;
    
    while (1) {
        scanf("%s", s1);
        if (s1[0] == '#') break;
        scanf("%s", s2);
        
        char result[201]; // para armazenar o SCS
        calculateSCS(s1, s2, result);
        
        // Imprime o formato especificado
        printf("Teste %d\n", testNumber++);
        printf("%s\n\n", result);
    }
    
    return 0;
}
