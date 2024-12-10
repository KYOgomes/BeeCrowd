import java.util.Scanner;

public class Fibonacki_2893 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt(); // número de casos de teste
        
        while (T-- > 0) {
            int k = sc.nextInt(); // valor de k
            int N = sc.nextInt(); // valor de N
            
            // Definindo o tamanho máximo para a sequência de Fibonacki
            int maxN = 2 * 100000; // 2 * 10^5
            int[] fibonacki = new int[maxN];
            
            // Preenchendo os primeiros k elementos da sequência de Fibonacki
            for (int i = 0; i < k; i++) {
                fibonacki[i] = i; // iniciando com os primeiros números
            }
            
            // Calculando os termos da sequência de Fibonacki até o N-ésimo termo
            for (int i = k; i < N; i++) {
                fibonacki[i] = 0;
                for (int j = 1; j <= k; j++) {
                    fibonacki[i] = (fibonacki[i] + fibonacki[i - j]) % 1000007;
                }
            }
            
            // Imprimindo o valor do N-ésimo termo da sequência de Fibonacki
            System.out.println(fibonacki[N-1]);
        }
        
        sc.close();
    }
}
