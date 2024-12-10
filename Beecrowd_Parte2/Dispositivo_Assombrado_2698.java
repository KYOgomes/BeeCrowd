import java.util.*;

class Interval {
    int color;
    int start;
    int end;

    Interval(int color, int start, int end) {
        this.color = color;
        this.start = start;
        this.end = end;
    }
}

public class Dispositivo_Assombrado_2698 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int L = scanner.nextInt();
        int C = scanner.nextInt();
        int N = scanner.nextInt();

        List<Interval> intervals = new ArrayList<>();
        intervals.add(new Interval(1, 0, L - 1));

        for (int i = 0; i < N; i++) {
            int P = scanner.nextInt();
            int X = scanner.nextInt();
            int A = scanner.nextInt();
            int B = scanner.nextInt();

            int S = 0;
            for (Interval interval : intervals) {
                if (interval.color == P) {
                    S += interval.end - interval.start + 1;
                }
            }

            int M1 = (A + S * S) % L;
            int M2 = (A + (S + B) * (S + B)) % L;

            int start = Math.min(M1, M2);
            int end = Math.max(M1, M2);

            List<Interval> newIntervals = new ArrayList<>();
            for (Interval interval : intervals) {
                if (interval.end < start || interval.start > end) {
                    newIntervals.add(interval);
                } else {
                    if (interval.start < start) {
                        newIntervals.add(new Interval(interval.color, interval.start, start - 1));
                    }

                    newIntervals.add(new Interval(X, Math.max(start, interval.start), Math.min(end, interval.end)));

                    if (interval.end > end) {
                        newIntervals.add(new Interval(interval.color, end + 1, interval.end));
                    }
                }
            }

            intervals = newIntervals;
        }

        int[] counts = new int[C + 1];
        for (Interval interval : intervals) {
            counts[interval.color] += interval.end - interval.start + 1;
        }

        int maxColor = 1;
        for (int i = 2; i <= C; i++) {
            if (counts[i] > counts[maxColor]) {
                maxColor = i;
            }
        }

        System.out.println(counts[maxColor]);
    }
}