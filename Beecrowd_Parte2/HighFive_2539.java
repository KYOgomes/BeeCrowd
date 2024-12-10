import java.util.Scanner;

public class Main {

    static class FenwickTree {
        int[] tree;
        int size;

        public FenwickTree(int size) {
            this.size = size;
            tree = new int[size + 1];
        }

        public void update(int index, int delta) {
            while (index <= size) {
                tree[index] += delta;
                index += index & -index;
            }
        }

        public int query(int index) {
            int sum = 0;
            while (index > 0) {
                sum += tree[index];
                index -= index & -index;
            }
            return sum;
        }

        public int queryRange(int left, int right) {
            return query(right) - query(left - 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            int N = sc.nextInt();
            int[] athletes = new int[N];
            for (int i = 0; i < N; i++) {
                athletes[i] = sc.nextInt();
            }

            FenwickTree fenwickTree = new FenwickTree(N);
            for (int i = 1; i <= N; i++) {
                fenwickTree.update(i, 1);
            }

            long totalHighFives = 0;
            for (int i = 0; i < N; i++) {
                int athleteNumber = athletes[i];
                fenwickTree.update(athleteNumber, -1);
                totalHighFives += fenwickTree.queryRange(athleteNumber + 1, N);
            }

            System.out.println(totalHighFives);
        }

        sc.close();
    }
}
