#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int minSwapsToSort(int arr[], int N) {
    int temp[N];
    for (int i=0; i<N; i++)
        temp[i] = arr[i];

    qsort(temp, N, sizeof(int), compare);

    int visited[N];
    for (int i=0; i<N; i++)
        visited[i] = 0;

    int swaps = 0;

    for (int i = 0; i < N; i++) {
        if (visited[i] || temp[i] == arr[i])
            continue;

        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = 1;
            j = find(temp, N, arr[j]);
            cycle_size++;
        }

        if (cycle_size > 0) {
            swaps += (cycle_size - 1);
        }
    }

    return swaps;
}

int find(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int N;
        scanf("%d", &N);

        int arr[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        printf("%d\n", minSwapsToSort(arr, N));
    }

    return 0;
}