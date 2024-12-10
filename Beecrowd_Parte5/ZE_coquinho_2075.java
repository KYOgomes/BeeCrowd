import java.util.*;

public class ZE_coquinho_2075 {

    static int T;
    static List<String>[] memo;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        T = scanner.nextInt();
        scanner.nextLine(); // Consume the newline after T
        
        memo = new ArrayList[51]; // Memoization array for lengths up to 50
        for (int i = 0; i <= 50; i++) {
            memo[i] = new ArrayList<>();
        }
        
        while (T-- > 0) {
            int N = scanner.nextInt();
            int K = scanner.nextInt();
            scanner.nextLine(); // Consume the newline after K
            
            generateMalformedSculptures(N); // Generate all malformed sculptures of length N
            
            if (K >= memo[N].size()) {
                System.out.println("-1");
            } else {
                System.out.println(memo[N].get(K));
            }
        }
        
        scanner.close();
    }

    static void generateMalformedSculptures(int N) {
        if (N == 0 || !memo[N].isEmpty()) {
            return; // Return if sculptures of length N are already generated
        }
        
        if (N == 1) {
            memo[N].add("()");
            return;
        }
        
        // Generate all sculptures of length N-1
        generateMalformedSculptures(N - 1);
        
        // Option 1: Start with '(' and end with ')', with a malformed sculpture of length N-1 in between
        for (String s : memo[N - 1]) {
            memo[N].add("(" + s + ")");
        }
        
        // Option 2: Add '()' in front of a malformed sculpture of length N-2
        if (N > 2) {
            generateMalformedSculptures(N - 2);
            for (String s : memo[N - 2]) {
                memo[N].add("()" + s);
            }
        }
    }
}