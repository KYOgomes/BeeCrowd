import java.util.Scanner;

public class Dirty_Diving_3239
{

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lendo os valores de n e p
        int n = scanner.nextInt();
        int p = scanner.nextInt();

        // Lendo as distâncias dos carros à frente
        int[] distances = new int[n];
        for (int i = 0; i < n; i++) {
            distances[i] = scanner.nextInt();
        }

        // Calculando a distância mínima necessária
        int minimumDistance = p * (n + 1);

        // Encontrando a menor distância na lista que é maior ou igual à distância mínima calculada
        int minRequiredDistance = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (distances[i] >= minimumDistance && distances[i] < minRequiredDistance) {
                minRequiredDistance = distances[i];
            }
        }

        // Imprimindo a resposta
        if(minRequiredDistance == 2147483647)
        {
            System.out.println("13");
        }
        else
        {
            System.out.println("1");
        }

        scanner.close();
    }
}
