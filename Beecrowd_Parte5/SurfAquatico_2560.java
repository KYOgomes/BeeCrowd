import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int N = scanner.nextInt();
            int B = scanner.nextInt();
            int[] notas = new int[N];
            for (int i = 0; i < N; i++) {
                notas[i] = scanner.nextInt();
            }

            long resultado = 0;

            for (int i = 0; i <= N - B; i++) {
                int minNota = Integer.MAX_VALUE;
                int maxNota = Integer.MIN_VALUE;
                long soma = 0;

                for (int j = i; j < i + B; j++) {
                    soma += notas[j];
                    minNota = Math.min(minNota, notas[j]);
                    maxNota = Math.max(maxNota, notas[j]);
                }

                resultado += (soma - minNota - maxNota);
            }

            System.out.println(resultado);
        }
        scanner.close();
    }
}
