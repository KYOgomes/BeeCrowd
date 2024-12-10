import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Leitura de L e N
        StringTokenizer st = new StringTokenizer(br.readLine());
        int L = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        // Leitura da string S
        String S = br.readLine();

        // StringBuilder para manipular a string S
        StringBuilder sb = new StringBuilder(S);

        // Processamento das N operações
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int operacao = Integer.parseInt(st.nextToken());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            if (operacao == 1) {
                char C = st.nextToken().charAt(0);
                // Operação 1: contar ocorrências de C em S[A-1, B-1]
                int count = 0;
                for (int j = A - 1; j < B; j++) {
                    if (sb.charAt(j) == C) {
                        count++;
                    }
                }
                System.out.println(count);
            } else if (operacao == 2) {
                char C = st.nextToken().charAt(0);
                // Operação 2: encontrar primeira e última ocorrência de C em S[A-1, B-1]
                int first = -1;
                int last = -1;
                for (int j = A - 1; j < B; j++) {
                    if (sb.charAt(j) == C) {
                        if (first == -1) {
                            first = j + 1; // converte para 1-indexed
                        }
                        last = j + 1; // converte para 1-indexed
                    }
                }
                System.out.println(first + " " + last);
            } else if (operacao == 3) {
                // Operação 3: inverter S[A-1, B-1]
                int start = A - 1;
                int end = B - 1;
                while (start < end) {
                    char temp = sb.charAt(start);
                    sb.setCharAt(start, sb.charAt(end));
                    sb.setCharAt(end, temp);
                    start++;
                    end--;
                }
            } else if (operacao == 4) {
                char C = st.nextToken().charAt(0);
                // Operação 4: adicionar C antes de S[A-1]
                sb.insert(A - 1, C);
            }
        }

        // Imprime o resultado final da string S após as operações
        System.out.println(sb.toString());

        br.close();
    }
}
