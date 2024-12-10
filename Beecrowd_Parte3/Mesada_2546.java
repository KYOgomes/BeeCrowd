import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int N = scanner.nextInt();
            int Q = scanner.nextInt();
            int[] mesada = new int[N + 1]; // Índices de 1 a N

            for (int i = 1; i <= N; i++) {
                mesada[i] = scanner.nextInt();
            }

            for (int i = 0; i < Q; i++) {
                char op = scanner.next().charAt(0);
                int x = scanner.nextInt();
                int y = scanner.nextInt();

                if (op == 'A') {
                    int v = scanner.nextInt();
                    for (int j = x; j <= y; j++) {
                        mesada[j] += v;
                    }
                } else if (op == 'C') {
                    int maxMesada = Integer.MIN_VALUE;
                    int neto = -1;
                    for (int j = x; j <= y; j++) {
                        if (mesada[j] > maxMesada) {
                            maxMesada = mesada[j];
                            neto = j;
                        }
                    }
                    System.out.println(neto);
                }
            }
        }
        scanner.close();
    }
}
