import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Amigos_3160 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());

        int[] array = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }

        Query[] queries = new Query[Q];
        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int L = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());
            queries[i] = new Query(L, R, i);
        }

        // Ordenar as queries para otimizar o processamento dos intervalos
        MoAlgorithm.sort(queries);

        int[] freq = new int[N + 1]; // Frequência de cada número no intervalo
        int[] countFreq = new int[N + 1]; // Contagem de quantas vezes cada frequência ocorre
        int[] left = new int[N + 1]; // Índice mais à esquerda que o número aparece
        int[] right = new int[N + 1]; // Índice mais à direita que o número aparece

        int[] answer = new int[Q];

        // Processamento das queries
        int currentL = 1, currentR = 0;
        int distinctCount = 0;

        for (Query query : queries) {
            int L = query.L;
            int R = query.R;
            int index = query.index;

            // Ajustar o intervalo [currentL, currentR] para [L, R]
            while (currentR < R) {
                currentR++;
                int num = array[currentR];

                if (left[num] == 0) left[num] = currentR;
                right[num] = currentR;

                int oldFreq = freq[num];
                freq[num]++;
                
                if (oldFreq == num) {
                    countFreq[num]--;
                } else if (freq[num] == num) {
                    countFreq[num]++;
                }

                if (countFreq[num] == 1 && left[num] == currentL) {
                    distinctCount++;
                }
            }

            while (currentR > R) {
                int num = array[currentR];
                int oldFreq = freq[num];
                freq[num]--;
                
                if (oldFreq == num) {
                    countFreq[num]--;
                } else if (freq[num] == num - 1) {
                    countFreq[num]--;
                }

                if (countFreq[num] == 0 && right[num] == currentR) {
                    distinctCount--;
                }

                currentR--;
            }

            while (currentL < L) {
                int num = array[currentL];
                int oldFreq = freq[num];
                freq[num]--;
                
                if (oldFreq == num) {
                    countFreq[num]--;
                } else if (freq[num] == num - 1) {
                    countFreq[num]--;
                }

                if (countFreq[num] == 0 && right[num] == currentL) {
                    distinctCount--;
                }

                currentL++;
            }

            while (currentL > L) {
                currentL--;
                int num = array[currentL];

                if (left[num] == 0) left[num] = currentL;
                right[num] = currentL;

                int oldFreq = freq[num];
                freq[num]++;
                
                if (oldFreq == num) {
                    countFreq[num]--;
                } else if (freq[num] == num) {
                    countFreq[num]++;
                }

                if (countFreq[num] == 1 && left[num] == currentR) {
                    distinctCount++;
                }
            }

            answer[index] = distinctCount;
        }

        // Imprimir as respostas
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < Q; i++) {
            sb.append(answer[i]).append("\n");
        }
        System.out.print(sb);
    }

    // Classe para representar uma consulta
    static class Query {
        int L, R, index;

        public Query(int L, int R, int index) {
            this.L = L;
            this.R = R;
            this.index = index;
        }
    }

    // Implementação do algoritmo de ordenação Mo
    static class MoAlgorithm {

        // Função para ordenar as queries
        static void sort(Query[] queries) {
            int blockSize = (int) Math.sqrt(queries.length);
            Arrays.sort(queries, (q1, q2) -> {
                int block1 = q1.L / blockSize;
                int block2 = q2.L / blockSize;
                if (block1 != block2) {
                    return block1 - block2;
                }
                return q1.R - q2.R;
            });
        }
    }
}
