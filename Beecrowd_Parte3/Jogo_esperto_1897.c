#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10001

int queue[MAX];
bool visited[MAX];

int minOperations(int N, int M) {
    int front = 0, rear = 0;
    memset(visited, false, sizeof(visited));

    queue[rear++] = N;
    visited[N] = true;
    int operations = 0;

    while (front != rear) {
        int size = rear - front;
        while (size-- > 0) {
            int current = queue[front++];

            if (current == M) {
                return operations;
            }

            // Possible operations
            if (current * 2 <= 10000 && !visited[current * 2]) {
                queue[rear++] = current * 2;
                visited[current * 2] = true;
            }
            if (current * 3 <= 10000 && !visited[current * 3]) {
                queue[rear++] = current * 3;
                visited[current * 3] = true;
            }
            if (current % 2 == 0 && !visited[current / 2]) {
                queue[rear++] = current / 2;
                visited[current / 2] = true;
            }
            if (current % 3 == 0 && !visited[current / 3]) {
                queue[rear++] = current / 3;
                visited[current / 3] = true;
            }
            if (current + 7 <= 10000 && !visited[current + 7]) {
                queue[rear++] = current + 7;
                visited[current + 7] = true;
            }
            if (current - 7 >= 0 && !visited[current - 7]) {
                queue[rear++] = current - 7;
                visited[current - 7] = true;
            }
        }
        operations++;
    }

    return -1; // In case it doesn't find, although it's not necessary for the given problem conditions
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int result = minOperations(N, M);
    printf("%d\n", result);

    return 0;
}