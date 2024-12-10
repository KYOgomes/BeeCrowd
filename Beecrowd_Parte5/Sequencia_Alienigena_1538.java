import java.util.Scanner;

public class Sequencia_Alienigena_1538_ERRO {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int n = scanner.nextInt();
            if (n == 0) {
                break;
            }
            String result = findAlienSequence(n);
            System.out.println(result);
        }

        scanner.close();
    }

    public static String findAlienSequence(int n) {
        StringBuilder sb = new StringBuilder();

        while (n > 0) {
            int remainder = (n - 1) % 4; // remainder in base 4 (0, 1, 2, 3)
            switch (remainder) {
                case 0: sb.append('B'); break;
                case 1: sb.append('A'); break;
                case 2: sb.append('C'); break;
                case 3: sb.append('D'); break;
            }
            n = (n - 1) / 4; // update n to next place value
        }

        return sb.reverse().toString(); // reverse to get correct order
    }
}
