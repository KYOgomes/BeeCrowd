import java.util.Scanner;

public class Main {

    // Arrays para armazenar os códigos Morse e os caracteres correspondentes
    private static final String[] morseCodes = {
            "=.===", "===.=.=.=", "===.=.===.=", "===.=.=", "=", "=.=.===.=",
            "===.===.=", "=.=.=.=","=.=", "=.===.===.===", "===.=.===", "=.===.=.=",
            "===.===", "===.=", "===.===.===", "=.===.===.=", "===.===.=.===",
            "=.===.=", "=.=.=", "===", "=.=.===", "=.=.=.===", "=.===.===",
            "===.=.=.===", "===.=.===.===", "===.===.=.="};

    private static final char[] characters = {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};

    // Método para decodificar uma mensagem em código morse
    private static String decodeMorse(String morseCode) {
        StringBuilder sb = new StringBuilder();

        // Divide o código morse pelos espaços entre palavras (.......)
        String[] words = morseCode.split("\\.{7}");
        
        for (String word : words) {
            String[] symbols = word.split("\\.{3}");

            for (String symbol : symbols) {
                char decodedChar = decodeSymbol(symbol);
                sb.append(decodedChar);
            }
            sb.append(" "); // Adiciona espaço entre palavras
        }

        // Remove o último espaço entre palavras, se houver
        if (sb.length() > 0 && sb.charAt(sb.length() - 1) == ' ') {
            sb.deleteCharAt(sb.length() - 1);
        }

        return sb.toString();
    }

    // Método para decodificar um único símbolo de código morse
    private static char decodeSymbol(String symbol) {
        for (int i = 0; i < morseCodes.length; i++) {
            if (morseCodes[i].equals(symbol)) {
                return characters[i];
            }
        }
        return ' '; // Se não encontrar, retorna espaço
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lê o número de casos de teste
        int t = scanner.nextInt();
        scanner.nextLine(); // Consume a quebra de linha após o número de casos de teste

        // Processa cada caso de teste
        for (int i = 0; i < t; i++) {
            String morseCode = scanner.nextLine().trim();

            // Decodifica o código morse
            String decodedMessage = decodeMorse(morseCode);

            // Imprime o resultado
            System.out.println(decodedMessage);
        }

        scanner.close();
    }
}
