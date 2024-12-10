import java.util.Scanner;

public class Main {
    static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read city dimensions
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        // Create a 2D array to store the number of snowmen at each position
        int[][] city = new int[N + 1][M + 1];
        
        // Initialize counters and read input events
        int dayCounter = 0;

        while (sc.hasNext()) {
            // Read the first integer to determine the type of event
            String line = sc.nextLine().trim();
            String[] parts = line.split(" ");
            int len = parts.length;
            
            if (len == 3) {
                // Construction event
                int X = Integer.parseInt(parts[0]);
                int Y = Integer.parseInt(parts[1]);
                int B = Integer.parseInt(parts[2]);
                city[X][Y] += B;
            } else if (len == 2) {
                // Destruction event
                int X = Integer.parseInt(parts[0]);
                int Y = Integer.parseInt(parts[1]);
                city[X][Y] = 0;
            } else if (len == 5) {
                // Distribution event
                int X1 = Integer.parseInt(parts[0]);
                int Y1 = Integer.parseInt(parts[1]);
                int X2 = Integer.parseInt(parts[2]);
                int Y2 = Integer.parseInt(parts[3]);
                int C = Integer.parseInt(parts[4]);

                // Calculate the number of snowmen in the given rectangular area
                int snowmenCount = 0;
                for (int i = X1; i <= X2; i++) {
                    for (int j = Y1; j <= Y2; j++) {
                        snowmenCount += city[i][j];
                    }
                }
                
                // Calculate the number of ways to distribute C carrots among snowmenCount snowmen
                int result = (snowmenCount == 0) ? 0 : nCrMod(C + snowmenCount - 1, snowmenCount - 1, MOD);
                
                // Print the result for this day
                dayCounter++;
                System.out.println("Dia " + dayCounter + ": " + result);
            }
        }
        sc.close();
    }
    
    // Function to compute nCr % MOD
    static int nCrMod(int n, int r, int mod) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
        
        int[] dp = new int[r + 1];
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = Math.min(i, r); j > 0; j--) {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
        }
        
        return dp[r];
    }
}
