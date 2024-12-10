import java.util.*;

public class Parque_Jurassico_3045 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testNumber = 1;
        
        while (true) {
            String s1 = scanner.nextLine();
            if (s1.equals("#")) break;
            String s2 = scanner.nextLine();
            
            // Calcula o Shortest Common Supersequence (SCS)
            String scs = calculateSCS(s1, s2);
            
            // Imprime o resultado no formato especificado
            System.out.println("Teste " + testNumber++);
            System.out.println(scs);
            System.out.println();
        }
        
        scanner.close();
    }
    
    // Função para calcular o Shortest Common Supersequence (SCS)
    private static String calculateSCS(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();
        
        // Tabela para armazenar o tamanho do SCS de s1[0..i-1] e s2[0..j-1]
        int[][] dp = new int[m+1][n+1];
        
        // Preenche a tabela dp
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (s1.charAt(i-1) == s2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // Tamanho do SCS é dp[m][n]
        int scsLength = dp[m][n];
        
        // Constrói o SCS usando a tabela dp
        StringBuilder sb = new StringBuilder();
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (s1.charAt(i-1) == s2.charAt(j-1)) {
                sb.append(s1.charAt(i-1));
                i--;
                j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                sb.append(s1.charAt(i-1));
                i--;
            } else {
                sb.append(s2.charAt(j-1));
                j--;
            }
        }
        
        // Adiciona os caracteres restantes de s1 e s2
        while (i > 0) {
            sb.append(s1.charAt(i-1));
            i--;
        }
        while (j > 0) {
            sb.append(s2.charAt(j-1));
            j--;
        }
        
        // Inverte a string construída, pois foi montada de trás para frente
        return sb.reverse().toString();
    }
}
