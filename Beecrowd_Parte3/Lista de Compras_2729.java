import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        scanner.nextLine(); // Consumir o newline após o número

        for (int i = 0; i < n; i++) {
            String[] linha = scanner.nextLine().split(" ");
            Arrays.sort(linha); // Ordena a linha

            ArrayList<String> lista = new ArrayList<>();
            String ultimo = "";

            for (String item : linha) {
                if (!item.equals(ultimo)) {
                    lista.add(item);
                    ultimo = item;
                }
            }

            System.out.println(String.join(" ", lista));
        }

        scanner.close();
    }
}
