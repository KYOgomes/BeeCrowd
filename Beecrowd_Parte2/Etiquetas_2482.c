#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void readString(char *str) {
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove a quebra de linha
}

int main() {
    int qntEntrada = 0;
    scanf("%d", &qntEntrada);
    getchar();  // Consume newline

    char idioma[qntEntrada][MAX_LEN];
    char mensagem[qntEntrada][MAX_LEN];

    // Lendo idiomas e mensagens
    for (int i = 0; i < qntEntrada; i++) {
        readString(idioma[i]);
        readString(mensagem[i]);
    }

    int qntCrianca = 0;
    scanf("%d", &qntCrianca);
    getchar();  // Consume newline

    char nomeCrianca[qntCrianca][MAX_LEN];
    char nacionalidade[qntCrianca][MAX_LEN];

    // Lendo nomes e nacionalidades das crianças
    for (int j = 0; j < qntCrianca; j++) {
        readString(nomeCrianca[j]);
        readString(nacionalidade[j]);
    }

    // Iterando sobre cada criança
    for (int aux = 0; aux < qntCrianca; aux++) {
        printf("%s\n", nomeCrianca[aux]);

        // Verificando se há uma mensagem correspondente ao idioma da nacionalidade da criança
        for (int percorre = 0; percorre < qntEntrada; percorre++) {
            if (strcmp(nacionalidade[aux], idioma[percorre]) == 0) {
                printf("%s\n\n", mensagem[percorre]);
            }
        }
    }

    return 0;
}
