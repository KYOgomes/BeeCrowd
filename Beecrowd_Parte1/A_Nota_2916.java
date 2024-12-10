import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class A_Nota_2916 {

    static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String line;

        while ((line = br.readLine()) != null) {
            st = new StringTokenizer(line);
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            // Ler as notas
            long[] notas = new long[N];
            line = br.readLine();
            st = new StringTokenizer(line);
            for (int i = 0; i < N; i++) {
                notas[i] = Long.parseLong(st.nextToken());
            }

            // Encontrar a soma das K-ésimas maiores notas
            long result = findKthLargestSum(notas, N, K);

            // Imprimir o resultado
            System.out.println(result);
        }

        br.close();
    }

    static long findKthLargestSum(long[] notas, int N, int K) {
        // Min-heap para manter as K maiores notas
        PriorityQueue<Long> minHeap = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            minHeap.offer(notas[i]);
            if (minHeap.size() > K) {
                minHeap.poll(); // Remove a menor das K maiores notas
            }
        }

        // Calcular a soma das K maiores notas
        long sum = 0;
        while (!minHeap.isEmpty()) {
            sum = (sum + minHeap.poll()) % MOD;
        }

        return sum;
    }
}
