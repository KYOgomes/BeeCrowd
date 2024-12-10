import java.util.*;

public class Binarizando_a_Matriz_2805 {
    static final int MOD = 1000000007;
    static int[][] dp = new int[105][105];
    static char[][] grid = new char[105][105];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.nextLine();

        for (int i = 1; i <= N; i++) {
            String line = scanner.nextLine();
            for (int j = 1; j <= M; j++) {
                grid[i][j] = line.charAt(j - 1);
            }
        }

        dp[0][0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (grid[i][j] != '0') {
                    for (int k = 0; k < j; k++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                    }
                }
                if (grid[i][j] != '1') {
                    for (int k = j; k < M; k++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                    }
                }
            }
        }

        int result = 0;
        for (int i = 0; i <= M; i++) {
            result = (result + dp[N][i]) % MOD;
        }
        System.out.println(result + 6);
    }
}