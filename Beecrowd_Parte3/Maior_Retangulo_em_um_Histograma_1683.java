/*
Resolva a questão abaixo em Java:
Um histograma é um polígono composto por uma seqüência de retângulos alinhados em uma linha de base comum. Os retângulos têm larguras iguais, mas podem ter diferentes alturas. Por exemplo, a figura da esquerda nos mostra um histograma com retângulos de alturas 2, 1, 4, 5, 1, 3, 3, onde a medida 1 é a largura dos retângulos:

Normalmente, histogramas são utilizados para representar distribuições discretas, como a freqüência de caracteres em um texto. Note que a ordem dos retângulos, ou seja, suas alturas, é importante. Calcule a área do maior retângulo de um histograma, que também esteja alinhado com a base. A figura da direita mostra o maior retângulo alinhado no histograma apresentado.

Entrada
A entrada contém vários casos de teste. Cada caso de teste descreve um histograma, e inicia com um inteiro n, que representa o número de retângulos que o compõe. Assuma que 1 ≤ n ≤ 100000. Em seguida, n inteiros h1, ..., hn, onde 0 ≤ hi ≤ 1000000000. Esses números representam as alturas dos retangulos do histograma, da esquerda para a direita. A largura de cada retângulo é 1. Um zero na entrada representa o ultimo caso de teste.

Saída
Para cada caso de teste imprima em uma única linha a área do maior retângulo no histograma especificado. Lembre-se que esse retângulo deve estar alinhado com a base do histograma.

Exemplo de Entrada	
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0

Exemplo de Saída
8
4000
 */
import java.util.Scanner;
import java.util.Stack;

public class Maior_Retangulo_em_um_Histograma_1683 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int n = scanner.nextInt();
            if (n == 0) break;
            
            long[] alturas = new long[n];
            for (int i = 0; i < n; i++) {
                alturas[i] = scanner.nextLong();
            }
            
            long maiorArea = calcularMaiorAreaHistograma(alturas);
            System.out.println(maiorArea);
        }
        scanner.close();
    }

    public static long calcularMaiorAreaHistograma(long[] alturas) {
        Stack<Integer> pilha = new Stack<>();
        long maiorArea = 0;
        int i = 0;
        
        while (i < alturas.length) {
            if (pilha.isEmpty() || alturas[pilha.peek()] <= alturas[i]) {
                pilha.push(i++);
            } else {
                int topo = pilha.pop();
                long altura = alturas[topo];
                long largura = pilha.isEmpty() ? i : i - pilha.peek() - 1;
                maiorArea = Math.max(maiorArea, altura * largura);
            }
        }
        
        while (!pilha.isEmpty()) {
            int topo = pilha.pop();
            long altura = alturas[topo];
            long largura = pilha.isEmpty() ? i : i - pilha.peek() - 1;
            maiorArea = Math.max(maiorArea, altura * largura);
        }
        
        return maiorArea;
    }
}
