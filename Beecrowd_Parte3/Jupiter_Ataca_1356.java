import java.util.Scanner;

public class Jupiter_Ataca_1356 {
    static class SegmentTree {
        long[] t, a;
        int p, b;

        SegmentTree(int n, int b, int p) {
            t = new long[n << 2];
            a = new long[n + 1];
            this.p = p;
            this.b = b;
        }

        void build(int node, int start, int end) {
            if (start == end) {
                t[node] = a[start];
            } else {
                int mid = (start + end) >> 1;
                build(node << 1, start, mid);
                build(node << 1 | 1, mid + 1, end);
                t[node] = (t[node << 1] * b + t[node << 1 | 1]) % p;
            }
        }

        void update(int node, int start, int end, int idx, long val) {
            if (start == end) {
                a[idx] = val;
                t[node] = val;
            } else {
                int mid = (start + end) >> 1;
                if (start <= idx && idx <= mid) {
                    update(node << 1, start, mid, idx, val);
                } else {
                    update(node << 1 | 1, mid + 1, end, idx, val);
                }
                t[node] = (t[node << 1] * b + t[node << 1 | 1]) % p;
            }
        }

        long query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) {
                return 0;
            }
            if (l <= start && end <= r) {
                return t[node] * power(b, r - end) % p;
            }
            int mid = (start + end) >> 1;
            long p1 = query(node << 1, start, mid, l, r);
            long p2 = query(node << 1 | 1, mid + 1, end, l, r);
            return (p1 + p2) % p;
        }

        long power(long a, long b) {
            long res = 1;
            while (b > 0) {
                if ((b & 1) == 1) {
                    res = (res * a) % p;
                }
                b >>= 1;
                a = (a * a) % p;
            }
            return res;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int b = sc.nextInt();
            int p = sc.nextInt();
            int l = sc.nextInt();
            int n = sc.nextInt();
            if (b == 0 && p == 0 && l == 0 && n == 0) {
                break;
            }
            SegmentTree st = new SegmentTree(l, b, p);
            for (int i = 0; i < n; i++) {
                char type = sc.next().charAt(0);
                int x = sc.nextInt();
                int y = sc.nextInt();
                if (type == 'E') {
                    st.update(1, 1, l, x, y);
                } else {
                    System.out.println(st.query(1, 1, l, x, y));
                }
            }
            System.out.println("-");
        }
        sc.close();
    }
}