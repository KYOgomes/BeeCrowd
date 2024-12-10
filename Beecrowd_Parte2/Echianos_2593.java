import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Leitura do texto
        String texto = scanner.nextLine();
        
        // Leitura da quantidade de palavras
        int qtdPalavras = scanner.nextInt();
        scanner.nextLine(); // Consumir quebra de linha
        
        // Leitura das palavras
        String[] palavras = scanner.nextLine().split(" ");
        
        // Processamento das palavras
        for (String palavra : palavras) {
            boolean primeiraPosicao = true;
            boolean encontrou = false;
            
            // Procurar a palavra no texto
            int posInicial = 0;
            while ((posInicial = texto.indexOf(palavra, posInicial)) != -1) {
                if (!primeiraPosicao) {
                    System.out.print(" ");
                }
                System.out.print(posInicial);
                primeiraPosicao = false;
                encontrou = true;
                
                // Avançar para a próxima posição após a última ocorrência
                posInicial += palavra.length();
            }
            
            // Se não encontrou nenhuma ocorrência da palavra
            if (!encontrou) {
                System.out.print("-1");
            }
            
            System.out.println(); // Nova linha para a próxima palavra
        }
        
        scanner.close();
    }
}
