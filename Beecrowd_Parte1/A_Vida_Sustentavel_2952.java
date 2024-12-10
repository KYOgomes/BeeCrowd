import java.util.*;

public class A_Vida_Sustentavel_2952 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Leitura do número de horas N
        int N = scanner.nextInt();
        scanner.nextLine(); // Consumir a quebra de linha após o número

        // Leitura das ações
        String actions = scanner.nextLine().trim();

        // Tabelas de custo de água e emissão de gases
        int[] waterUsage = {400, 100, 300, 700, 450, 0, 0};
        int[] gasEmission = {0, 100, 200, 300, 150, 100, 50};

        // Tabelas de nutrição e velocidade
        int[] nutrition = {300, 500, 400, 200, 1000, 0, 0};
        int[] speed = {0, 80, 60, 40, 20, 80, 50};

        // Array para guardar o custo benefício acumulado
        long[] costBenefit = new long[N + 1]; // +1 para incluir o índice 0

        // Calcula o custo benefício acumulado
        for (int i = 1; i <= N; i++) {
            char action = actions.charAt(i - 1);
            if (action != 'N') {
                int index = action - 'A';
                costBenefit[i] = costBenefit[i - 1];
                if (index >= 0 && index < 7) {
                    if (index < 4) {
                        costBenefit[i] += nutrition[index];
                        costBenefit[i] -= waterUsage[index];
                    } else {
                        costBenefit[i] += speed[index];
                        costBenefit[i] -= gasEmission[index];
                    }
                }
            } else {
                costBenefit[i] = costBenefit[i - 1];
            }
        }

        // Encontrar o maior e o menor intervalo de custo benefício
        long maxSubarraySum = Long.MIN_VALUE;
        long minSubarraySum = Long.MAX_VALUE;
        long currentSum = 0;

        for (int i = 1; i <= N; i++) {
            currentSum += costBenefit[i];
            if (currentSum > maxSubarraySum) {
                maxSubarraySum = currentSum;
            }
            if (currentSum < minSubarraySum) {
                minSubarraySum = currentSum;
            }
        }

        // Imprimir resultado
        System.out.println(maxSubarraySum + " " + minSubarraySum);

        scanner.close();
    }
}
