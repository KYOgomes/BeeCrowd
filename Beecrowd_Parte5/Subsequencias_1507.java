import java.util.Scanner;

public class Subsequencias_1507 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int qtsCasos = sc.nextInt();
        sc.nextLine(); // Consumir o restante da linha após o número de casos

        while (qtsCasos-- > 0) {
            String string = sc.nextLine();
            int qtsStrings = sc.nextInt();
            sc.nextLine(); // Consumir o restante da linha após o número de strings

            for (int j = 0; j < qtsStrings; ++j) {
                String subString = sc.next();

                if (isSubString(subString, string))
                    System.out.println("Yes");
                else
                    System.out.println("No");
            }

            if (qtsCasos > 0) {
                sc.nextLine(); // Consumir a linha em branco entre os casos
            }
        }

        sc.close();
    }

    public static boolean isSubString(String string1, String string2) {
        int len1 = string1.length();
        int len2 = string2.length();
        int j = 0;

        for (int i = 0; i < len2 && j < len1; i++) {
            if (string1.charAt(j) == string2.charAt(i)) {
                j++;
            }
        }

        // Se todos os caracteres de string1 foram encontrados em string2 na ordem correta
        return j == len1;
    }
}
