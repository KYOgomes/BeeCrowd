#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MAX_LENGTH 19 // 18 caracteres + '\0'

char nomes[2 * MAX_N][MAX_LENGTH];
char prefixos_ruas[MAX_N][MAX_LENGTH];
char prefixos_avenidas[MAX_N][MAX_LENGTH];

int main() {
    int N;
    scanf("%d", &N);
    
    // Lendo os nomes das ruas e avenidas
    for (int i = 0; i < 2 * N; ++i) {
        scanf("%s", nomes[i]);
    }
    
    // Determinando os prefixos mais curtos para as ruas
    for (int i = 0; i < N; ++i) {
        int min_length = strlen(nomes[i]);
        strncpy(prefixos_ruas[i], nomes[i], min_length + 1); // Copia incluindo o '\0'
        
        for (int j = N; j < 2 * N; ++j) {
            int k;
            for (k = 0; k < min_length; ++k) {
                if (nomes[j][k] != prefixos_ruas[i][k])
                    break;
            }
            if (k < min_length) {
                prefixos_ruas[i][k] = '\0';
                min_length = k;
            }
        }
    }
    
    // Determinando os prefixos mais curtos para as avenidas
    for (int i = N; i < 2 * N; ++i) {
        int min_length = strlen(nomes[i]);
        strncpy(prefixos_avenidas[i - N], nomes[i], min_length + 1); // Copia incluindo o '\0'
        
        for (int j = 0; j < N; ++j) {
            int k;
            for (k = 0; k < min_length; ++k) {
                if (nomes[j][k] != prefixos_avenidas[i - N][k])
                    break;
            }
            if (k < min_length) {
                prefixos_avenidas[i - N][k] = '\0';
                min_length = k;
            }
        }
    }
    
    // Calculando o número mínimo de letras nas placas
    int total_letras = 0;
    for (int i = 0; i < N; ++i) {
        total_letras += strlen(prefixos_ruas[i]);
    }
    for (int i = 0; i < N; ++i) {
        total_letras += strlen(prefixos_avenidas[i]);
    }
    
    printf("%d\n", total_letras);
    
    return 0;
}
