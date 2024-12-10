import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt(); // Número de prédios
        int L = scanner.nextInt(); // Largura dos prédios
        int D = scanner.nextInt(); // Espaçamento entre os prédios

        int[] heights = new int[N];
        for (int i = 0; i < N; i++) {
            heights[i] = scanner.nextInt(); // Altura dos prédios
        }

        // Calcula o intervalo de tempo de luz solar (16 horas)
        double daylightMinutes = 16.0 * 60.0; // Em minutos

        // Calcula a área total de luz solar
        double totalSunlightArea = 0.0;
        for (int i = 0; i < N; i++) {
            // Altura do prédio em relação ao solo
            int h = heights[i];

            // Ângulo de inclinação do sol em relação ao solo
            double angle = Math.atan((double) h / (double) (L + D));

            // Largura do segmento de jardim que recebe luz solar
            double sunlightWidth = h / Math.tan(angle);

            // Área do segmento de jardim
            double segmentArea = sunlightWidth * L;

            totalSunlightArea += segmentArea;
        }

        // Tempo total de luz solar
        double totalSunlightTime = totalSunlightArea / L;

        // Imprime o resultado com 2 casas decimais
        System.out.printf("%.2f%n", totalSunlightTime);
        
        scanner.close();
    }
}
