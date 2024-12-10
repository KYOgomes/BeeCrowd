#include <stdio.h>
#include <stdlib.h>

#define MAX_YEARS 50000
#define MAX_QUERIES 10000
#define INF 1000000000

typedef struct {
    int year;
    int rain;
} RainInfo;

// Function to perform binary search
int binarySearch(RainInfo arr[], int l, int r, int year) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid].year == year) {
            return mid;
        } else if (arr[mid].year < year) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

// Comparator function for qsort
int cmpfunc(const void *a, const void *b) {
    return ((RainInfo *)a)->year - ((RainInfo *)b)->year;
}

int main() {
    int n, m;
    RainInfo rainInfo[MAX_YEARS];
    int queries[MAX_QUERIES][2];
    
    while (scanf("%d", &n) && n != 0) {
        scanf("%d", &m);

        // Read the rainfall information
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &rainInfo[i].year, &rainInfo[i].rain);
        }

        // Read the queries
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &queries[i][0], &queries[i][1]);
        }

        // Sort the rainfall information by year
        qsort(rainInfo, n, sizeof(RainInfo), cmpfunc);

        for (int i = 0; i < m; i++) {
            int Y = queries[i][0];
            int X = queries[i][1];
            int idxY = binarySearch(rainInfo, 0, n - 1, Y);
            int idxX = binarySearch(rainInfo, 0, n - 1, X);

            if (idxY == -1 || idxX == -1) {
                printf("maybe\n");
                continue;
            }

            int rainY = rainInfo[idxY].rain;
            int rainX = rainInfo[idxX].rain;

            if (rainY != rainX) {
                printf("false\n");
            } else {
                int isTrue = 1;
                for (int j = idxY + 1; j < idxX; j++) {
                    if (rainInfo[j].rain >= rainX) {
                        isTrue = 0;
                        break;
                    }
                }

                if (isTrue) {
                    if (idxX - idxY == X - Y) {
                        printf("true\n");
                    } else {
                        printf("maybe\n");
                    }
                } else {
                    printf("false\n");
                }
            }
        }

        printf("\n");
    }

    return 0;
}
