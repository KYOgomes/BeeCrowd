import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class O_Contra_Ataque_1863 {
    static class Soldier {
        int x, y;
        List<Integer> strongerThan;
        
        public Soldier(int x, int y) {
            this.x = x;
            this.y = y;
            this.strongerThan = new ArrayList<>();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        Soldier[] soldiers = new Soldier[N + 1];
        for (int i = 1; i <= N; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            soldiers[i] = new Soldier(x, y);
        }

        for (int i = 0; i < M; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            soldiers[u].strongerThan.add(v);
        }

        int[] dp = new int[N + 1];
        Arrays.fill(dp, 1);

        for (int i = 1; i <= N; i++) {
            for (int j : soldiers[i].strongerThan) {
                if (soldiers[i].x > soldiers[j].x && soldiers[i].y > soldiers[j].y) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxSoldiers = 1;
        for (int i = 1; i <= N; i++) {
            maxSoldiers = Math.max(maxSoldiers, dp[i]);
        }

        System.out.println(maxSoldiers);

        sc.close();
    }
}
