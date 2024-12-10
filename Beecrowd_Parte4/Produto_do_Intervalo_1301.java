import java.util.*;

public class Produto_do_Intervalo_1301 {

    static int MAX = 100100;
    static int[] st = new int[MAX * 4];
    static int[] vetor = new int[MAX];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            int n = sc.nextInt();
            int k = sc.nextInt();

            for (int i = 1; i <= n; ++i)
                vetor[i] = sc.nextInt();

            build(1, 1, n);
            for (int i = 0; i < k; ++i) {
                char comando = sc.next().charAt(0);

                if (comando == 'C') {
                    int a = sc.nextInt();
                    int b = sc.nextInt();
                    update(1, 1, n, a, b);
                } else {
                    int a = sc.nextInt();
                    int b = sc.nextInt();
                    int ans = query(1, 1, n, a, b);
                    System.out.print(ans == 0 ? "0" : ans > 0 ? "+" : "-");
                }
            }

            System.out.println();
        }

        sc.close();
    }

    static void build(int p, int l, int r) {
        if (l == r) {
            st[p] = vetor[l];
            return;
        }

        build(p * 2, l, (l + r) / 2);
        build((p * 2) + 1, ((l + r) / 2) + 1, r);

        int ans = st[p * 2] * st[p * 2 + 1];
        st[p] = ans == 0 ? 0 : ans > 0 ? 1 : -1;
    }

    static void update(int p, int l, int r, int x, int v) {
        if (l == r) {
            vetor[x] = st[p] = v;
            return;
        }

        if (x <= (l + r) / 2)
            update(p * 2, l, (l + r) / 2, x, v);
        else
            update((p * 2) + 1, ((l + r) / 2) + 1, r, x, v);

        int ans = st[p * 2] * st[p * 2 + 1];
        st[p] = ans == 0 ? 0 : ans > 0 ? 1 : -1;
    }

    static int query(int p, int l, int r, int a, int b) {
        if (a <= l && b >= r)
            return st[p];

        if (b < l || a > r)
            return 1;

        int rL = query(p * 2, l, (l + r) / 2, a, b);
        int rR = query(p * 2 + 1, ((l + r) / 2) + 1, r, a, b);

        int ans = rL * rR;
        return ans == 0 ? 0 : ans > 0 ? 1 : -1;
    }
}