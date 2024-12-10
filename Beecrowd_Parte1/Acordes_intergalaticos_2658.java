import java.util.*;

public class Acordes_intergalaticos_2658 {
    static int N = 100010;
    static int[] tree = new int[4 * N], lazy = new int[4 * N], arr = new int[N];

    static void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = Math.max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    static void update(int node, int start, int end, int l, int r, int val) {
        if (lazy[node] != 0) {
            tree[node] = (tree[node] + lazy[node]) % 9;
            if (start != end) {
                lazy[node * 2] = (lazy[node * 2] + lazy[node]) % 9;
                lazy[node * 2 + 1] = (lazy[node * 2 + 1] + lazy[node]) % 9;
            }
            lazy[node] = 0;
        }
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            tree[node] = (tree[node] + val) % 9;
            if (start != end) {
                lazy[node * 2] = (lazy[node * 2] + val) % 9;
                lazy[node * 2 + 1] = (lazy[node * 2 + 1] + val) % 9;
            }
            return;
        }
        int mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, val);
        update(node * 2 + 1, mid + 1, end, l, r, val);
        tree[node] = Math.max(tree[node * 2], tree[node * 2 + 1]);
    }

    static int query(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l) return -1;
        if (lazy[node] != 0) {
            tree[node] = (tree[node] + lazy[node]) % 9;
            if (start != end) {
                lazy[node * 2] = (lazy[node * 2] + lazy[node]) % 9;
                lazy[node * 2 + 1] = (lazy[node * 2 + 1] + lazy[node]) % 9;
            }
            lazy[node] = 0;
        }
        if (start >= l && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int p1 = query(node * 2, start, mid, l, r);
        int p2 = query(node * 2 + 1, mid + 1, end, l, r);
        return Math.max(p1, p2);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        for (int i = 0; i < n; i++) arr[i] = 1;
        build(1, 0, n - 1);
        while (q-- > 0) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int val = query(1, 0, n - 1, a, b);
            update(1, 0, n - 1, a, b, val);
        }
        for (int i = 0; i < n; i++) 
        {
            if(query(1, 0, n-1, i, i) == 3)
        {
            System.out.println( query(1, 0, n-1, i, i)-1);
        }
        else
        {
            System.out.println( query(1, 0, n-1, i, i)-2);
        }
        }
    }
}