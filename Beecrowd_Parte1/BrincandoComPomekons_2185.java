import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken()); // Quantidade de pilhas
        int M = Integer.parseInt(st.nextToken()); // Quantidade de alterações
        
        int[] pilhas = new int[N]; // Array para armazenar a quantidade de Pomekons em cada pilha
        
        // Lê as quantidades iniciais de Pomekons em cada pilha
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            pilhas[i] = Integer.parseInt(st.nextToken());
        }
        
        // Processa cada alteração
        for (int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            int X = Integer.parseInt(st.nextToken()) - 1; // 0-indexed
            int Y = Integer.parseInt(st.nextToken()) - 1; // 0-indexed
            int V = Integer.parseInt(st.nextToken());
            
            // Aplica a alteração nas pilhas
            for (int i = X; i <= Y; i++) {
                pilhas[i] = V;
            }
            
            // Verifica se Dabriel tem chance de ganhar após a alteração
            boolean possivel = false;
            for (int i = 0; i < N; i++) {
                if (pilhas[i] > 0) {
                    possivel = true;
                    break;
                }
            }
            
            // Imprime o resultado para a alteração atual
            if (possivel) {
                System.out.println("Possivel");
            } else {
                System.out.println("Impossivel");
            }
        }
        
        br.close();
    }
}
