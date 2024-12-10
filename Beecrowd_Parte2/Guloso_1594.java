/*
Dado um vetor de inteiros de tamanho N e um inteiro K, ache o maior elemento para cada sub-vetor contínuo de tamanho K. Imprima a soma de todos estes valores.

Exemplo 1: Se tivermos o vetor [3, 2, 1, 4, 10] e K for 3, então temos que considerar os sub-vetores [3, 2, 1], [2, 1, 4] e [1, 4, 10]. O maior elemento de cada sub-vetor vale 3, 4 e 10, somando o total de 17.

Exemplo 2: Se tivermos o vetor [1, 2, 3, 4, 5, 6] e K for 2, então temos que considerar os sub-vetores [1, 2], [2, 3], [3, 4], [4, 5] e [5, 6]. O maior elemento de cada sub-vetor vale 2, 3, 4, 5 e 6 somando o total de 20.

Exemplo 3: Se tivermos o vetor [5, 4, 3] e K for 1, então temos que considerar os sub-vetores [5], [4] e [3]. O maior elemento de cada sub-vetor vale 5, 4 e 3 somando o total de 12.

Entrada
A entrada para esse problema é bem singular, leia com atenção! Na primeira linha você terá um inteiro T (T = 200) indicando o número de casos de teste. Para cada caso você receberá três números inteiros, N (1 ≤ N ≤ 104* ou 1 ≤ N ≤ 106**), K (1 ≤ K ≤ N) e S (0 ≤ S ≤ 109). Para gerar o vetor de inteiros, use o seguinte código em C/C++ em que recomendamos que você copie (control+C) do enunciado:

array[0] = S;
for (i = 1; i < N; ++i)
    array[i] = (1LL*array[i-1]*1103515245 + 12345) % (2147483648LL);

É garantido que existe uma solução que não se baseia nas propriedades do gerador da entrada acima.

*ocorrerá em 90% dos casos;
**ocorrerá nos casos restantes.

Saída
Para cada caso imprima a soma dos maiores elementos de cada sub-vetor.

Exemplo de Entrada	
4
3 2 1
8 3 6
1000000 500000 1
1000000 100 1

Exemplo de Saída
2207055180
10350035639
1073743171194747
2125953085698411
 */
import java.util.*;

public class Guloso_1594 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();  // Número de casos de teste
        for (int t = 0; t < T; t++) {
            int N = scanner.nextInt();  // Tamanho do vetor
            int K = scanner.nextInt();  // Tamanho do sub-vetor
            long S = scanner.nextLong();  // Valor inicial para gerar o vetor de inteiros

            // Gerar vetor de inteiros
            long[] array = new long[N];
            array[0] = S;
            Random rand = new Random(S);
            for (int i = 1; i < N; i++) {
                array[i] = (1L * array[i - 1] * 1103515245 + 12345) % (2147483648L);
            }

            // Calcular a soma dos maiores elementos dos sub-vetores de tamanho K
            long somaDosMaioresElementos = 0;
            Deque<Integer> deque = new LinkedList<>();

            // Primeiro sub-vetor de tamanho K
            for (int i = 0; i < K; i++) {
                while (!deque.isEmpty() && array[deque.peekLast()] <= array[i]) {
                    deque.removeLast();
                }
                deque.addLast(i);
            }
            somaDosMaioresElementos += array[deque.peekFirst()];

            // Outros sub-vetores de tamanho K
            for (int i = K; i < N; i++) {
                while (!deque.isEmpty() && deque.peekFirst() <= i - K) {
                    deque.removeFirst();
                }
                while (!deque.isEmpty() && array[deque.peekLast()] <= array[i]) {
                    deque.removeLast();
                }
                deque.addLast(i);
                somaDosMaioresElementos += array[deque.peekFirst()];
            }

            System.out.println(somaDosMaioresElementos);
        }
        scanner.close();
    }
}
