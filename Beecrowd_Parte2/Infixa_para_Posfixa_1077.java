/*
O Professor solicitou que você escreva um programa que converta uma expressão na forma infixa (como usualmente conhecemos) para uma expressão na forma posfixa. Como você sabe, os termos in (no meio) e pos (depois) se referem à posição dos operadores. O programa terá que lidar somente com operadores binários +,-,*,/,^, parênteses, letras e números. Um exemplo seria uma expressão como:
(A*B+2*C^3)/2*A. O programa deve converter esta expressão (infixa) para a expressão posfixa: AB*2C3^*+2/A*
 

Entrada
A primeira linha da entrada contém um valor inteiro N (N < 1000), que indica o número de casos de teste. Cada caso de teste a seguir é uma expressão válida na forma infixa, com até 300 caracteres.

Saída
Para cada caso, apresente a expressão convertida para a forma posfixa.

Exemplo de Entrada	
3
A*2
(A*2+c-d)/2
(2*4/a^b)/(2*c)

Exemplo de Saída
A2*
A2*c+d-2/
24*ab^/2c*/

// OBS.:  O " */ "  de 24*ab^/2c*/ faz parte da saída

import java.util.Scanner;


public class Infixa_para_Posfixa_1077 {

    // Classe para representar o nó da pilha
    private static class PilhaNo {
        char valor;         // Valor armazenado no nó da pilha
        PilhaNo abaixo;     // Referência para o próximo nó abaixo na pilha

        PilhaNo(char valor) {
            this.valor = valor;
            this.abaixo = null;
        }
    }

    // Classe para representar a pilha
    private static class Pilha {
        int tamanho;        // Tamanho atual da pilha (quantidade de elementos)
        PilhaNo topo;       // Referência para o topo da pilha (último elemento inserido)

        Pilha() {
            this.tamanho = 0;
            this.topo = null;
        }

        void push(char valor) {
            PilhaNo novoTopo = new PilhaNo(valor);  // Cria um novo nó para o valor
            novoTopo.abaixo = topo;                 // Aponta o novo nó para o antigo topo
            topo = novoTopo;                        // Atualiza o topo da pilha
            tamanho++;                              // Aumenta o tamanho da pilha
        }

        void pop() {
            if (tamanho > 0) {
                topo = topo.abaixo;  // Atualiza o topo para o próximo nó abaixo
                tamanho--;           // Reduz o tamanho da pilha
            }
        }

        char top() {
            return topo.valor;  // Retorna o valor do topo da pilha
        }


        boolean isEmpty() {
            return tamanho == 0;  // Verifica se a pilha está vazia
        }
    }

    // Função para determinar a precedência de operadores
    private static int precedencia(char operador) {
        switch (operador) {
            case '+':
            case '-':
                return 1;   // Baixa precedência para soma e subtração
            case '*':
            case '/':
                return 2;   // Alta precedência para multiplicação e divisão
            default:
                return 0;   // Outros operadores têm precedência zero (ou não são operadores válidos)
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();  // Lê o número de expressões
        scanner.nextLine();         // Consumir o newline pendente após nextInt

        for (int k = 0; k < N; ++k) {
            String expressao = scanner.nextLine();  // Lê a expressão matemática

            Pilha pilha = new Pilha();  // Cria uma nova pilha para cada expressão

            int tam = expressao.length();
            for (int i = 0; i < tam; ++i) {
                char caractere = expressao.charAt(i);

                if (Character.isLetterOrDigit(caractere)) {
                    System.out.print(caractere);  // Se for caractere alfabético ou dígito, imprime diretamente
                } else if (caractere == '(' || caractere == '^') {
                    pilha.push(caractere);  // Se for '(' ou '^', empilha na pilha
                } else if (caractere == ')') {
                    while (!pilha.isEmpty() && pilha.top() != '(') {
                        System.out.print(pilha.top());  // Desempilha e imprime até encontrar '('
                        pilha.pop();
                    }

                    if (!pilha.isEmpty()) pilha.pop();  // Remove '(' da pilha, se presente
                } else {
                    while (!pilha.isEmpty() && pilha.top() != '(' && precedencia(caractere) <= precedencia(pilha.top())) {
                        System.out.print(pilha.top());  // Desempilha e imprime enquanto a precedência for maior ou igual
                        pilha.pop();
                    }

                    pilha.push(caractere);  // Empilha o operador atual
                }
            }

            while (!pilha.isEmpty()) {
                System.out.print(pilha.top());  // Desempilha e imprime qualquer operador restante na pilha
                pilha.pop();
            }

            System.out.println();  // Nova linha para a próxima expressão
        }

        scanner.close();
    }
}
