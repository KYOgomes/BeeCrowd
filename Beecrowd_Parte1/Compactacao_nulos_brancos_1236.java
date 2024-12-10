import java.util.Scanner;

public class Compactacao_nulos_brancos_1236 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        scanner.nextLine(); // Consume the newline after reading N
        
        for (int t = 0; t < N; t++) {
            String line = scanner.nextLine();
            StringBuilder compressed = new StringBuilder();
            
            int i = 0;
            while (i < line.length()) {
                char currentChar = line.charAt(i);
                
                if (currentChar == '0') {
                    int count = 0;
                    while (i < line.length() && line.charAt(i) == '0') {
                        count++;
                        i++;
                    }
                    
                    if (count > 2) {
                        compressed.append('#').append(count);
                    } else {
                        for (int j = 0; j < count; j++) {
                            compressed.append('0');
                        }
                    }
                    
                } else if (currentChar == ' ') {
                    int count = 0;
                    while (i < line.length() && line.charAt(i) == ' ') {
                        count++;
                        i++;
                    }
                    
                    if (count > 2) {
                        compressed.append('$').append(count);
                    } else {
                        for (int j = 0; j < count; j++) {
                            compressed.append(' ');
                        }
                    }
                    
                } else {
                    compressed.append(currentChar);
                    i++;
                }
            }
            
            System.out.println(compressed.toString());
        }
        
        scanner.close();
    }
}