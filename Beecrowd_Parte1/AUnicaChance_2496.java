import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Número de casos de teste
        
        for (int i = 0; i < n; i++) {
            int m = scanner.nextInt(); // Tamanho da string s
            String s = scanner.next(); // String s
            
            int trocas = 0;
            for (int j = 0; j < m; j++) {
                char expectedChar = (char) ('A' + j);
                if (s.charAt(j) != expectedChar) {
                    trocas++;
                }
            }
            
            if (trocas < 3) {
                System.out.println("There are the chance.");
            } else {
                System.out.println("There aren't the chance.");
            }
        }
        
        scanner.close();
    }
}
