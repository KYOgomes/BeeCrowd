import java.util.Scanner;

public class Lista_telefonica_1211 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (scanner.hasNext()) {
            int N = scanner.nextInt(); // Número de telefones
            scanner.nextLine(); // Consumir o newline após o inteiro
            
            if (N == 0) break; // Caso de término de entrada
            
            String[] telefones = new String[N];
            
            // Ler os N telefones
            for (int i = 0; i < N; i++) {
                telefones[i] = scanner.nextLine();
            }
            
            // Processar o primeiro telefone sem modificações
            String telefoneAnterior = telefones[0];
            int economia = 0;
            
            // Processar os telefones restantes
            for (int i = 1; i < N; i++) {
                String telefoneAtual = telefones[i];
                StringBuilder linhaCompactada = new StringBuilder();
                int caracteresEconomizados = 0;
                
                // Comparar cada caractere dos números
                for (int j = 0; j < telefoneAtual.length(); j++) {
                    if (j < telefoneAnterior.length() && telefoneAtual.charAt(j) == telefoneAnterior.charAt(j)) {
                        linhaCompactada.append(' '); // Substitui prefixo comum por espaço
                        caracteresEconomizados++;
                    } else {
                        linhaCompactada.append(telefoneAtual.charAt(j));
                    }
                }
                
                telefoneAnterior = linhaCompactada.toString();
                economia += caracteresEconomizados;
            }
            
            System.out.println(economia);
        }
        
        scanner.close();
    }
}
