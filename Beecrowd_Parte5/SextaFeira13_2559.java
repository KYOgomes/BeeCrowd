import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int N = scanner.nextInt();
            int[] sequencia = new int[N + 1]; // Índices de 1 a N
            for (int i = 1; i <= N; i++) {
                sequencia[i] = scanner.nextInt();
            }

            int Q = scanner.nextInt();
            for (int i = 0; i < Q; i++) {
                int op = scanner.nextInt();
                if (op == 1) {
                    int x = scanner.nextInt();
                    int v = scanner.nextInt();
                    sequencia[x] = v;
                } else if (op == 2) {
                    int x = scanner.nextInt();
                    int y = scanner.nextInt();
                    int z = scanner.nextInt();
                    int v = scanner.nextInt();
                    for (int j = x; j <= y; j++) {
                        if (sequencia[j] == z) {
                            sequencia[j] = v;
                        }
                    }
                } else if (op == 3) {
                    int x = scanner.nextInt();
                    int y = scanner.nextInt();
                    int soma = 0;
                    for (int j = x; j <= y; j++) {
                        soma += sequencia[j];
                    }
                    System.out.println(soma);
                }
            }
        }
        scanner.close();
    }
}
