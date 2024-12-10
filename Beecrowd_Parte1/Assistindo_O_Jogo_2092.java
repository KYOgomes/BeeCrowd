import java.util.Scanner;

public class Main {
    // Função para inicializar os times nas casas
    public static void initializeTeams(int N, int F, int A, int B, int C, int[] teams) {
        teams[0] = A % F;
        for (int i = 1; i < N; ++i) {
            teams[i] = (B * teams[i - 1] + C) % F;
        }
    }

    // Função para encontrar a próxima casa com o mesmo time no sentido horário
    public static int findClockwise(int[] teams, int N, int start, int team) {
        for (int i = 1; i < N; ++i) {
            int index = (start + i) % N;
            if (teams[index] == team) {
                return i;
            }
        }
        return N;
    }

    // Função para encontrar a próxima casa com o mesmo time no sentido anti-horário
    public static int findCounterClockwise(int[] teams, int N, int start, int team) {
        for (int i = 1; i < N; ++i) {
            int index = (start - i + N) % N;
            if (teams[index] == team) {
                return i;
            }
        }
        return N;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int F = scanner.nextInt();

        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();

        // Array para armazenar os times das casas
        int[] teams = new int[N];
        initializeTeams(N, F, A, B, C, teams);

        int M = scanner.nextInt();

        for (int i = 0; i < M; ++i) {
            int I = scanner.nextInt();
            int E = scanner.nextInt();
            --I; // Ajustar para índice zero

            teams[I] = E;

            int dcw = findClockwise(teams, N, I, E);
            int dccw = findCounterClockwise(teams, N, I, E);

            System.out.println(dccw + " " + dcw);
        }

        scanner.close();
    }
}
