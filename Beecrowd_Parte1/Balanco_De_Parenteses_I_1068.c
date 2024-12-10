/* BALANÇO DE PARÊNTESES I

Dada uma expressão qualquer com parênteses, indique se a quantidade de parênteses está correta ou não, 
sem levar em conta o restante da expressão. Por exemplo:

a+(b*c)-2-a        está correto
(a+b*(2-c)-2+a)*2  está correto

enquanto

(a*b-(2+c)         está incorreto
2*(3-a))           está incorreto
)3+b*(2-c)(        está incorreto

Ou seja, todo parênteses que fecha deve ter um outro parênteses que abre correspondente e não pode haver parênteses que fecha sem um 
previo parenteses que abre e a quantidade total de parenteses que abre e fecha deve ser igual.

Entrada
Como entrada, haverá N expressões (1 <= N <= 10000), cada uma delas com até 1000 caracteres.

Saída
O arquivo de saída deverá ter a quantidade de linhas correspondente ao arquivo de entrada, cada uma delas contendo as palavras 
correct ou incorrect de acordo com as regras acima fornecidas.

Exemplo de Entrada	
a+(b*c)-2-a 
(a+b*(2-c)-2+a)*2 
(a*b-(2+c) 
2*(3-a))  
)3+b*(2-c)( 

Exemplo de Saída
correct
correct
incorrect
incorrect
incorrect
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool verifica(char* expression) {
    int count = 0; // contador de parênteses abertos

    for (int i = 0; i < strlen(expression); i++) {
        char caractere = expression[i];
        if (caractere == '(') {
            count++;
        } else if (caractere == ')') {
            if (count == 0) {
                return false; // parêntese de fechamento sem correspondente de abertura
            }
            count--; // decrementar o contador de parênteses abertos
        }
    }

    return count == 0; // a expressão está balanceada se o contador for zero no final
}

int main() {
    char string[1001]; // buffer para a expressão (até 1000 caracteres)
    while (fgets(string, sizeof(string), stdin)) {
        // remover a nova linha, se houver
        string[strcspn(string, "\n")] = 0;
        
        if (verifica(string)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
