import java.util.*;
import java.io.*;

public class O_Pior_Clime_de_Todos_3210
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder output = new StringBuilder();
        String line;
        
        while (!(line = br.readLine()).equals("0 0")) {
            // Read the number of years with rainfall info
            int n = Integer.parseInt(line.trim());
            
            // Map to store rainfall info by year
            Map<Integer, Integer> rainfall = new HashMap<>();
            TreeSet<Integer> years = new TreeSet<>();
            
            // Read rainfall data
            for (int i = 0; i < n; i++) {
                String[] parts = br.readLine().trim().split(" ");
                int year = Integer.parseInt(parts[0]);
                int rain = Integer.parseInt(parts[1]);
                rainfall.put(year, rain);
                years.add(year);
            }
            
            // Read number of queries
            int m = Integer.parseInt(br.readLine().trim());
            
            for (int i = 0; i < m; i++) {
                String[] parts = br.readLine().trim().split(" ");
                int y = Integer.parseInt(parts[0]);
                int x = Integer.parseInt(parts[1]);
                
                if (!rainfall.containsKey(x) || !rainfall.containsKey(y)) {
                    output.append("maybe\n");
                } else {
                    int rainX = rainfall.get(x);
                    int rainY = rainfall.get(y);
                    
                    if (rainX != rainY) {
                        output.append("false\n");
                    } else {
                        SortedSet<Integer> subset = years.subSet(y + 1, x);
                        boolean isTrue = true;
                        for (int year : subset) {
                            if (rainfall.containsKey(year) && rainfall.get(year) >= rainX) {
                                isTrue = false;
                                break;
                            }
                        }
                        if (isTrue) {
                            if (subset.isEmpty()) {
                                output.append("true\n");
                            } else {
                                int first = subset.first();
                                int last = subset.last();
                                boolean completeData = true;
                                for (int i = first; i <= last; i++) {
                                    if (!rainfall.containsKey(i)) {
                                        completeData = false;
                                        break;
                                    }
                                }
                                if (completeData) {
                                    output.append("true\n");
                                } else {
                                    output.append("maybe\n");
                                }
                            }
                        } else {
                            output.append("false\n");
                        }
                    }
                }
            }
            
            // Read blank line between test cases
            if (br.ready()) {
                br.readLine();
                output.append("\n");
            }
        }
        
        // Print all the output
        System.out.print(output.toString());
    }
}
