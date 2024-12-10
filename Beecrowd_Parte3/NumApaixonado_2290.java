import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int N = scanner.nextInt();
            if (N == 0) {
                break;
            }

            // Utilizamos um HashSet para encontrar os números apaixornados
            Set<Long> numbers = new HashSet<>();
            for (int i = 0; i < N; i++) {
                long num = scanner.nextLong();
                if (numbers.contains(num)) {
                    numbers.remove(num); // Remove se já estava presente
                } else {
                    numbers.add(num); // Adiciona se não estava presente
                }
            }

            // Convertendo o HashSet para um array e ordenando
            Long[] apaixonados = numbers.toArray(new Long[0]);
            Arrays.sort(apaixonados);

            // Imprimindo os números apaixornados
            System.out.println(apaixonados[0] + " " + apaixonados[1]);
        }
    }
}
