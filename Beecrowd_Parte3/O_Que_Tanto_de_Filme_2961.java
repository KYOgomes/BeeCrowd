import java.util.Scanner;

public class O_Que_Tanto_de_Filme_2961 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt(); // número de anos
        sc.nextLine(); // consome a quebra de linha
        
        int[] erros = new int[4]; // índices 0 a 3 para as categorias 1 a 4
        
        for (int ano = 0; ano < N; ano++) {
            // Lendo os palpites
            sc.nextLine(); // "Palpites"
            String[] palpites = new String[4];
            for (int i = 0; i < 4; i++) {
                palpites[i] = sc.nextLine();
            }
            
            // Lendo os vencedores
            sc.nextLine(); // "Vencedores"
            String[] vencedores = new String[4];
            for (int i = 0; i < 4; i++) {
                vencedores[i] = sc.nextLine();
            }
            
            // Comparando palpites com vencedores
            for (int i = 0; i < 4; i++) {
                if (!palpites[i].equals(vencedores[i])) {
                    erros[i]++;
                }
            }
        }
        
        // Determinando as categorias com mais erros
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 4; i++) {
            if (erros[i] > 0) {
                sb.append((i + 1) + " "); // índice + 1 para a categoria
            }
        }
        
        // Removendo o último espaço em branco, se houver
        if (sb.length() > 0) {
            sb.setLength(sb.length() - 1);
        }
        
        // Imprimindo o resultado
        System.out.println(sb.toString());
        
        sc.close();
    }
}
