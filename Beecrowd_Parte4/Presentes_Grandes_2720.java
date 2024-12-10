import java.util.Arrays;
import java.util.Scanner;

class Present {
    int id;
    long volume;

    Present(int id, long volume) {
        this.id = id;
        this.volume = volume;
    }
}

public class Presentes_Grandes_2720 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();

        for (int t = 0; t < T; t++) {
            int N = scanner.nextInt();
            int K = scanner.nextInt();
            Present[] presents = new Present[N];

            for (int i = 0; i < N; i++) {
                int id = scanner.nextInt();
                long volume = 1L * scanner.nextInt() * scanner.nextInt() * scanner.nextInt();
                presents[i] = new Present(id, volume);
            }

            Arrays.sort(presents, (a, b) -> {
                if (b.volume != a.volume) {
                    return Long.compare(b.volume, a.volume);
                } else {
                    return Integer.compare(a.id, b.id);
                }
            });

            int[] ids = new int[K];
            for (int i = 0; i < K; i++) {
                ids[i] = presents[i].id;
            }

            Arrays.sort(ids);

            for (int i = 0; i < K; i++) {
                if (i > 0) {
                    System.out.print(" ");
                }
                System.out.print(ids[i]);
            }

            System.out.println();
        }

        scanner.close();
    }
}