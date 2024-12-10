import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Número de casos de teste
        scanner.nextLine(); // Consumir o newline após o número
        
        for (int caso = 0; caso < n; caso++) {
            // Leitura do texto
            String texto = scanner.nextLine();
            
            // Leitura da palavra a ser buscada
            String palavra = scanner.nextLine();
            int tamPalavra = palavra.length();
            
            // Variável para armazenar as posições encontradas
            StringBuilder posicoes = new StringBuilder();
            
            // Variável para controlar a posição atual no texto
            int posAtual = 0;
            
            // Loop para buscar a palavra no texto
            while (posAtual <= texto.length() - tamPalavra) {
                // Encontramos a palavra na posição atual?
                if (texto.substring(posAtual, posAtual + tamPalavra).equals(palavra)) {
                    posicoes.append(posAtual).append(" ");
                    // Avançamos para além da palavra encontrada
                    posAtual += tamPalavra;
                } else {
                    // Avançamos apenas um caractere
                    posAtual++;
                }
            }
            
            // Se não encontrou nenhuma posição, imprimir -1
            if (posicoes.length() == 0) {
                System.out.println("-1");
            } else {
                // Remover o espaço extra no final e imprimir as posições
                System.out.println(posicoes.toString().trim());
            }
        }
        
        scanner.close();
    }
}
