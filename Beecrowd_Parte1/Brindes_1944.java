import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Brindes {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        List<String> inicial = new ArrayList<>();
        inicial.add("E C A F");
        
        LinkedList<String> painel = new LinkedList<>(inicial);
        int brindes = 0;

        int n = input.nextInt();
        input.nextLine();  // Consumir a quebra de linha após o número

        for (int i = 0; i < n; i++) {
            String a = input.nextLine();
            if (a.equals(painel.getFirst())) {
                painel.removeFirst();
                brindes++;
                if (painel.isEmpty()) {
                    painel = new LinkedList<>(inicial);
                }
            } else {
                painel.addFirst(new StringBuilder(a).reverse().toString());
            }
        }

        System.out.println(brindes);
        input.close();
    }
}
