import java.util.*;
//saida errada
public class PNetworks_1274 {
    static int[] perm;
    static int[] target;
    static int[] swaps;
    static int n;

    static boolean solve(int idx) {
        if (idx == n - 1) {
            for (int i = 0; i < n; i++) {
                if (perm[i] != target[i]) {
                    return false;
                }
            }
            return true;
        }
        for (int i = idx; i < n; i++) {
            swap(idx, i);
            swaps[idx] = i;
            if (solve(idx + 1)) {
                return true;
            }
            swap(idx, i);
        }
        return false;
    }

    static void swap(int i, int j) {
        int temp = perm[i];
        perm[i] = perm[j];
        perm[j] = temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            n = sc.nextInt();
            if (n == 0) {
                break;
            }
            perm = new int[n];
            target = new int[n];
            swaps = new int[n];
            for (int i = 0; i < n; i++) {
                perm[i] = i + 1;
                target[i] = sc.nextInt();
            }
            if (solve(0)) {
                System.out.print(n - 1);
                for (int i = 0; i < n - 1; i++) {
                    System.out.print(" " + (swaps[i] + 1));
                }
                System.out.println();
            } else {
                System.out.println("No solution");
            }
        }
        sc.close();
    }
}