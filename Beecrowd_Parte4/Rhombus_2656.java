import java.util.Scanner;

public class Rhombus_2656 {
    static final int MAX = 101;
    static int[][] grid = new int[MAX][MAX];

    // Função para calcular a soma dentro da distância Manhattan d a partir de (x, y)
    static int manhattanSum(int x, int y, int d) {
        int sum = 0;
        // Percorrendo as células dentro do quadrado manhattan de lado 2*d+1
        for (int i = x - d; i <= x + d; i++) {
            for (int j = y - (d - Math.abs(x - i)); j <= y + (d - Math.abs(x - i)); j++) {
                // Verificando se (i, j) está dentro dos limites da matriz
                if (i >= 0 && i < MAX && j >= 0 && j < MAX) {
                    sum += grid[i][j];
                }
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q;
        while ((q = scanner.nextInt()) != 0) {
            while (q-- > 0) {
                int type = scanner.nextInt();
                int x = scanner.nextInt();
                int y = scanner.nextInt();
                if (type == 1) {
                    grid[x][y] = 1; // Marcando como ocupada
                } else if (type == 2) {
                    grid[x][y] = 0; // Marcando como livre
                } else if (type == 3) {
                    int d = scanner.nextInt();
                    int result = manhattanSum(x, y, d);
                    System.out.println(result);
                }
            }
        }
    }
}