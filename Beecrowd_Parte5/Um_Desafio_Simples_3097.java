import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class FenwickTree {
    private int[] tree;
    private int maxVal;

    public FenwickTree(int maxSize) {
        this.tree = new int[maxSize + 1];
        this.maxVal = maxSize;
    }

    public void add(int idx, int value) {
        while (idx <= maxVal) {
            tree[idx] += value;
            idx += idx & -idx;
        }
    }

    public int sum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    public int rangeSum(int left, int right) {
        return sum(right) - sum(left - 1);
    }
}

public class Um_Desafio_Simples_3097 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int N = Integer.parseInt(tokenizer.nextToken());
        int Q = Integer.parseInt(tokenizer.nextToken());

        int[] array = new int[N + 1];
        tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 1; i <= N; i++) {
            array[i] = Integer.parseInt(tokenizer.nextToken());
        }

        FenwickTree fenwickTree = new FenwickTree(100000);
        int[] count = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            fenwickTree.add(array[i], 1);
            count[i] = 0;
        }

        StringBuilder output = new StringBuilder();
        for (int q = 0; q < Q; q++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int type = Integer.parseInt(tokenizer.nextToken());
            
            if (type == 1) {
                // Operação 1: Alterar o valor na posição A para Y
                int A = Integer.parseInt(tokenizer.nextToken());
                int Y = Integer.parseInt(tokenizer.nextToken());
                
                int currentVal = array[A];
                if (currentVal != Y) {
                    fenwickTree.add(currentVal, -1);
                    fenwickTree.add(Y, 1);
                    array[A] = Y;
                }
                
            } else if (type == 2) {
                // Operação 2: Consultar quantos números maiores que X existem no intervalo [A, B]
                int X = Integer.parseInt(tokenizer.nextToken());
                int A = Integer.parseInt(tokenizer.nextToken());
                int B = Integer.parseInt(tokenizer.nextToken());
                
                int greaterCount = fenwickTree.rangeSum(X + 1, 100000);
                output.append(greaterCount).append("\n");
            }
        }

        System.out.print(output);
    }
}
