import java.util.*;

public class Trilha_Perigosa_2655 {
    static int MAX = 100010;
    static int[] road = new int[MAX];

    static int distinctMonsters(int L, int R) {
        Set<Integer> monsters = new HashSet<>();
        for (int i = L; i <= R; i++) {
            monsters.add(road[i]);
        }
        return monsters.size();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int Q = scanner.nextInt();
        int M = scanner.nextInt();
        for (int i = 1; i <= N; i++) {
            road[i] = scanner.nextInt();
        }
        while (Q-- > 0) {
            int type = scanner.nextInt();
            int L = scanner.nextInt();
            int R = scanner.nextInt();
            if (type == 1) {
                System.out.println(distinctMonsters(L, R));
            } else {
                road[L] = R;
            }
        }
    }
}