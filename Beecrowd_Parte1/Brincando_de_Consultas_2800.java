import java.util.*;

public class Brincando_de_Consultas_2800 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int Q = scanner.nextInt();
        int[] array = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            array[i] = scanner.nextInt();
        }

        for (int i = 0; i < Q; i++) {
            int operation = scanner.nextInt();
            if (operation == 1) {
                int X = scanner.nextInt();
                int W = scanner.nextInt();
                array[X] = W;
            } else if (operation == 2) {
                int X = scanner.nextInt();
                int Y = scanner.nextInt();
                int W = scanner.nextInt();
                int count = 0;
                for (int j = X; j <= Y; j++) {
                    if (array[j] != W) {
                        count++;
                    }
                }
                System.out.println(count);
            }
        }
    }
}