import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Tamanho da sequência
        scanner.nextLine(); // Consumir a quebra de linha

        long[] sequence = new long[N];
        for (int i = 0; i < N; i++) {
            sequence[i] = Long.parseLong(scanner.nextLine(), 16);
        }
        scanner.close();

        long totalMin = Long.MAX_VALUE;
        long totalMax = Long.MIN_VALUE;
        long totalSum = 0;

        for (int i = 0; i < 16; i++) {
            long mask = 1L << i;
            long total = 0;

            for (long num : sequence) {
                long transformedNum = num & ~mask;
                total += transformedNum;
            }

            totalMin = Math.min(totalMin, total);
            totalMax = Math.max(totalMax, total);
            totalSum += total;
        }

        long modulo = 10000000 + 7; // 3b9aca07 em hexadecimal
        System.out.printf("%08x %08x %08x%n", totalMin % modulo, totalMax % modulo, totalSum % modulo);
    }
}
