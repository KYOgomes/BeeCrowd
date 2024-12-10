import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            int N = Integer.parseInt(line.trim());
            
            // Leitura dos preços iniciais
            int[] precos = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                precos[i] = Integer.parseInt(st.nextToken());
            }
            
            // Inicialização do histórico de preços
            int[][] historico = new int[N][1]; // Começa com apenas o preço inicial
            for (int i = 0; i < N; i++) {
                historico[i][0] = precos[i];
            }
            
            // Leitura do número de operações
            int Q = Integer.parseInt(br.readLine().trim());
            
            StringBuilder sb = new StringBuilder();
            for (int q = 0; q < Q; q++) {
                st = new StringTokenizer(br.readLine());
                int op = Integer.parseInt(st.nextToken());
                if (op == 1) {
                    // Operação de alteração de preço
                    int i = Integer.parseInt(st.nextToken()) - 1; // Convertendo para índice 0-based
                    int p = Integer.parseInt(st.nextToken());
                    
                    // Atualiza o preço na loja i
                    precos[i] = p;
                    
                    // Adiciona o novo preço ao histórico da loja i
                    int[] novoHistorico = new int[historico[i].length + 1];
                    System.arraycopy(historico[i], 0, novoHistorico, 0, historico[i].length);
                    novoHistorico[historico[i].length] = p;
                    historico[i] = novoHistorico;
                } else if (op == 2) {
                    // Operação de consulta
                    int i = Integer.parseInt(st.nextToken()) - 1; // Convertendo para índice 0-based
                    int j = Integer.parseInt(st.nextToken()) - 1; // Convertendo para índice 0-based
                    
                    // Encontra o mínimo e o máximo preço entre as lojas i e j
                    int minPreco = Integer.MAX_VALUE;
                    int maxPreco = Integer.MIN_VALUE;
                    
                    for (int k = i; k <= j; k++) {
                        for (int h = 0; h < historico[k].length; h++) {
                            int precoAtual = historico[k][h];
                            if (precoAtual < minPreco) minPreco = precoAtual;
                            if (precoAtual > maxPreco) maxPreco = precoAtual;
                        }
                    }
                    
                    // Calcula a maior diferença de preços
                    int maiorDiferenca = Math.abs(maxPreco - minPreco);
                    
                    // Adiciona o resultado à saída
                    sb.append(maiorDiferenca).append("\n");
                }
            }
            
            // Imprime a saída do caso de teste
            System.out.print(sb.toString());
        }
    }
}
