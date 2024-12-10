import java.util.*;

public class Distribuicao_de_Cartas_2821 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int nCartas = scanner.nextInt();
        int nJogadores = scanner.nextInt();
        scanner.nextLine();

        int[] cartas = new int[nCartas];
        for (int i = 0; i < nCartas; i++) {
            String carta = scanner.next();
            switch (carta) {
                case "A":
                    cartas[i] = 1;
                    break;
                case "J":
                    cartas[i] = 11;
                    break;
                case "Q":
                    cartas[i] = 12;
                    break;
                case "K":
                    cartas[i] = 13;
                    break;
                default:
                    cartas[i] = Integer.parseInt(carta);
                    break;
            }
        }

        int[] soma = new int[nJogadores];
        int[] count = new int[nJogadores];
        int j = 0;
        for (int i = 0; i < nCartas; i++) {
            soma[j] += cartas[i];
            count[j]++;
            if (j < nJogadores - 1 && soma[j] + cartas[i + 1] > soma[j]) {
                j++;
            }
        }

        int maxCount = Arrays.stream(count).max().getAsInt();
        int maxSoma = Arrays.stream(soma).max().getAsInt();
        System.out.println(maxCount + " " + maxSoma);
    }
}