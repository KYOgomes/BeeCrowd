import java.util.*;

public class Main {

    static class UnionFind {
        int[] parent;
        int[] rank;

        public UnionFind(int size) {
            parent = new int[size + 1];
            rank = new int[size + 1];
            for (int i = 1; i <= size; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        public int find(int u) {
            if (parent[u] != u) {
                parent[u] = find(parent[u]); // Path compression
            }
            return parent[u];
        }

        public void union(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            
            if (rootU != rootV) {
                // Union by rank
                if (rank[rootU] > rank[rootV]) {
                    parent[rootV] = rootU;
                } else if (rank[rootU] < rank[rootV]) {
                    parent[rootU] = rootV;
                } else {
                    parent[rootV] = rootU;
                    rank[rootU]++;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine(); // Consumir o newline após os inteiros

        UnionFind uf = new UnionFind(N);

        for (int i = 0; i < K; i++) {
            String line = scanner.nextLine();
            String[] parts = line.split(" ");

            char type = parts[0].charAt(0);
            int A = Integer.parseInt(parts[1]);
            int B = Integer.parseInt(parts[2]);

            if (type == 'F') {
                uf.union(A, B);
            } else if (type == 'C') {
                if (uf.find(A) == uf.find(B)) {
                    System.out.println("S");
                } else {
                    System.out.println("N");
                }
            }
        }

        scanner.close();
    }
}
