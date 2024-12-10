import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Consultas_horriveis_1500 {

    static long[] b1;
    static long[] b2;
    static long n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Long.parseLong(st.nextToken());
            long o = Long.parseLong(st.nextToken());

            b1 = new long[(int) (n + 1)];
            b2 = new long[(int) (n + 1)];

            while (o-- > 0) {
                st = new StringTokenizer(br.readLine());
                long m = Long.parseLong(st.nextToken());
                long p = Long.parseLong(st.nextToken());
                long q = Long.parseLong(st.nextToken());

                if (p > q) {
                    long temp = p;
                    p = q;
                    q = temp;
                }

                if (m == 0) {
                    long v = Long.parseLong(st.nextToken());
                    range_update(p, q, v);
                } else {
                    long result = range_query(p, q);
                    sb.append(result).append("\n");
                }
            }
        }

        System.out.print(sb);
    }

    static void range_update(long i, long j, long v) {
        update(b1, i, v);
        update(b1, j + 1, -v);
        update(b2, i, v * (i - 1));
        update(b2, j + 1, -v * j);
    }

    static void update(long[] ft, long k, long v) {
        for (; k <= n; k += LSOne(k)) {
            ft[(int) k] += v;
        }
    }

    static long range_query(long i, long j) {
        return query(j) - query(i - 1);
    }

    static long query(long b) {
        return p_query(b1, b) * b - p_query(b2, b);
    }

    static long p_query(long[] ft, long b) {
        long sum = 0;
        for (; b > 0; b -= LSOne(b)) {
            sum += ft[(int) b];
        }
        return sum;
    }

    static long LSOne(long s) {
        return s & (-s);
    }
}
