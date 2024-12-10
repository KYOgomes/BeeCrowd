import java.util.*;

public class Assuntos_Pendentes_2984 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();
        sc.close();

        int pendentes = contarAssuntosPendentes(S);
        
        if (pendentes > 0) {
            System.out.printf("Ainda temos %d assunto(s) pendente(s)!\n", pendentes);
        } else {
            System.out.println("Partiu RU!");
        }
    }

    public static int contarAssuntosPendentes(String S) {
        Stack<Character> stack = new Stack<>();
        
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            
            if (c == '(') {
                stack.push(c); // Empilha abertura de parênteses
            } else if (c == ')') {
                if (!stack.isEmpty() && stack.peek() == '(') {
                    stack.pop(); // Fecha um parêntese aberto
                } else {
                    stack.push(c); // Parêntese de fechamento sem abertura correspondente
                }
            }
        }
        
        return stack.size(); // O que sobrar na pilha são os pendentes
    }
}
