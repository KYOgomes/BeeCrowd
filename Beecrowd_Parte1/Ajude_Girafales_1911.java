import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Ajude_Girafales_1911 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        while (true) {
            int N = sc.nextInt();
            sc.nextLine(); // Consume the newline after N
            
            if (N == 0) {
                break;
            }
            
            // Map to store original signatures
            Map<String, String> originalSignatures = new HashMap<>();
            
            // Read original signatures
            for (int i = 0; i < N; i++) {
                String nome = sc.next();
                String assinatura = sc.nextLine().trim(); // trim to remove leading space
                
                originalSignatures.put(nome.toLowerCase(), assinatura);
            }
            
            int M = sc.nextInt();
            sc.nextLine(); // Consume the newline after M
            
            int falsas = 0;
            
            // Check signatures in the attendance list
            for (int i = 0; i < M; i++) {
                String nome = sc.next();
                String assinatura = sc.nextLine().trim(); // trim to remove leading space
                
                String originalAssinatura = originalSignatures.get(nome.toLowerCase());
                
                if (originalAssinatura == null) {
                    continue; // It's guaranteed that all students in the attendance list have original signatures
                }
                
                // Compare signatures
                int differences = 0;
                for (int j = 0; j < originalAssinatura.length(); j++) {
                    char c1 = originalAssinatura.charAt(j);
                    char c2 = assinatura.charAt(j);
                    
                    if (Character.isUpperCase(c1) && Character.isLowerCase(c2) ||
                        Character.isLowerCase(c1) && Character.isUpperCase(c2)) {
                        differences++;
                    }
                }
                
                if (differences > 1) {
                    falsas++;
                }
            }
            
            // Output the result for the current test case
            System.out.println(falsas);
        }
        
        sc.close();
    }
}
