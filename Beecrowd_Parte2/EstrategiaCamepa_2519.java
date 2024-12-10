import java.util.Scanner;

public class Main {
    
    static class FenwickTree2D {
        int[][] tree;
        int[][] field;
        int N, M;
        
        public FenwickTree2D(int n, int m, int[][] initialField) {
            N = n;
            M = m;
            tree = new int[N + 1][M + 1];
            field = new int[N + 1][M + 1];
            
            // Inicializa o BIT e o campo
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    update(i, j, initialField[i][j]);
                }
            }
        }
        
        // Atualiza o valor na posição (x, y) e no BIT
        public void update(int x, int y, int delta) {
            int diff = delta - field[x][y];
            field[x][y] = delta;
            for (int i = x; i <= N; i += (i & -i)) {
                for (int j = y; j <= M; j += (j & -j)) {
                    tree[i][j] += diff;
                }
            }
        }
        
        // Consulta a soma até a posição (x, y) no BIT
        public int query(int x, int y) {
            int sum = 0;
            for (int i = x; i > 0; i -= (i & -i)) {
                for (int j = y; j > 0; j -= (j & -j)) {
                    sum += tree[i][j];
                }
            }
            return sum;
        }
        
        // Consulta a quantidade de jogadores na região retangular
        public int queryRectangle(int x1, int y1, int x2, int y2) {
            return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        while (sc.hasNext()) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            
            if (N == 0 && M == 0) break;
            
            int[][] initialField = new int[N + 1][M + 1];
            
            // Ler o campo inicial
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    initialField[i][j] = sc.nextInt();
                }
            }
            
            FenwickTree2D fenwickTree = new FenwickTree2D(N, M, initialField);
            
            int Q = sc.nextInt();
            StringBuilder output = new StringBuilder();
            
            // Processar cada operação
            for (int q = 0; q < Q; q++) {
                int R = sc.nextInt();
                if (R == 0) {
                    int I1 = sc.nextInt();
                    int J1 = sc.nextInt();
                    int I2 = sc.nextInt();
                    int J2 = sc.nextInt();
                    
                    // Movimentação do jogador de (I1, J1) para (I2, J2)
                    fenwickTree.update(I1, J1, 0);
                    fenwickTree.update(I2, J2, 1);
                } else if (R == 1) {
                    int I1 = sc.nextInt();
                    int J1 = sc.nextInt();
                    int I2 = sc.nextInt();
                    int J2 = sc.nextInt();
                    
                    // Consulta na região (I1, J1) até (I2, J2)
                    int playersCount = fenwickTree.queryRectangle(I1, J1, I2, J2);
                    output.append(playersCount).append("\n");
                }
            }
            
            System.out.print(output);
        }
        
        sc.close();
    }
}
