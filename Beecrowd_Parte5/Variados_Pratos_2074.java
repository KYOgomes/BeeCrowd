import java.util.*;

public class Variados_Pratos_2074 {

    static long[][] dp;
    static int MOD = 1_000_000_007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        List<String> results = new ArrayList<>();

        while (T-- > 0) {
            int N = scanner.nextInt();
            int K = scanner.nextInt();

            dp = new long[N + 1][1 << N];
            for (long[] row : dp) {
                Arrays.fill(row, -1);
            }

            long result = countValidPermutations(N, K, 0, 0);
            results.add(String.valueOf(result));
        }

        scanner.close();

        // Print all results
        for (String result : results) {
            System.out.println(result);
        }
    }

    static long countValidPermutations(int N, int K, int i, int used) {
        if (i == N) {
            return 1; // Base case: found a valid permutation
        }

        if (dp[i][used] != -1) {
            return dp[i][used]; // Return memoized result
        }

        long count = 0;

        for (int j = 0; j < N; j++) {
            if ((used & (1 << j)) == 0 && Math.abs(j - i) <= K) {
                count += countValidPermutations(N, K, i + 1, used | (1 << j));
                count %= MOD; // To avoid overflow, since result can be large
            }
        }

        dp[i][used] = count; // Store result in memoization array
        return count;
    }
}
