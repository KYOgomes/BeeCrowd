import java.util.Scanner;

public class Fila_Supermercado_2065 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Leitura de N e M
        int N = scanner.nextInt(); // número de funcionários
        int M = scanner.nextInt(); // número de clientes

        // Leitura dos tempos vi
        int[] vi = new int[N];
        for (int i = 0; i < N; i++) {
            vi[i] = scanner.nextInt();
        }

        // Leitura dos números de itens cj
        int[] cj = new int[M];
        for (int i = 0; i < M; i++) {
            cj[i] = scanner.nextInt();
        }

        // Array para armazenar o tempo em que cada funcionário estará livre
        long[] tempoLivre = new long[N];

        // Variável para guardar o tempo total
        long tempoTotal = 0;

        // Processamento de cada cliente
        for (int j = 0; j < M; j++) {
            // Encontrar o funcionário livre mais rápido
            int funcionarioMaisRapido = 0;
            for (int k = 1; k < N; k++) {
                if (tempoLivre[k] < tempoLivre[funcionarioMaisRapido]) {
                    funcionarioMaisRapido = k;
                }
            }

            // Tempo de atendimento deste cliente pelo funcionário escolhido
            tempoLivre[funcionarioMaisRapido] += vi[funcionarioMaisRapido] * cj[j];

            // Atualiza o tempo total, se necessário
            if (tempoLivre[funcionarioMaisRapido] > tempoTotal) {
                tempoTotal = tempoLivre[funcionarioMaisRapido];
            }
        }

        // Imprime o tempo total necessário para atender todos os clientes
        System.out.println(tempoTotal);

        scanner.close();
    }
}
