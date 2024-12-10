import java.util.*;


public class Sudoku_1383 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        for (int i = 1; i <= n; i++) {
            int[][] s = new int[9][9];
            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 9; k++) {
                    s[j][k] = scanner.nextInt();
                }
            }

            List<Boolean> linhas = new ArrayList<>();
            for (int j = 0; j < 9; j++) {
                linhas.add(f(s, j, 0, j, 8));
                linhas.add(f(s, 0, j, 8, j));
            }
            for (int j = 0; j < 9; j += 3) {
                for (int k = 0; k < 9; k += 3) {
                    linhas.add(f(s, j, k, j + 2, k + 2));
                }
            }

            boolean ok = linhas.stream().reduce(true, (a, b) -> a && b);
            System.out.println("Instancia " + i);
            System.out.println(ok ? "SIM" : "NAO");
            System.out.println();
        }
        scanner.close();
    }

    public static boolean f(int[][] s, int x1, int y1, int x2, int y2) {
        List<Integer> linha = new ArrayList<>();
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                linha.add(s[i][j]);
            }
        }
        Collections.sort(linha);
        List<Boolean> ordenada = new ArrayList<>();
        for (int i = 1; i <= 9; i++) {
            ordenada.add(linha.get(i - 1) == i);
        }
        return ordenada.stream().reduce(true, (a, b) -> a && b);
    }
}

