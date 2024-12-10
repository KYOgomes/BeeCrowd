#include <stdio.h>
#include <string.h>

// Função para decodificar um único código Morse
void decodeMorse(char *morse) {
    // Mapeamento de Morse para caracteres
    const char *morseTable[] = {"=.===", "===.=.=.=", "===.=.===.=", "===.=.=", "=", "=.=.===.=",
 "===.===.=", "=.=.=.=","=.=", "=.===.===.===", "===.=.===", "=.===.=.=",
 "===.===", "===.=", "===.===.===", "=.===.===.=", "===.===.=.===",
 "=.===.=", "=.=.=", "===", "=.=.===", "=.=.=.===", "=.===.===",
 "===.=.=.===", "===.=.===.===", "===.===.=.="}; // espaço

    // Variável para armazenar a mensagem decodificada
    char decoded[1001];
    decoded[0] = '\0'; // Inicializa a string vazia

    char *token;
    token = strtok(morse, "......."); // Separa por sete pontos para palavras

    while (token != NULL) {
        char *letter;
        letter = strtok(token, "..."); // Separa por três pontos para letras
        
        while (letter != NULL) {
            // Verifica se letter é um espaço em branco
            if (strcmp(letter, "") == 0) {
                strcat(decoded, " ");
            } else {
                // Procura letter no morseTable
                int found = 0;
                for (int i = 0; i < 27; i++) {
                    if (strcmp(letter, morseTable[i]) == 0) {
                        char ch = 'a' + i;
                        strncat(decoded, &ch, 1); // Adiciona a letra correspondente
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcat(decoded, "?"); // Caractere não reconhecido
                }
            }

            letter = strtok(NULL, "..."); // Próxima letra
        }
        
        strcat(decoded, " "); // Adiciona espaço entre palavras
        token = strtok(NULL, "......."); // Próxima palavra
    }

    // Remove o último espaço adicionado antes de imprimir
    decoded[strlen(decoded) - 1] = '\0';

    // Imprime a mensagem decodificada
    printf("%s\n", decoded);
}

int main() {
    int t;
    scanf("%d", &t); // Número de casos de teste
    
    getchar(); // Consume newline after t
    
    for (int i = 0; i < t; i++) {
        char morse[1001];
        fgets(morse, 1001, stdin); // Lê o código Morse
        morse[strcspn(morse, "\n")] = '\0'; // Remove o newline
        
        decodeMorse(morse); // Decodifica e imprime a mensagem
    }
    
    return 0;
}
