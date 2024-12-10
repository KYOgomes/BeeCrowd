import java.util.Scanner;

public class Jogos_Divertidos_3207 {

    // Função para determinar o vencedor para um caso de teste
    public static String determineWinner(double X, double[] F) {
        int K = F.length;

        // Verifica se o tamanho atual do planeta é menor ou igual a 1 gob
        if (X <= 1.0) {
            // Se já está menor ou igual a 1, Nils ganha porque foi a última jogada válida
            return "Nils";
        }

        // Verifica se há alguma jogada vencedora para Nils
        for (int i = 0; i < K; i++) {
            double novoTamanho = X * F[i];
            if (novoTamanho <= 1.0) {
                return "Nils";
            }
        }

        // Se não houver jogada vencedora para Nils, Mikael ganha
        return "Mikael";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // número de casos de teste

        for (int i = 0; i < N; i++) {
            double X = scanner.nextDouble(); // tamanho inicial do planeta
            int K = scanner.nextInt(); // número de armas-FATOR disponíveis
            double[] F = new double[K]; // array para armazenar os valores das armas-FATOR

            for (int j = 0; j < K; j++) {
                F[j] = scanner.nextDouble();
            }

            // Determina o vencedor para o caso de teste atual
            String winner = determineWinner(X, F);
            System.out.println(winner);
        }

        scanner.close();
    }
}
