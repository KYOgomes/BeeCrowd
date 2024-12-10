import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            int n = Integer.parseInt(scanner.nextLine().trim());

            if (n == 0) {
                break;
            }

            ArrayList<String> lista = new ArrayList<>();
            String linha = scanner.nextLine().trim();

            while (!linha.equals("0")) {
                lista.add(linha);
                linha = scanner.nextLine().trim();
            }

            Collections.sort(lista);

            for (String item : lista) {
                System.out.println(item);
            }

            System.out.println();
        }

        scanner.close();
    }
}
