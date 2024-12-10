import java.util.ArrayList;
import java.util.Scanner;

public class Cordão_de_Led_3171 {
    static ArrayList<Integer>[] adjList;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Lendo N (número de segmentos) e L (número de ligações)
        int N = scanner.nextInt();
        int L = scanner.nextInt();
        
        // Inicializando a lista de adjacências
        adjList = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            adjList[i] = new ArrayList<>();
        }
        
        // Lendo as ligações e populando a lista de adjacências
        for (int i = 0; i < L; i++) {
            int X = scanner.nextInt();
            int Y = scanner.nextInt();
            adjList[X].add(Y);
            adjList[Y].add(X);
        }
        
        // Inicializando o array de visitados
        visited = new boolean[N + 1];
        
        // Realizando a DFS a partir do nó 1
        dfs(1);
        
        // Verificando se todos os nós foram visitados
        boolean completo = true;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                completo = false;
                break;
            }
        }
        
        // Imprimindo o resultado
        if (completo) {
            System.out.println("COMPLETO");
        } else {
            System.out.println("INCOMPLETO");
        }
        
        scanner.close();
    }
    
    // Método para realizar a busca em profundidade (DFS)
    static void dfs(int node) {
        visited[node] = true;
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
    }
}
