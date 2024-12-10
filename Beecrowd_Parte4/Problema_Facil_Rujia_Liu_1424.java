import java.util.*;
import java.io.*;

public class Problema_Facil_Rujia_Liu_1424 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] arr = new int[n];
            Map<Integer, List<Integer>> occurrences = new HashMap<>();
            
            // Ler o vetor e armazenar as ocorrências
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
                if (!occurrences.containsKey(arr[i])) {
                    occurrences.put(arr[i], new ArrayList<>());
                }
                occurrences.get(arr[i]).add(i + 1); // Armazenando como 1-indexado
            }
            
            // Processar as consultas
            for (int i = 0; i < m; i++) {
                int k = sc.nextInt();
                int v = sc.nextInt();
                
                if (occurrences.containsKey(v) && occurrences.get(v).size() >= k) {
                    System.out.println(occurrences.get(v).get(k - 1));
                } else {
                    System.out.println(0);
                }
            }
        }
        
        sc.close();
    }
}