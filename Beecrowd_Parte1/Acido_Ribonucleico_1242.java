import java.util.Scanner;
import java.util.Stack;

public class Acido_Ribonucleico_1242 {
    
    // Função para verificar se dois caracteres formam um par válido
    static boolean match(char a, char b) {
        if (a > b) {
            char temp = a;
            a = b;
            b = temp;
        }
        return (a == 'B' && b == 'S') || (a == 'C' && b == 'F');
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (scanner.hasNext()) {
            String acid = scanner.next();
            Stack<Character> st = new Stack<>();
            int cnt = 0;

            for (int i = 0; i < acid.length(); i++) {
                if (!st.isEmpty() && match(st.peek(), acid.charAt(i))) {
                    st.pop();
                    cnt++;
                } else {
                    st.push(acid.charAt(i));
                }
            }

            System.out.println(cnt);
        }
        
        scanner.close();
    }
}
