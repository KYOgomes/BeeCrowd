#include <stdio.h>
#include <string.h>

int contarAssuntosPendentes(char *S) {
    int pendentes = 0;
    int balance = 0;
    
    for (int i = 0; S[i] != '\0'; i++) {
        if (S[i] == '(') {
            balance++;
        } else if (S[i] == ')') {
            if (balance > 0) {
                balance--;
            } else {
                pendentes++;
            }
        }
    }
    
    pendentes += balance; // Adiciona os pendentes que não foram fechados
    
    return pendentes;
}

int main() {
    char S[100001];
    fgets(S, sizeof(S), stdin);
    
    // Remover o caractere de nova linha no final da string
    S[strcspn(S, "\n")] = '\0';
    
    int pendentes = contarAssuntosPendentes(S);
    
    if (pendentes > 0) {
        printf("Ainda temos %d assunto(s) pendente(s)!\n", pendentes);
    } else {
        printf("Partiu RU!\n");
    }
    
    return 0;
}
