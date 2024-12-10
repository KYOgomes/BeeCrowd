import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int caseNumber = 0;

        while (true) {
            int V = sc.nextInt();
            int P = sc.nextInt();
            int T = sc.nextInt();

            if (V == 0 && P == 0 && T == 0) break;

            caseNumber++;

            int[] checkpoints = new int[P];
            for (int i = 0; i < P; i++) {
                checkpoints[i] = sc.nextInt();
            }

            int[][] times = new int[T][P];
            for (int i = 0; i < T; i++) {
                for (int j = 0; j < P; j++) {
                    times[i][j] = sc.nextInt();
                }
            }

            int[] totalPoints = new int[T];

            for (int t = 0; t < T; t++) {
                for (int p = 0; p < P; p++) {
                    int expectedTimeInSeconds = (int) Math.round((double) checkpoints[p] / V * 3600);
                    int actualTimeInSeconds = times[t][p];
                    int difference = actualTimeInSeconds - expectedTimeInSeconds;

                    if (difference > 0) {
                        // Atraso, penalização de 1 ponto por segundo de atraso
                        int penaltyPoints = Math.min(difference, 1200); // Limite de 20 minutos (1200 segundos)
                        totalPoints[t] += penaltyPoints;
                    } else if (difference < 0) {
                        // Adiantamento, penalização de 2 pontos por segundo de adiantamento
                        int advancePoints = Math.min(-difference * 2, 1200); // Limite de 10 minutos (600 segundos)
                        totalPoints[t] += advancePoints;
                    }
                }
            }

            // Criar e ordenar times baseado nos pontos totais
            Team[] teams = new Team[T];
            for (int i = 0; i < T; i++) {
                teams[i] = new Team(i + 1, totalPoints[i]);
            }

            Arrays.sort(teams);
            
            // Saída formatada em ordem decrescente de pontos
            if (caseNumber > 1) {
                System.out.println();
            }

            for (int i = T - 1; i >= 0; i--) {
                System.out.print(" " + teams[i].number);
            }
            System.out.println();
        }

        sc.close();
    }

    static class Team implements Comparable<Team> {
        int number;
        int points;

        Team(int number, int points) {
            this.number = number;
            this.points = points;
        }

        @Override
        public int compareTo(Team other) {
            if (this.points != other.points) {
                return Integer.compare(this.points, other.points);
            } else {
                return Integer.compare(this.number, other.number);
            }
        }
    }
}
