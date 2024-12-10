import java.util.Scanner;

public class O_Campeao_2040 {
    static class Time {
        String nome;
        int pontos;

        Time(String nome, int pontos) {
            this.nome = nome;
            this.pontos = pontos;
        }
    }

    // Função para encontrar o índice de um time no vetor de times
    static int indexOf(Time[] times, int numTimes, String nome) {
        for (int i = 0; i < numTimes; i++) {
            if (times[i].nome.equals(nome)) {
                return i;
            }
        }
        return -1; // Time não encontrado
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int N = scanner.nextInt();
            if (N == 0) break;

            Time[] times = new Time[N];

            // Leitura dos times e suas pontuações iniciais
            for (int i = 0; i < N; i++) {
                String nome = scanner.next();
                int pontos = scanner.nextInt();
                times[i] = new Time(nome, pontos);
            }

            // Processamento dos jogos da última rodada
            int numJogos = N / 2;
            for (int i = 0; i < numJogos; i++) {
                String timeA = scanner.next();
                int golsA = scanner.nextInt();
                int golsB = scanner.nextInt();
                String timeB = scanner.next();

                // Encontrar os índices dos times no vetor
                int idxA = indexOf(times, N, timeA);
                int idxB = indexOf(times, N, timeB);

                // Atualizar pontuações conforme o resultado do jogo
                if (golsA > golsB) {
                    times[idxA].pontos += golsA * 3 + 5; // 3 pontos por gol + 5 pontos pela vitória
                    times[idxB].pontos += golsB * 3; // 3 pontos por gol
                } else if (golsA < golsB) {
                    times[idxA].pontos += golsA * 3; // 3 pontos por gol
                    times[idxB].pontos += golsB * 3 + 5; // 3 pontos por gol + 5 pontos pela vitória
                } else {
                    times[idxA].pontos += golsA * 3; // 3 pontos por gol
                    times[idxB].pontos += golsB * 3; // 3 pontos por gol
                }
            }

            // Encontrar o time com maior pontuação (o campeão)
            int idxCampeao = 0;
            for (int i = 1; i < N; i++) {
                if (times[i].pontos > times[idxCampeao].pontos) {
                    idxCampeao = i;
                }
            }

            // Determinar a saída conforme especificado
            if (times[idxCampeao].nome.equals("Sport")) {
                System.out.printf("O Sport foi o campeao com %d pontos :D\n", times[idxCampeao].pontos);
            } else {
                System.out.printf("O Sport nao foi o campeao. O time campeao foi o %s com %d pontos :(\n", times[idxCampeao].nome, times[idxCampeao].pontos);
            }
            System.out.println(); // linha em branco após cada caso de teste
        }

        scanner.close();
    }
}
