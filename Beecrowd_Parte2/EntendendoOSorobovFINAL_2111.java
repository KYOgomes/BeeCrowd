import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextInt()) {
            int number = scanner.nextInt();
            printSorobov(number);
        }

        scanner.close();
    }

    private static void printSorobov(int number) {
        String[] top = {"000000000", "000000000"};
        String[] bottom = {"000000000", "000000000", "000000000", "000000000", "000000000"};

        char[] digits = String.format("%09d", number).toCharArray();

        for (int i = 0; i < 9; i++) {
            int digit = digits[i] - '0';

            if (digit >= 5) {
                top[1] = replaceCharAt(top[1], i, '1');
                digit -= 5;
            } else {
                top[0] = replaceCharAt(top[0], i, '1');
            }

            for (int j = 0; j < digit; j++) {
                bottom[j] = replaceCharAt(bottom[j], i, '1');
            }
        }

        for (String line : top) {
            System.out.println(line);
        }
        System.out.println("---------");
        for (String line : bottom) {
            System.out.println(line);
        }
        System.out.println();
    }

    private static String replaceCharAt(String s, int pos, char c) {
        StringBuilder sb = new StringBuilder(s);
        sb.setCharAt(pos, c);
        return sb.toString();
    }
}
