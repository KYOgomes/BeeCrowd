import java.util.*;

public class ZE_coquinho_2 {

    static int T;
    static List<String>[] memo;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        T = scanner.nextInt();
        scanner.nextLine(); // Consume the newline after T
        
        memo = new ArrayList[51]; // Memoization array for lengths up to 50
        for (int i = 1; i <= 50; i++) {
            memo[i] = new ArrayList<>();
        }
        
        while (T-- > 0) {
            int N = scanner.nextInt();
            int K = scanner.nextInt();
            scanner.nextLine(); // Consume the newline after K
            
            String result = generateMalformedSculpture(N, K - 1); // K-1 because K is 1-based index
            
            if (result == null) {
                System.out.println("-1");
            } else {
                System.out.println(result);
            }
        }
        
        scanner.close();
    }

    static String generateMalformedSculpture(int N, int K) {
        if (N == 0) {
            return ""; // Base case: empty sculpture
        }
        
        if (memo[N].size() > K) {
            return memo[N].get(K); // Return from memoization if already computed
        }
        
        String result = null;
        List<String> currentList = memo[N];
        
        // Generate all sculptures of length N in lexicographical order
        if (N > 0) {
            // Option 1: Start with '(' and end with ')', with a malformed sculpture of length N-1 in between
            if (K >= 0) {
                String subResult = generateMalformedSculpture(N - 1, K);
                if (subResult != null) {
                    result = "(" + subResult + ")";
                    currentList.add(result);
                    K -= 1; // Decrease K because we found a sculpture here
                }
            }
        }
        
        if (N > 1) {
            // Option 2: Add '()' in front of a malformed sculpture of length N-2
            if (K >= 0) {
                String subResult = generateMalformedSculpture(N - 2, K);
                if (subResult != null) {
                    result = "()" + subResult;
                    currentList.add(result);
                    K -= 1; // Decrease K because we found a sculpture here
                }
            }
        }
        
        // Return the generated sculpture or null if K is out of bounds
        return (K < 0) ? null : result;
    }
}
