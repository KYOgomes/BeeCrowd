import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int P = scanner.nextInt();

        // Matrizes para contar quantas pedras pretas e brancas até cada posição (i, j)
        int[][] prefixBlack = new int[N][N];
        int[][] prefixWhite = new int[N][N];

        // Leitura das pedras pretas
        for (int i = 0; i < P; i++) {
            int L = scanner.nextInt() - 1; // 1-based to 0-based index
            int C = scanner.nextInt() - 1; // 1-based to 0-based index
            prefixBlack[L][C]++;
        }

        // Leitura das pedras brancas
        for (int i = 0; i < P; i++) {
            int L = scanner.nextInt() - 1; // 1-based to 0-based index
            int C = scanner.nextInt() - 1; // 1-based to 0-based index
            prefixWhite[L][C]++;
        }

        // Construção das matrizes de prefixo
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i > 0) {
                    prefixBlack[i][j] += prefixBlack[i - 1][j];
                    prefixWhite[i][j] += prefixWhite[i - 1][j];
                }
                if (j > 0) {
                    prefixBlack[i][j] += prefixBlack[i][j - 1];
                    prefixWhite[i][j] += prefixWhite[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    prefixBlack[i][j] -= prefixBlack[i - 1][j - 1];
                    prefixWhite[i][j] -= prefixWhite[i - 1][j - 1];
                }
            }
        }

        // Contagem das sub-áreas
        int blackAreas = 0;
        int whiteAreas = 0;

        // Percorre todas as possíveis sub-áreas
        for (int size = 1; size <= N; size++) {
            for (int i = 0; i <= N - size; i++) {
                for (int j = 0; j <= N - size; j++) {
                    int totalBlack = prefixBlack[i + size - 1][j + size - 1];
                    int totalWhite = prefixWhite[i + size - 1][j + size - 1];

                    if (i > 0) {
                        totalBlack -= prefixBlack[i - 1][j + size - 1];
                        totalWhite -= prefixWhite[i - 1][j + size - 1];
                    }
                    if (j > 0) {
                        totalBlack -= prefixBlack[i + size - 1][j - 1];
                        totalWhite -= prefixWhite[i + size - 1][j - 1];
                    }
                    if (i > 0 && j > 0) {
                        totalBlack += prefixBlack[i - 1][j - 1];
                        totalWhite += prefixWhite[i - 1][j - 1];
                    }

                    if (totalBlack > 0 && totalWhite == 0) {
                        blackAreas++;
                    } else if (totalBlack == 0 && totalWhite > 0) {
                        whiteAreas++;
                    }
                }
            }
        }

        // Saída do resultado
        System.out.println(blackAreas + " " + whiteAreas);

        scanner.close();
    }
}
