import java.util.Scanner;

public class Parafusos_e_porcas_1520 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            int iter = sc.nextInt();
            int[] vet = new int[101]; // Vetor para contagem de intervalos

            // Lê os intervalos e atualiza o vetor vet
            for (int i = 0; i < iter; i++) {
                int inicio = sc.nextInt();
                int fim = sc.nextInt();
                for (int j = inicio; j <= fim; j++) {
                    vet[j]++;
                }
            }

            // Lê o número a ser buscado
            int j = sc.nextInt();

            // Verifica se o número está presente no vetor vet
            if (vet[j] > 0) {
                // Encontra o intervalo onde o número j foi encontrado
                int start = -1, end = -1;
                int acl = 0;

                for (int i = 1; i <= 100; i++) {
                    if (vet[i] > 0) {
                        acl += vet[i];
                        if (i == j) {
                            start = acl - vet[i] + 1;
                            end = acl;
                            break;
                        }
                    }
                }

                System.out.println(j + " found from " + start + " to " + end);
            } else {
                System.out.println(j + " not found");
            }
        }

        sc.close();
    }
}
