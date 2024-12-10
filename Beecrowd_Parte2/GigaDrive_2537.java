import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int N = scanner.nextInt();
            int M = scanner.nextInt();
            int[][] tabuleiro = new int[N][N];

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    tabuleiro[i][j] = scanner.nextInt();
                }
            }

            for (int i = 0; i < M; i++) {
                int x = scanner.nextInt() - 1;
                int y = scanner.nextInt() - 1;
                tabuleiro[x][y] = 1;

                int I1 = scanner.nextInt() - 1;
                int J1 = scanner.nextInt() - 1;
                int I2 = scanner.nextInt() - 1;
                int J2 = scanner.nextInt() - 1;

                int totalAzeitonas = 0;
                for (int a = I1; a <= I2; a++) {
                    for (int b = J1; b <= J2; b++) {
                        totalAzeitonas += tabuleiro[a][b];
                    }
                }
                System.out.println(totalAzeitonas);
            }
        }
        scanner.close();
    }
}
