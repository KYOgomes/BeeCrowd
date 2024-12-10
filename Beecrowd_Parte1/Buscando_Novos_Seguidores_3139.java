import java.util.Scanner;

public class Buscando_Novos_Seguidores_3139 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Leitura dos valores de entrada
        int N = scanner.nextInt(); // número atual de seguidores
        int M = scanner.nextInt(); // número mínimo de seguidores necessários

        int[] Di = new int[30];
        for (int i = 0; i < 30; i++) {
            Di[i] = scanner.nextInt(); // leitura dos inscritos nos últimos 30 dias
        }

        scanner.close();

        // Calcular a média dos últimos 30 dias
        int soma = 0;
        for (int i = 0; i < 30; i++) {
            soma += Di[i];
        }
        int avg30 = (int) Math.ceil((double) soma / 30);

        // Calcular o número de dias necessários
        int days = 0;
        if (N >= M) {
            days = 0; // N já é maior ou igual a M
        } else {
            days = (int) Math.ceil((double) (M - N) / avg30);
        }

        // Imprimir o resultado
        System.out.println(days);
    }
}
