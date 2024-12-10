import java.util.Scanner;

public class Organizador_de_Vagoes_1162 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine(); // Consumir o newline após o número N

        for (int k = 0; k < N; ++k) {
            int L = sc.nextInt();
            sc.nextLine(); // Consumir o newline após o número L

            int[] vagoes = new int[L];
            for (int i = 0; i < L; ++i) {
                vagoes[i] = sc.nextInt();
            }
            sc.nextLine(); // Consumir o newline após a última linha de vagoes

            int swaps = insertionSort(vagoes, L);
            System.out.printf("Optimal train swapping takes %d swaps.%n", swaps);
        }

        sc.close();
    }

    public static int insertionSort(int[] V, int n) {
        int trocas = 0;

        for (int i = 1; i < n; ++i) {
            int j = i;
            while (j > 0 && V[j] < V[j - 1]) {
                swap(V, j, j - 1);
                ++trocas;
                --j;
            }
        }

        return trocas;
    }

    public static void swap(int[] V, int i, int j) {
        int temp = V[i];
        V[i] = V[j];
        V[j] = temp;
    }
}
