import java.util.Scanner;

public class Trocando_Presentes_2734 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();

        for (int t = 0; t < T; t++) {
            int N = scanner.nextInt();
            int[] gifts = new int[2*N];
            int totalSum = 0;

            for (int i = 0; i < 2*N; i++) {
                gifts[i] = scanner.nextInt();
                totalSum += gifts[i];
            }

            boolean[] dp = new boolean[totalSum + 1];
            dp[0] = true;

            for (int i = 0; i < 2*N; i++) {
                for (int j = totalSum; j >= gifts[i]; j--) {
                    dp[j] = dp[j] || dp[j - gifts[i]];
                }
            }

            int halfSum = totalSum / 2;
            while (!dp[halfSum]) {
                halfSum--;
            }

            System.out.println(totalSum - 2*halfSum);
        }

        scanner.close();
    }
}