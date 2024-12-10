import java.util.Scanner;

class FenwickTree {
    private int[] tree;
    
    public FenwickTree(int size) {
        tree = new int[size + 1];
    }
    
    public void update(int index, int delta) {
        while (index < tree.length) {
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
}

public class Mega_Divisoes_3248 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] sequence = new int[n];
        
        for (int i = 0; i < n; i++) {
            sequence[i] = scanner.nextInt();
        }
        
        long[] rightSmaller = new long[n];
        long[] leftGreater = new long[n];
        
        FenwickTree fenwickTree = new FenwickTree(n);
        
        // Calculate rightSmaller
        for (int i = n - 1; i >= 0; i--) {
            rightSmaller[i] = fenwickTree.query(sequence[i] - 1);
            fenwickTree.update(sequence[i], 1);
        }
        
        // Reset the Fenwick Tree
        fenwickTree = new FenwickTree(n);
        
        // Calculate leftGreater
        for (int i = 0; i < n; i++) {
            leftGreater[i] = i - fenwickTree.query(sequence[i]);
            fenwickTree.update(sequence[i], 1);
        }
        
        // Count the number of triples
        long count = 0;
        for (int j = 0; j < n; j++) {
            count += leftGreater[j] * rightSmaller[j];
        }
        
        System.out.println(count);
        
        scanner.close();
    }
}
