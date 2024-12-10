import java.util.*;

public class Jogo_do_Quadrado_2067 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Leitura das dimensões do retângulo
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        // Leitura do retângulo
        int[][] retangulo = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                retangulo[i][j] = scanner.nextInt();
            }
        }

        // Leitura do número de consultas
        int Q = scanner.nextInt();
        int[] consultas = new int[Q];
        for (int i = 0; i < Q; i++) {
            consultas[i] = scanner.nextInt();
        }

        // Processamento de cada consulta
        for (int q = 0; q < Q; q++) {
            int S = consultas[q];
            boolean encontrouProdutoNaoZero = false;

            // Iterar sobre todos os possíveis quadrados SxS no retângulo
            for (int i = 0; i <= N - S; i++) {
                for (int j = 0; j <= M - S; j++) {
                    // Calcular o produto dos elementos do quadrado SxS
                    long produto = 1;
                    for (int di = 0; di < S; di++) {
                        for (int dj = 0; dj < S; dj++) {
                            produto *= retangulo[i + di][j + dj];
                            if (produto == 0) {
                                // Se encontrou um quadrado com produto zero, interrompe o cálculo
                                di = S; // sai do loop di
                                dj = S; // sai do loop dj
                            }
                        }
                    }

                    // Verificar se o produto foi diferente de zero
                    if (produto != 0) {
                        encontrouProdutoNaoZero = true;
                        break;
                    }
                }
                if (encontrouProdutoNaoZero) {
                    break;
                }
            }

            // Saída para essa consulta
            if (encontrouProdutoNaoZero) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }

        scanner.close();
    }
}
