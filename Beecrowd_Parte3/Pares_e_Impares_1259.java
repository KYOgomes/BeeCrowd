/*
Considerando a entrada de valores inteiros não negativos, ordene estes valores segundo o seguinte critério:

Primeiro os Pares
Depois os Ímpares
Sendo que deverão ser apresentados os pares em ordem crescente e depois os ímpares em ordem decrescente.

Entrada
A primeira linha de entrada contém um único inteiro positivo N (1 < N <= 105) Este é o número de linhas de entrada que vem logo a seguir. As próximas N linhas conterão, cada uma delas, um valor inteiro não negativo.

Saída
Apresente todos os valores lidos na entrada segundo a ordem apresentada acima. Cada número deve ser impresso em uma linha, conforme exemplo abaixo.

Exemplo de Entrada	
10
4
32
34
543
3456
654
567
87
6789
98

Exemplo de Saída
4
32
34
98
654
3456
6789
567
543
87

*/
import java.util.Scanner;

public class Pares_e_Impares_1259 {

    // Função para trocar dois elementos em um array
    static void trocar(int[] arr, int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }

    // Função de comparação personalizada
    static int comp(int a, int b) {
        // Implementação da função comp do código C adaptado
        if (a % 2 == 0) {
            if (b % 2 == 0)
                return a - b; // ambos são pares
            else
                return -1; // a é par, b é ímpar
        } else {
            if (b % 2 == 0)
                return 1; // a é ímpar, b é par
            else
                return b - a; // ambos são ímpares
        }
    }

    // Função de ordenação manual
    static void ordenar(int[] arr, int n) {
        // Utilizaremos um algoritmo de ordenação simples, como Bubble Sort
        boolean trocou = true;
        while (trocou) {
            trocou = false;
            for (int i = 1; i < n; ++i) {
                if (comp(arr[i-1], arr[i]) > 0) {
                    trocar(arr, i-1, i);
                    trocou = true;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] numeros = new int[n];

        for (int i = 0; i < n; ++i) {
            numeros[i] = scanner.nextInt();
        }

        // Ordenar o array utilizando nossa função de ordenação personalizada
        ordenar(numeros, n);

        // Imprimir os números ordenados
        for (int i = 0; i < n; ++i) {
            System.out.println(numeros[i]);
        }

        scanner.close();
    }
}
