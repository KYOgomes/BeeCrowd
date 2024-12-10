import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());

        Point[] points = new Point[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            points[i] = new Point(x, y);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < P; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            double maxDistance = 0.0;
            for (int j = 1; j < N; j++) {
                double dist1 = distance(points[j-1], points[j], x1, y1);
                double dist2 = distance(points[j-1], points[j], x2, y2);
                double dist = Math.sqrt(dist1 * dist1 + dist2 * dist2);
                maxDistance = Math.max(maxDistance, dist);
            }

            sb.append(String.format("%.2f\n", maxDistance));
        }

        System.out.print(sb.toString());
    }

    static class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static double distance(Point p1, Point p2, int x, int y) {
        long dx = p2.x - p1.x;
        long dy = p2.y - p1.y;
        long dx2 = x - p1.x;
        long dy2 = y - p1.y;

        return Math.sqrt(dx2 * dx2 + dy2 * dy2);
    }
}
