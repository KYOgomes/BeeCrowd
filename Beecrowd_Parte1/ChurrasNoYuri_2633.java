import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            scanner.nextLine(); // Consume newline after integer

            List<String[]> lines = new ArrayList<>();

            // Leitura dos dados e processamento
            for (int i = 0; i < n; i++) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");
                lines.add(parts);
            }

            // Ordenação pela segunda coluna como inteiro
            Collections.sort(lines, (a, b) -> Integer.parseInt(a[1]) - Integer.parseInt(b[1]));

            // Construção da lista de resultados
            List<String> result = new ArrayList<>();
            for (String[] parts : lines) {
                result.add(parts[0]);
            }

            // Saída do resultado
            System.out.println(String.join(" ", result));
        }

        scanner.close();
    }
}
