import java.util.*;
//saida errada
public class Onde_Estao_as_Bolhas_1388 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int N = sc.nextInt();
            int M = sc.nextInt();

            if (N == 0 && M == 0) {
                break;
            }

            int[] swaps = new int[M];
            for (int i = 0; i < M; i++) {
                swaps[i] = sc.nextInt();
            }

            int[] sequence = new int[N];
            for (int i = 0; i < N; i++) {
                sequence[i] = N - i;
            }

            for (int i = 0; i < M; i++) {
                int pos = N - 1 - swaps[i];
                int temp = sequence[pos];
                for (int j = pos; j < N - 1; j++) {
                    sequence[j] = sequence[j + 1];
                }
                sequence[N - 1] = temp;
            }

            for (int i = 0; i < N; i++) {
                if (i > 0) {
                    System.out.print(" ");
                }
                System.out.print(sequence[i]);
            }
            System.out.println();
        }

        sc.close();
    }
}