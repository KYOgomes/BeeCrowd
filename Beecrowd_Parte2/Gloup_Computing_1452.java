import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Gloup_Computing_1452 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        while (true) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            if (N == 0 && M == 0) {
                break;
            }

            // Leitura dos servidores
            Set<String>[] serverApps = new HashSet[N];
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                int Qi = Integer.parseInt(st.nextToken());
                serverApps[i] = new HashSet<>();
                for (int j = 0; j < Qi; j++) {
                    serverApps[i].add(st.nextToken());
                }
            }

            // Leitura dos clientes
            Set<String>[] clientApps = new HashSet[M];
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int Pj = Integer.parseInt(st.nextToken());
                clientApps[i] = new HashSet<>();
                for (int j = 0; j < Pj; j++) {
                    clientApps[i].add(st.nextToken());
                }
            }

            // Contagem das conexões únicas
            int totalConnections = 0;
            for (int j = 0; j < M; j++) { // para cada cliente
                for (int i = 0; i < N; i++) { // para cada servidor
                    boolean isConnected = false;
                    for (String app : clientApps[j]) {
                        if (serverApps[i].contains(app)) {
                            isConnected = true;
                            break;
                        }
                    }
                    if (isConnected) {
                        totalConnections++;
                    }
                }
            }

            // Imprime resultado para este caso de teste
            System.out.println(totalConnections);
        }

        br.close();
    }
}
