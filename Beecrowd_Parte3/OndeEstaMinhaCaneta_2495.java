import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        while (sc.hasNext()) {
            int N = sc.nextInt();
            long sumTotal = (long) N * (N + 1) / 2;
            long sumReturned = 0;
            
            for (int i = 0; i < N - 1; i++) {
                int returnedPen = sc.nextInt();
                sumReturned += returnedPen;
            }
            
            long missingPen = sumTotal - sumReturned;
            System.out.println(missingPen);
        }
        
        sc.close();
    }
}
