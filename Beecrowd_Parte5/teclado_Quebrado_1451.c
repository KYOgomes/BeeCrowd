#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char texto[1000]; 
    char saida[1000]; 
    int pos = 0; 
    int home = 0; 

    // Enquanto houver entrada
    while (fgets(texto, sizeof(texto), stdin) != NULL) 
    {
        int tam = strlen(texto);
        
        saida[0] = '\0';
        pos = 0;

        for (int i = 0; i < tam; i++) {
            if (texto[i] == '[') {
                home = 1;
                pos = 0;
            }
            else if (texto[i] == ']') {
                home = 0;
                pos = strlen(saida);
            }
            else {
                if (home) {
                    memmove(saida + pos + 1, saida + pos, strlen(saida + pos) + 1); 
                    saida[pos] = texto[i];
                    pos++; 
                } else {
                    saida[pos] = texto[i];
                    pos++; 
                }
            }
        }
        printf("%s\n", saida);
    }

    return 0;
}