import java.util.Scanner;

public class Banco_do_Farao_2071 {

    // Função para calcular a soma de um subarray máximo e o seu tamanho
    public static void encontrarMaximoSubarray(int[] contas, int inicio, int fim, Result result) {
        int somaAtual = 0;
        int melhorSoma = Integer.MIN_VALUE;
        int comprimentoAtual = 0;
        int melhorComprimento = 0;

        for (int i = inicio; i <= fim; i++) {
            somaAtual += contas[i];
            comprimentoAtual++;

            if (somaAtual > melhorSoma || (somaAtual == melhorSoma && comprimentoAtual > melhorComprimento)) {
                melhorSoma = somaAtual;
                melhorComprimento = comprimentoAtual;
            }

            if (somaAtual < 0) {
                somaAtual = 0;
                comprimentoAtual = 0;
            }
        }

        result.somaMaxima = melhorSoma;
        result.comprimentoMaximo = melhorComprimento;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();

        while (T-- > 0) {
            int N = scanner.nextInt();
            int[] contas = new int[N + 1];

            for (int i = 1; i <= N; i++) {
                contas[i] = scanner.nextInt();
            }

            int Q = scanner.nextInt();

            for (int i = 0; i < Q; i++) {
                int A = scanner.nextInt();
                int B = scanner.nextInt();

                Result result = new Result();
                encontrarMaximoSubarray(contas, A, B, result);
                System.out.println(result.somaMaxima + " " + result.comprimentoMaximo);
            }
        }

        scanner.close();
    }

    // Classe para armazenar os resultados da função encontrarMaximoSubarray
    static class Result {
        int somaMaxima;
        int comprimentoMaximo;
    }
}
