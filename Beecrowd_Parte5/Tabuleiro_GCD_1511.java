import java.util.*;
import java.io.*;

public class Tabuleiro_GCD_1511 
{

    static Map<Point, Integer> grid = new HashMap<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            int Q = sc.nextInt();
            sc.nextLine(); // Consume newline after reading Q

            for (int q = 0; q < Q; ++q) {
                String line = sc.nextLine();
                String[] parts = line.split(" ");

                if (parts[0].equals("QUERY")) {
                    int x = Integer.parseInt(parts[1]);
                    int y = Integer.parseInt(parts[2]);
                    int d = Integer.parseInt(parts[3]);
                    System.out.println(queryGCD(x, y, d));
                } else if (parts[0].equals("SET")) {
                    int x = Integer.parseInt(parts[1]);
                    int y = Integer.parseInt(parts[2]);
                    int val = Integer.parseInt(parts[3]);
                    set(x, y, val);
                }
            }
        }

        sc.close();
    }

    static int queryGCD(int x, int y, int d) {
        int gcdValue = 0;
        for (Map.Entry<Point, Integer> entry : grid.entrySet()) {
            Point pos = entry.getKey();
            int value = entry.getValue();

            int distance = Math.abs(pos.x - x) + Math.abs(pos.y - y);
            if (distance <= d) {
                gcdValue = gcd(gcdValue, value);
            }
        }
        return gcdValue;
    }

    static void set(int x, int y, int val) {
        Point point = new Point(x, y);
        grid.put(point, val);
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return Math.abs(a);
    }

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null || getClass() != obj.getClass())
                return false;
            Point other = (Point) obj;
            return x == other.x && y == other.y;
        }
    }
}
