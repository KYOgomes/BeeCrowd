#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 1000000

typedef struct {
    int position;
    int jumpNumber;
} Position;

typedef struct {
    Position *data;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (Position*)malloc(size * sizeof(Position));
    queue->front = 0;
    queue->rear = 0;
    queue->size = size;
    return queue;
}

void enqueue(Queue* queue, Position value) {
    queue->data[queue->rear++] = value;
}

Position dequeue(Queue* queue) {
    return queue->data[queue->front++];
}

bool isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

bool canReachStone(int N, int M) {
    // BFS setup
    Queue* queue = createQueue(N + 2);
    bool *visited = (bool *)calloc(N + 2, sizeof(bool));

    // Start from the left bank (position 0)
    Position start = {0, 1};
    enqueue(queue, start);
    visited[0] = true;

    while (!isEmpty(queue)) {
        Position current = dequeue(queue);
        int currentPosition = current.position;
        int jumpNumber = current.jumpNumber;

        // Calculate the next jump distance
        int jumpDistance = 2 * jumpNumber - 1;

        // Jump forward
        int forwardPosition = currentPosition + jumpDistance;
        if (forwardPosition == M) {
            freeQueue(queue);
            free(visited);
            return true; // Reached the target stone
        }
        if (forwardPosition <= N && !visited[forwardPosition]) {
            visited[forwardPosition] = true;
            Position next = {forwardPosition, jumpNumber + 1};
            enqueue(queue, next);
        }

        // Jump backward
        int backwardPosition = currentPosition - jumpDistance;
        if (backwardPosition == M) {
            freeQueue(queue);
            free(visited);
            return true; // Reached the target stone
        }
        if (backwardPosition > 0 && !visited[backwardPosition]) {
            visited[backwardPosition] = true;
            Position next = {backwardPosition, jumpNumber + 1};
            enqueue(queue, next);
        }
    }

    freeQueue(queue);
    free(visited);
    return false;
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) == 2) {
        if (N == 0 && M == 0) break;

        if (canReachStone(N, M)) {
            printf("Let me try!\n");
        } else {
            printf("Don't make fun of me!\n");
        }
    }
    return 0;
}
