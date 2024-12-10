/*
Um baralho contém um número par 2n de cartas a1, a2,..., a2n, todas distintas (a1 < a2 ... < a2n). O baralho encontra-se perfeitamente ordenado, ou seja, a primeira carta é a1, a segunda carta é a2, e assim por diante, até a última carta, que é a2n.

Um croupier então executa repetidamente um procedimento de embaralhar, que consiste de dois passos:

O baralho é divido ao meio;
As cartas das duas metades são então intercaladas, de maneira que se a sequência de cartas do baralho no início do passo 1 é x1, x2, ..., x2n, então ao final do passo 2 a sequência de cartas se torna xn+1, x1, xn+2, x2,..., x2n, xn.
Dado o número de cartas do baralho, escreva um programa que determine quantas vezes o procedimento de embaralhar descrito acima deve ser re petido de forma que o baralho volte a ficar ordenado.

Entrada
A única linha da entrada contém um inteiro par P (2 ≤ P ≤ 2 x 105 ), indicando o número de cartas do baralho (note que o valor P corresponde ao valor 2n na descrição acima).

Saída
Seu programa deve produzir uma única linha contendo um único inteiro, o número mínimo de vezes que o processo de embaralhamento deve ser repetido para que o baralho fique novamente ordenado.

Exemplo de Entrada
6

Exemplo de Saída 
3
*/

import java.util.Scanner;

public class Baralho_Embaralhado_1709 {

    // Declaração da variável global p
    static int p;

    // Função principal para chamar a função embaralhar e imprimir o resultado
    public static void main(String[] args) {
        // Leitura do valor de p
        Scanner scanner = new Scanner(System.in);
        //System.out.print("Digite o valor de p: ");
        p = scanner.nextInt();

        // Chamada da função embaralhar(1, 1) e impressão do resultado
        System.out.println(embaralhar(1, 1));

        scanner.close();
    }

    // Definição da função embaralhar
    static int embaralhar(int a, int c) {
        int b;
        if (2 * a <= p)
            b = 2 * a;
        else
            b = 2 * a - (p + 1);

        if (b == 1)
            return c;
        else
            return embaralhar(b, c + 1);
    }
}
