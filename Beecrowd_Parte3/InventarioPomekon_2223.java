import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class BIT {
    int[] tree;
    int size;

    public BIT(int size) {
        this.tree = new int[size + 1];
        this.size = size;
    }

    public void update(int index, int delta) {
        while (index <= size) {
            tree[index] += delta;
            index += index & (-index);
        }
    }

    public int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }

    public int queryRange(int left, int right) {
        return query(right) - query(left - 1);
    }
}

class Operacao {
    int indiceOperacao;
    int pilha;
    int valor;

    public Operacao(int indiceOperacao, int pilha, int valor) {
        this.indiceOperacao = indiceOperacao;
        this.pilha = pilha;
        this.valor = valor;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine().trim()); // Número de instâncias
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine().trim()); // Quantidade de pilhas
            int[] pilhas = new int[N + 1];
            BIT bit = new BIT(N);

            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                pilhas[i] = Integer.parseInt(st.nextToken());
                bit.update(i, pilhas[i]);
            }

            int Q = Integer.parseInt(br.readLine().trim()); // Quantidade de operações
            List<Operacao> operacoesTipo2 = new ArrayList<>();

            for (int i = 1; i <= Q; i++) {
                st = new StringTokenizer(br.readLine());
                int tipoOperacao = Integer.parseInt(st.nextToken());
                if (tipoOperacao == 1) {
                    int X = Integer.parseInt(st.nextToken());
                    int Y = Integer.parseInt(st.nextToken());
                    int K = Integer.parseInt(st.nextToken());

                    int quantidadeXaY = bit.queryRange(X, Y);
                    int indiceOperacao = K;

                    sb.append(quantidadeXaY).append("\n");
                } else if (tipoOperacao == 2) {
                    int X = Integer.parseInt(st.nextToken());
                    int W = Integer.parseInt(st.nextToken());
                    bit.update(X, W);
                    operacoesTipo2.add(new Operacao(i, X, W));
                }
            }
        }

        System.out.print(sb.toString());
    }
}
