import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int N = scanner.nextInt();
            int[] fibra = new int[N];
            for (int i = 0; i < N; i++) {
                fibra[i] = scanner.nextInt();
            }

            long totalCardapios = 0;
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    for (int k = j + 1; k < N; k++) {
                        if (fibra[i] > fibra[j] && fibra[j] > fibra[k]) {
                            totalCardapios++;
                        }
                    }
                }
            }

            System.out.println(totalCardapios);
        }
        scanner.close();
    }
}
