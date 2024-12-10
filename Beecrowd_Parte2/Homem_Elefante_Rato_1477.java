import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
//saida errada
public class Homem_Elefante_Rato_1477 {

    static int[][] st;
    static int[] lz;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String line;

        while ((line = br.readLine()) != null) {
            StringTokenizer stok = new StringTokenizer(line);
            int n = Integer.parseInt(stok.nextToken());
            int m = Integer.parseInt(stok.nextToken());

            if (n == 0 && m == 0) break;

            st = new int[4 * n][3];
            lz = new int[4 * n];

            build(1, 1, n);

            while (m-- > 0) {
                line = br.readLine();
                stok = new StringTokenizer(line);
                char op = stok.nextToken().charAt(0);
                int a = Integer.parseInt(stok.nextToken());
                int b = Integer.parseInt(stok.nextToken());

                if (op == 'C') {
                    int[] ans = rangeQuery(1, 1, n, a, b);
                    sb.append(ans[0]).append(" ").append(ans[1]).append(" ").append(ans[2]).append("\n");
                } else if (op == 'M') {
                    rangeUpdate(1, 1, n, a, b);
                }
            }
            sb.append("\n");
        }

        System.out.print(sb.toString());
    }

    static void build(int p, int l, int r) {
        lz[p] = 0;
        if (l == r) {
            st[p][0] = 1; // inicialmente todos são 'Homem'
        } else {
            int m = (l + r) >> 1;
            build(p << 1, l, m);
            build((p << 1) + 1, m + 1, r);
            add(st[p], st[p << 1], st[(p << 1) + 1]);
        }
    }

    static void rangeUpdate(int p, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return;
        if (l >= ql && r <= qr) {
            lz[p] = (lz[p] + 1) % 3;
            propagate(p, l, r);
        } else {
            int m = (l + r) >> 1;
            rangeUpdate(p << 1, l, m, ql, qr);
            rangeUpdate((p << 1) + 1, m + 1, r, ql, qr);
            add(st[p], st[p << 1], st[(p << 1) + 1]);
        }
    }

    static int[] rangeQuery(int p, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return new int[]{0, 0, 0};
        propagate(p, l, r);
        if (l >= ql && r <= qr) return st[p];
        int m = (l + r) >> 1;
        int[] left = rangeQuery(p << 1, l, m, ql, qr);
        int[] right = rangeQuery((p << 1) + 1, m + 1, r, ql, qr);
        int[] ans = new int[3];
        add(ans, left, right);
        return ans;
    }

    static void propagate(int p, int l, int r) {
        if (lz[p] > 0) {
            if (l != r) {
                lz[p << 1] = (lz[p << 1] + lz[p]) % 3;
                lz[(p << 1) + 1] = (lz[(p << 1) + 1] + lz[p]) % 3;
            }
            while (lz[p]-- > 0) rotate(st[p]);
        }
    }

    static void rotate(int[] arr) {
        int tmp = arr[2];
        arr[2] = arr[1];
        arr[1] = arr[0];
        arr[0] = tmp;
    }

    static void add(int[] res, int[] a, int[] b) {
        for (int i = 0; i < 3; i++) {
            res[i] = a[i] + b[i];
        }
    }
}
