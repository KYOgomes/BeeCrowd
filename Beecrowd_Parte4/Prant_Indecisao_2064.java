import java.util.*;

public class Prant_Indecisao_2064 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            int k = scanner.nextInt();
            int m = scanner.nextInt();
            int n = scanner.nextInt();
            scanner.nextLine(); // Consume newline after reading integers

            // Leitura das letras favoritas
            String favoritas = scanner.nextLine();

            // Leitura do nome inicial do cachorro
            String nomeInicial = scanner.nextLine();

            // Encontrar o nome com maior número de letras favoritas
            int maxFavoritas = 0;
            String melhorNome = nomeInicial;

            // Processamento das operações de troca
            for (int i = 0; i < n; i++) {
                String operacao = scanner.nextLine();
                char a = operacao.charAt(0);
                char b = operacao.charAt(2);

                // Aplicar a troca de letras no nome inicial do cachorro
                char[] nomeChars = nomeInicial.toCharArray();
                for (int j = 0; j < m; j++) {
                    if (nomeChars[j] == a) {
                        nomeChars[j] = b;
                    } else if (nomeChars[j] == b) {
                        nomeChars[j] = a;
                    }
                }
                nomeInicial = new String(nomeChars);

                // Verificar o número de letras favoritas no novo nome
                int favoritasCount = 0;
                for (int j = 0; j < m; j++) {
                    if (favoritas.contains(String.valueOf(nomeInicial.charAt(j)))) {
                        favoritasCount++;
                    }
                }

                // Atualizar o melhor nome, se necessário
                if (favoritasCount > maxFavoritas) {
                    maxFavoritas = favoritasCount;
                    melhorNome = nomeInicial;
                }
            }

            // Imprimir resultado
            System.out.println(maxFavoritas);
            System.out.println(melhorNome);
        }

        scanner.close();
    }
}