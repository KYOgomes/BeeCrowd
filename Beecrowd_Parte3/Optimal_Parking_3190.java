import java.util.Arrays;
import java.util.Scanner;

public class Optimal_Parking_3190 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); // número de casos de teste
        
        for (int caseNum = 1; caseNum <= t; caseNum++) {
            int n = scanner.nextInt(); // número de lojas
            int[] positions = new int[n];
            
            // Lê as posições das lojas
            for (int i = 0; i < n; i++) {
                positions[i] = scanner.nextInt();
            }
            
            // Ordena as posições das lojas
            Arrays.sort(positions);
            
            // A menor distância será entre a primeira e a última posição
            int minDistance = positions[n-1] - positions[0];
            
            // Imprime a menor distância para este caso de teste
            System.out.println(minDistance * 2);
        }
        
        scanner.close();
    }
}
