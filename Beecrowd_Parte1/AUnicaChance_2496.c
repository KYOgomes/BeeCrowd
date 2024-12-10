#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Número de casos de teste
    
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m); // Tamanho da string s
        
        char s[m+1]; // String s (mais 1 para o '\0')
        scanf("%s", s); // Leitura da string s
        
        int trocas = 0;
        for (int j = 0; j < m; j++) {
            char expectedChar = 'A' + j;
            if (s[j] != expectedChar) {
                trocas++;
            }
        }
        
        if (trocas < 3) {
            printf("There are the chance.\n");
        } else {
            printf("There aren't the chance.\n");
        }
    }
    
    return 0;
}
