/*
Crie um programa para ordenar um conjunto de strings pelo seu tamanho. Seu programa deve receber um conjunto de strings e retornar este mesmo conjunto ordenado pelo tamanho das palavras, se o tamanho das strings for igual, deve-se manter a ordem original do conjunto.

Entrada
A primeira linha da entrada possui um único inteiro N, que indica o número de casos de teste. Cada caso de teste poderá conter de 1 a 50 strings inclusive, e cada uma das strings poderá conter entre 1 e 50 caracteres inclusive. Os caracteres poderão ser espaços, letras, ou números.

Saída
A saída deve conter o conjunto de strings da entrada ordenado pelo tamanho das strings. Um espaço em branco deve ser impresso entre duas palavras.

Exemplo de Entrada	
4
Top Coder comp Wedn at midnight
one three five
I love Cpp
sj a sa df r e w f d s a v c x z sd fd

Exemplo de Saída
midnight Coder comp Wedn Top at
three five one
love Cpp I
sj sa df sd fd a r e w f d s a v c x z
*/
import java.util.*;

public class Ordenacao_por_Tamanho_1244 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine(); 

        for (int k = 0; k < N; ++k) {
            String frase = sc.nextLine();
            String[] palavras = frase.split(" ");
            insertionSort(palavras);

            System.out.print(palavras[0]);
            for (int i = 1; i < palavras.length; ++i) {
                System.out.print(" " + palavras[i]);
            }
            System.out.println();
        }

        sc.close();
    }

    public static void insertionSort(String[] palavras) {
        for (int i = 1; i < palavras.length; ++i) {
            String temp = palavras[i];
            int j = i - 1;
            while (j >= 0 && palavras[j].length() < temp.length()) {
                palavras[j + 1] = palavras[j];
                j--;
            }
            palavras[j + 1] = temp;
        }
    }
}
