import java.util.Scanner;

class FenwickTree {
    int[] BIT;
    int size;

    public FenwickTree(int size) {
        this.size = size;
        BIT = new int[size + 1];
    }

    public void update(int idx, int delta) {
        while (idx <= size) {
            BIT[idx] += delta;
            idx += idx & -idx;
        }
    }

    public int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += BIT[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
}

public class Gonaldinho_2792 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] indices = new int[N];

        for (int i = 0; i < N; i++) {
            indices[i] = scanner.nextInt();
        }

        FenwickTree fenwickTree = new FenwickTree(N);

        // Result array to store the order of deletions
        int[] result = new int[N];

        // Process indices to be deleted from right to left
        for (int i = N - 1; i >= 0; i--) {
            int idx = indices[i];
            // Count how many elements are to the left of idx and have not been deleted yet
            result[i] = fenwickTree.query(idx - 1);
            // Mark idx as deleted
            fenwickTree.update(idx, 1);
        }

        // Print the result array
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(result[i]).append(" ");
        }
        System.out.println((sb.toString().trim()));

        scanner.close();
    }
}