import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Socrates_e_Suas_perguntas_3155 {

    static class Query {
        int L, R, index;

        public Query(int L, int R, int index) {
            this.L = L;
            this.R = R;
            this.index = index;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

        int N = Integer.parseInt(tokenizer.nextToken());
        int Q = Integer.parseInt(tokenizer.nextToken());

        int[] array = new int[N + 1];
        tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 1; i <= N; i++) {
            array[i] = Integer.parseInt(tokenizer.nextToken());
        }

        Query[] queries = new Query[Q];
        for (int i = 0; i < Q; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int L = Integer.parseInt(tokenizer.nextToken());
            int R = Integer.parseInt(tokenizer.nextToken());
            queries[i] = new Query(L, R, i);
        }

        // Ordenar as queries por blocos para minimizar o movimento no array
        int blockSize = (int) Math.sqrt(N);
        Arrays.sort(queries, Comparator.comparingInt((Query q) -> q.L / blockSize)
                                      .thenComparingInt(q -> q.R));

        int[] count = new int[N + 1];
        int[] freq = new int[N + 1];
        int[] answer = new int[Q];

        int currentL = 1, currentR = 0;
        int distinctCount = 0;

        // Função para adicionar um elemento no intervalo
        Runnable add = () -> {
            int num = array[currentR];
            freq[count[num]]--;
            count[num]++;
            freq[count[num]]++;
            if (count[num] == num) {
                distinctCount++;
            }
            if (count[num] - 1 == num) {
                distinctCount--;
            }
        };

        // Função para remover um elemento do intervalo
        Runnable remove = () -> {
            int num = array[currentL];
            freq[count[num]]--;
            if (count[num] == num) {
                distinctCount--;
            }
            count[num]--;
            freq[count[num]]++;
            if (count[num] == num) {
                distinctCount++;
            }
        };

        for (Query query : queries) {
            int L = query.L, R = query.R, idx = query.index;

            while (currentR < R) {
                currentR++;
                add.run();
            }
            while (currentR > R) {
                remove.run();
                currentR--;
            }
            while (currentL < L) {
                remove.run();
                currentL++;
            }
            while (currentL > L) {
                currentL--;
                add.run();
            }

            answer[idx] = distinctCount;
        }

        StringBuilder output = new StringBuilder();
        for (int ans : answer) {
            output.append(ans).append("\n");
        }
        System.out.print(output);
    }
}
