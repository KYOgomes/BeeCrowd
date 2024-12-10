import java.util.Scanner;

public class Empurrando_Blocos_1874 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            int H = sc.nextInt();
            int P = sc.nextInt();
            int F = sc.nextInt();

            if (H == 0 && P == 0 && F == 0) {
                break;
            }

            int[][] pilhas = new int[H][P];
            int[] alturas = new int[P];
            int[] fila = new int[F];

            // Ler as pilhas
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < P; j++) {
                    pilhas[i][j] = sc.nextInt();
                    if (pilhas[i][j] == 1) {
                        alturas[j]++;
                    }
                }
            }

            // Ler a fila
            for (int i = 0; i < F; i++) {
                fila[i] = sc.nextInt();
            }

            // Processar a fila de blocos
            for (int i = 0; i < F; i++) {
                int bloco = fila[i];
                for (int j = P - 1; j >= 0; j--) {
                    if (alturas[j] < H) {
                        pilhas[alturas[j]][j] = bloco;
                        alturas[j]++;
                        break;
                    }
                }
            }

            // Imprimir o resultado
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < P; j++) {
                    if (j > 0) System.out.print(" ");
                    System.out.print(pilhas[i][j]);
                }
                System.out.println();
            }
            if (sc.hasNext()) {
                System.out.println();
            }
        }

        sc.close();
    }
}
