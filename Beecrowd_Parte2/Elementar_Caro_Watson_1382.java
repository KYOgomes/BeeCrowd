import java.util.*;

public class Elementar_Caro_Watson_1382 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int t = 0; t < T; t++) {
            int N = sc.nextInt();
            int[] arr = new int[N];

            for (int i = 0; i < N; i++) {
                arr[i] = sc.nextInt();
            }

            System.out.println(minSwapsToSort(arr, N));
        }

        sc.close();
    }

    public static int minSwapsToSort(int[] arr, int N) {
        int[] temp = Arrays.copyOf(arr, N);
        Arrays.sort(temp);
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            map.put(temp[i], i);
        }

        boolean[] visited = new boolean[N];
        Arrays.fill(visited, false);

        int swaps = 0;

        for (int i = 0; i < N; i++) {
            if (visited[i] || map.get(arr[i]) == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = map.get(arr[j]);
                cycleSize++;
            }

            if (cycleSize > 0) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }
}
