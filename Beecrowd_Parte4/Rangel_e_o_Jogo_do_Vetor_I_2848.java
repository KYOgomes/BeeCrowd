import java.util.*;

public class Rangel_e_o_Jogo_do_Vetor_I_2848 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int Q = scanner.nextInt();
        int[] numbers = new int[N];
        for (int i = 0; i < N; i++) {
            numbers[i] = scanner.nextInt();
        }

        for (int i = 0; i < Q; i++) {
            int L = scanner.nextInt() - 1;
            int R = scanner.nextInt() - 1;
            int K = scanner.nextInt() - 1;
            int G = scanner.nextInt();
            int D = scanner.nextInt();

            int[] subArray = Arrays.copyOfRange(numbers, L, R + 1);
            Arrays.sort(subArray);
            int Kth = subArray[K];
            int count = 0;
            for (int num : subArray) {
                if (num == Kth) {
                    count++;
                }
            }

            System.out.print(Kth + " " + count + " ");
            if (Math.abs(G - count) < Math.abs(D - count)) {
                System.out.println("G");
            } else if (Math.abs(G - count) > Math.abs(D - count)) {
                System.out.println("D");
            } else {
                System.out.println("E");
            }
        }

        scanner.close();
    }
}