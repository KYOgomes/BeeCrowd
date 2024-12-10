#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int color;
    int start;
    int end;
} Interval;

int main() {
    int L, C, N;
    scanf("%d %d %d", &L, &C, &N);

    Interval* intervals = malloc(L * sizeof(Interval));
    int intervalCount = 1;
    intervals[0].color = 1;
    intervals[0].start = 0;
    intervals[0].end = L - 1;

    for (int i = 0; i < N; i++) {
        int P, X, A, B;
        scanf("%d %d %d %d", &P, &X, &A, &B);

        int S = 0;
        for (int j = 0; j < intervalCount; j++) {
            if (intervals[j].color == P) {
                S += intervals[j].end - intervals[j].start + 1;
            }
        }

        int M1 = (A + S * S) % L;
        int M2 = (A + (S + B) * (S + B)) % L;

        int start = M1 < M2 ? M1 : M2;
        int end = M1 > M2 ? M1 : M2;

        Interval* newIntervals = malloc(L * sizeof(Interval));
        int newIntervalCount = 0;
        for (int j = 0; j < intervalCount; j++) {
            if (intervals[j].end < start || intervals[j].start > end) {
                newIntervals[newIntervalCount++] = intervals[j];
            } else {
                if (intervals[j].start < start) {
                    newIntervals[newIntervalCount++] = (Interval){intervals[j].color, intervals[j].start, start - 1};
                }

                newIntervals[newIntervalCount++] = (Interval){X, intervals[j].start > start ? intervals[j].start : start, intervals[j].end < end ? intervals[j].end : end};

                if (intervals[j].end > end) {
                    newIntervals[newIntervalCount++] = (Interval){intervals[j].color, end + 1, intervals[j].end};
                }
            }
        }

        free(intervals);
        intervals = newIntervals;
        intervalCount = newIntervalCount;
    }

    int* counts = calloc(C + 1, sizeof(int));
    for (int i = 0; i < intervalCount; i++) {
        counts[intervals[i].color] += intervals[i].end - intervals[i].start + 1;
    }

    int maxColor = 1;
    for (int i = 2; i <= C; i++) {
        if (counts[i] > counts[maxColor]) {
            maxColor = i;
        }
    }

    printf("%d\n", counts[maxColor]);

    free(intervals);
    free(counts);

    return 0;
}