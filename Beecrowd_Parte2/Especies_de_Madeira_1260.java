import java.util.*;
import java.io.*;

public class Especies_de_Madeira_1260 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine().trim());
        br.readLine(); // Leitura da linha em branco
        
        for (int i = 0; i < N; i++) {
            Map<String, Integer> speciesCount = new TreeMap<>();
            int totalTrees = 0;
            String line;
            
            while ((line = br.readLine()) != null && !line.isEmpty()) {
                speciesCount.put(line, speciesCount.getOrDefault(line, 0) + 1);
                totalTrees++;
            }
            
            for (Map.Entry<String, Integer> entry : speciesCount.entrySet()) {
                String species = entry.getKey();
                int count = entry.getValue();
                double percentage = (count / (double) totalTrees) * 100;
                System.out.printf("%s %.4f%n", species, percentage);
            }
            
            if (i < N - 1) {
                System.out.println();
                br.readLine(); // Leitura da linha em branco entre casos de teste
            }
        }
        
        br.close();
    }
}