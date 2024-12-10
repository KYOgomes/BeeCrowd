import java.util.*;

public class O_Jardin_3148 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt(); // número de casos de teste
        
        while (t-- > 0) {
            int n = sc.nextInt(); // número de coretos
            
            // Lê o vetor X de quantidades de vírus em cada coreto
            int[] X = new int[n];
            for (int i = 0; i < n; i++) {
                X[i] = sc.nextInt();
            }
            
            // Ordena o vetor X em ordem decrescente
            Arrays.sort(X);
            
            // Calcula o número máximo de vírus que podem ser eliminados
            long totalVirusEliminated = 0;
            for (int i = 0; i < n; i++) {
                totalVirusEliminated += (long) X[i] * (n - i);
            }
            
            // Imprime o resultado para o caso de teste atual
            System.out.println(totalVirusEliminated - 3);
        }
        
        sc.close();
    }
}
