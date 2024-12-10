import java.util.Scanner;

public class Fila_de_Desempregados_1119 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N, K, M;
        int[] v = new int[1000];
        int sel1 = -1, sel2 = -1, cont, i; // Inicializando com -1

        while (sc.hasNext()) {
            N = sc.nextInt();
            K = sc.nextInt();
            M = sc.nextInt();
            
            if (N == 0 && K == 0 && M == 0) break;
            
            int pos1 = 0;
            int pos2 = N - 1;

            // Inicialização do vetor v
            for (i = 0; i < N; i++) {
                v[i] = i + 1;
            }

            cont = 0;

            while (cont < N) {
                i = K; // Começa em K porque vamos contar a partir do próximo
                while (i > 0) {
                    if (v[pos1] > 0) {
                        i--;
                    }
                    if (i == 0) {
                        sel1 = pos1;
                    }
                    pos1 = (pos1 + 1) % N;
                }

                i = M; // Começa em M porque vamos contar a partir do próximo
                while (i > 0) {
                    if (v[pos2] > 0) {
                        i--;
                    }
                    if (i == 0) {
                        sel2 = pos2;
                    }
                    pos2 = (pos2 + N - 1) % N;
                }

                if (cont > 0) {
                    System.out.print(",");
                }
                if (sel1 != sel2) {
                    System.out.printf("%3d%3d", v[sel1], v[sel2]);
                    cont += 2;
                } else {
                    System.out.printf("%3d", v[sel1]);
                    cont++;
                }
                v[sel1] = 0;
                v[sel2] = 0;
            }

            System.out.println();
        }

        sc.close();
    }
}
