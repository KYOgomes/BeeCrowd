/*
Sua tarefa é escrever um programa que realiza uma simples Codificação Run-Length, como descrita nas regras abaixo. Qualquer sequencia entre 2 e 9 caracteres idênticos é codificada por dois caracteres. O primeiro caractere é a largura da sequência, representada por um dos caracteres entre 2 a 9. O segundo caractere é o valor do caractere repetido. Uma sequência de mais de 9 caracteres identicos repetidos é resolvida com primeiro codificando 9 caracteres, depois os caracteres restantes.

Qualquer sequência de caracteres que não contém repetições consecutivas de qualquer caracteres é representada por um caractere '1' seguido da sequência de caracteres e terminado com outro '1'. Se um '1' aparecer como parte da sequencia, ele será terminado com um '1', tendo então dois caracteres '1' como saída.
Entrada
A entrada consiste de letras(maiúsculas e minúsculas), digitos, espaços e pontuação. Toda linha é terminada com um caractere terminador de linha.
Saída
Cada linha da entrada é codificada separadamente como descrito acima. A nova linha no final de cada linha não é codificada, mas é passada diretamente para a saída.
Exemplo de Entrada	
AAAAAABCCCC
12344

Exemplo de Saída
6A1B14C
11123124
 */
#include <stdio.h>
#include <string.h>

void encode(char *str) {
    int len = strlen(str);
    int count = 1;
    
    for (int i = 0; i < len; ++i) {
        // Se o próximo caractere for igual ao atual, incrementa o contador
        if (str[i] == str[i + 1]) {
            count++;
        } else {
            // Caso contrário, verifica quantos caracteres foram contados
            if (count > 1 && count <= 9) {
                printf("%d%c", count, str[i]);
            } else if (count > 9) {
                printf("9%c", str[i]);
                // Chama recursivamente para codificar o restante da sequência
                encode(str + i + 1);
                return;
            } else {
                printf("1%c", str[i]);
            }
            count = 1;  // Reinicia o contador para o próximo caractere
        }
    }
    printf("\n");  // Nova linha final após codificar a linha
}

int main() {
    char line[1000];  // Assumindo que as linhas não excedem 1000 caracteres
    
    // Lê cada linha até encontrar o fim do arquivo
    while (fgets(line, sizeof(line), stdin)) {
        // Remove o caractere de nova linha do final, se presente
        line[strcspn(line, "\n")] = '\0';
        
        // Codifica a linha
        encode(line);
    }
    
    return 0;
}
