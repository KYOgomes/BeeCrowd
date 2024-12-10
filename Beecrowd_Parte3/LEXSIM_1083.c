/*
Uma das formas mais interessantes do uso de pilhas é a na avaliação de uma expressão matemática. Pode-se, através da pilha, fazer a análise léxica de uma expressão (indicar se uma expressão possui um operando inválido, como por exemplo um símbolo qualquer que não está presente nem na tabela de operadores, nem na tabela de operandos) e também a análise sintática. A análise sintática pode indicar que está faltando um ou mais parênteses, sobrando um ou mais parênteses, sobrando operador, 2 operandos sucessivos, etc. A tarefa aqui é determinar se uma expressão está correta ou não.

Entrada
Como entrada, são válidos:
a) Operandos: todas as letras maiúsculas ou minúsculas ('a'..'z', 'A'..'Z') e números (0...9).
b) Parênteses.
c) Operadores: deverão ser aceitos os seguintes operadores segundo a tabela de prioridades  apresentada abaixo:

Operador	        /     Prioridade
^	                           6
*,/	                           5
+,-	                           4
>,<,=,#,	                   3
AND ( . )	                   2
OR ( | )	                   1

Para facilitar a implementação, será utilizado um ponto para representar o AND (.) e o Pipe ( | ) para representar o OR.

Obs.: Como restrição, não será permitida a entrada de expressões com operadores unários, como por e exemplo o '-' de: 4 * -2

A finalização da entrada será determinada pelo final do arquivo de entrada EOF().

Saída
Como saída, para cada expressão de entrada deverá ser gerado uma linha indicando o resultado do processamento. Se a expressão estiver correta, esta deverá ser transformada para a forma posfixa. Se não for possível, deverá ser impressa a mensagem "Lexical Error!" indicando erro léxico ou "Syntax Error!" indicando o erro de sintaxe, nesta ordem.

Exemplo de Entrada	
(
(A+
(A+B)*c
(A+B)*%
(a+b*c)/2*e+a
(a+b*c)/2*(e+a)
(a+b*c)/2*(e+a
(ab+*c)/2*(e+a)
(a+b*cc)/2*(e+a
(“a+b*cc)/2*(e+a
a+b-c
a-b*c/d+e

Exemplo de Saída
Syntax Error!
Syntax Error!
AB+c*
Lexical Error!
abc*+2/e*a+
abc*+2/ea+*
Syntax Error!
Syntax Error!
Syntax Error!
Lexical Error!
ab+c-
abc*d/-e+
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char stack[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    s->stack[++s->top] = c;
}

char pop(Stack *s) {
    return s->stack[s->top--];
}

int isOperator(char c) {
    return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-' || c == '>' || c == '<' || c == '=' || c == '#' || c == '.' || c == '|');
}

int getPriority(char c) {
    switch (c) {
        case '^':
            return 6;
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 4;
        case '>':
        case '<':
        case '=':
        case '#':
            return 3;
        case '.':
            return 2;
        case '|':
            return 1;
        default:
            return 0;
    }
}

void infixToPostfix(char *expression) {
    Stack stack;
    init(&stack);

    int len = strlen(expression);
    char postfix[MAX];
    int postfixIndex = 0;

    for (int i = 0; i < len; i++) {
        char c = expression[i];

        if (isOperator(c)) {
            while (stack.top >= 0 && getPriority(stack.stack[stack.top]) >= getPriority(c)) {
                postfix[postfixIndex++] = pop(&stack);
            }
            push(&stack, c);
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (stack.top >= 0 && stack.stack[stack.top] != '(') {
                postfix[postfixIndex++] = pop(&stack);
            }
            if (stack.top >= 0 && stack.stack[stack.top] == '(') {
                pop(&stack);
            } else {
                printf("Syntax Error!\n");
                return;
            }
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[postfixIndex++] = c;
        } else {
            printf("Lexical Error!\n");
            return;
        }
    }

    while (stack.top >= 0) {
        if (stack.stack[stack.top] == '(' || stack.stack[stack.top] == ')') {
            printf("Syntax Error!\n");
            return;
        }
        postfix[postfixIndex++] = pop(&stack);
    }

    postfix[postfixIndex] = '\0';
    printf("%s\n", postfix);
}

int main() {
    char expression[MAX];
    while (scanf("%s", expression) != EOF) {
        infixToPostfix(expression);
    }
    return 0;
}
