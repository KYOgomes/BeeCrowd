import java.util.Scanner;

public class Numero_casal_solteirao_Solteirona_1535 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            int n = sc.nextInt();
            processSingleNumber(n);
        }

        sc.close();
    }

    // Verifica se o número N é um "número casal quadrado" e imprime a e b se for
    // Caso contrário, imprime "Bachelor Number." ou "Spinster Number."
    private static void processSingleNumber(int n) {
        if (n < 0) {
            System.out.println("Bachelor Number.");
            return;
        }

        // Verifica se é possível representar n como a^2 - b^2
        int a = 1;
        while (true) {
            int a2 = a * a;
            int b2 = a2 - n;
            if (b2 >= 0) {
                int b = (int) Math.sqrt(b2);
                if (b * b == b2 && a > b) {
                    System.out.println(a + " " + b);
                    return;
                }
            }
            a++;
            if (a2 > n) {
                break;
            }
        }

        if (n % 2 == 0) {
            System.out.println("Bachelor Number.");
        } else {
            System.out.println("Spinster Number.");
        }
    }
}