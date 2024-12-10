import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        
        while ((line = br.readLine()) != null) {
            int T = Integer.parseInt(line.trim());
            if (T == 0) break;
            
            HashMap<String, String> connections = new HashMap<>();
            boolean isFunction = true;
            boolean invertible = true;
            
            for (int i = 0; i < T; i++) {
                String[] parts = br.readLine().split(" -> ");
                String X = parts[0];
                String Y = parts[1];
                
                if (connections.containsKey(X)) {
                    if (!connections.get(X).equals(Y)) {
                        isFunction = false;
                    }
                } else {
                    connections.put(X, Y);
                }
            }
            
            if (!isFunction) {
                System.out.println("Not a function.");
            } else {
                // Check if invertible
                HashMap<String, String> reverseConnections = new HashMap<>();
                for (String key : connections.keySet()) {
                    String value = connections.get(key);
                    if (reverseConnections.containsKey(value)) {
                        invertible = false;
                        break;
                    }
                    reverseConnections.put(value, key);
                }
                
                if (invertible) {
                    System.out.println("Invertible.");
                } else {
                    System.out.println("Not invertible.");
                }
            }
        }
        
        br.close();
    }
}
