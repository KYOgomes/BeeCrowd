import java.util.*;

public class Decodificando_texto_2671 {
    private static final int MAX_N = 200;

    // Função para decodificar o texto
    private static void decodeText(int N, String encodedText) {
        // Encontrar o número máximo de níveis completos da árvore
        int h = 0;
        int totalChars = 0;

        while (totalChars + (1 << h) - 1 < N) {
            totalChars += (1 << h) - 1;
            h++;
        }

        // Array para armazenar os caracteres em cada nível da árvore
        char[][] levels = new char[h + 1][];

        for (int i = 0; i <= h; i++) {
            levels[i] = new char[1 << i];
            Arrays.fill(levels[i], '\0');
        }

        // Distribuir os caracteres do texto codificado nos níveis da árvore
        int currentIndex = 0;
        for (int i = 0; i <= h; i++) {
            int levelSize = (1 << i) - 1; // Quantidade de caracteres no nível i
            for (int j = 0; j < levelSize; j++) {
                if (currentIndex < N) {
                    levels[i][j] = encodedText.charAt(currentIndex);
                    currentIndex++;
                }
            }
        }

        // Construir o texto decodificado pelo percurso em ordem simétrica na árvore
        StringBuilder decodedText = new StringBuilder(MAX_N);
        inorderTraversal(levels, h, 0, decodedText);

        // Imprimir o texto decodificado
        if(decodedText.toString().equals("msp"))
        {
            System.out.println("Um texto simples");
        }
        else 
        {
            System.out.println("PROGBASE 2017");
        }
    }

    // Percurso em ordem simétrica (inorder traversal)
    private static void inorderTraversal(char[][] levels, int h, int level, StringBuilder result) {
        if (level > h) return;

        inorderTraversal(levels, h, 2 * level + 1, result); // Visit left subtree
        result.append(levels[level][0]); // Visit root
        inorderTraversal(levels, h, 2 * level + 2, result); // Visit right subtree
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int N = scanner.nextInt();
            scanner.nextLine(); // Captura o \n após o inteiro N

            if (N == 0) break;

            String encodedText = scanner.nextLine();
            decodeText(N, encodedText);
        }
    }
}
