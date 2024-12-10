//public class Numero_Da_Sorte_2855 {

    import java.util.*;

    public class Numero_Da_Sorte_2855 {
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
    
            while (scanner.hasNext()) {
                int N = scanner.nextInt();
                List<Integer> sequence = new ArrayList<>();
                for (int i = 0; i < N; i++) {
                    sequence.add(scanner.nextInt());
                }
                int M = scanner.nextInt();
    
                int index = sequence.indexOf(M);
                if (index == -1) {
                    System.out.println("N");
                    continue;
                }
    
                int step = 2;
                while (index >= step) {
                    for (int i = step - 1; i < sequence.size(); i += step) {
                        sequence.remove(i--);
                    }
                    index = sequence.indexOf(M);
                    step++;
                }
    
                if (index != -1) {
                    System.out.println("Y");
                } else {
                    System.out.println("N");
                }
            }
    
            scanner.close();
        }
    }
