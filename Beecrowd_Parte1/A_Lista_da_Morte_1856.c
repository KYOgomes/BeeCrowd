#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} DoublyLinkedList;

typedef struct {
    int key;
    Node* node;
} HashEntry;

#define TABLE_SIZE 100003

HashEntry* hashTable[TABLE_SIZE];

unsigned int hash(int key) {
    return key % TABLE_SIZE;
}

void insertHash(int key, Node* node) {
    unsigned int index = hash(key);
    while (hashTable[index] != NULL && hashTable[index]->key != key) {
        index = (index + 1) % TABLE_SIZE;
    }
    if (hashTable[index] == NULL) {
        hashTable[index] = (HashEntry*)malloc(sizeof(HashEntry));
    }
    hashTable[index]->key = key;
    hashTable[index]->node = node;
}

Node* searchHash(int key) {
    unsigned int index = hash(key);
    while (hashTable[index] != NULL && hashTable[index]->key != key) {
        index = (index + 1) % TABLE_SIZE;
    }
    return hashTable[index] == NULL ? NULL : hashTable[index]->node;
}

DoublyLinkedList* createList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = list->tail = NULL;
    return list;
}

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = node->prev = NULL;
    return node;
}

void insertAfter(DoublyLinkedList* list, Node* afterNode, int value) {
    Node* newNode = createNode(value);
    if (afterNode->next != NULL) {
        newNode->next = afterNode->next;
        afterNode->next->prev = newNode;
    } else {
        list->tail = newNode;
    }
    newNode->prev = afterNode;
    afterNode->next = newNode;
    insertHash(value, newNode);
}

void removeNode(DoublyLinkedList* list, Node* node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }
    free(node);
}

int countBetween(DoublyLinkedList* list, int a, int b) {
    Node* nodeA = searchHash(a);
    Node* nodeB = searchHash(b);
    int count = 0;
    if (nodeA == NULL || nodeB == NULL) return -1;
    Node* start = nodeA->next;
    while (start != NULL && start != nodeB) {
        count++;
        start = start->next;
    }
    if (start == NULL) {
        count = 0;
        start = nodeB->next;
        while (start != NULL && start != nodeA) {
            count++;
            start = start->next;
        }
    }
    return count;
}

int main() {
    int N, Q;
    scanf("%d", &N);

    DoublyLinkedList* list = createList();
    memset(hashTable, 0, sizeof(hashTable));

    Node* lastNode = NULL;
    for (int i = 0; i < N; i++) {
        int enemy;
        scanf("%d", &enemy);
        Node* newNode = createNode(enemy);
        if (list->head == NULL) {
            list->head = list->tail = newNode;
        } else {
            lastNode->next = newNode;
            newNode->prev = lastNode;
            list->tail = newNode;
        }
        lastNode = newNode;
        insertHash(enemy, newNode);
    }

    scanf("%d", &Q);
    char command[10];
    for (int i = 0; i < Q; i++) {
        scanf("%s", command);
        if (command[0] == 'I') {
            int p, e;
            scanf("%d %d", &p, &e);
            Node* eNode = searchHash(e);
            insertAfter(list, eNode, p);
        } else if (command[0] == 'R') {
            int e;
            scanf("%d", &e);
            Node* eNode = searchHash(e);
            removeNode(list, eNode);
        } else if (command[0] == 'Q') {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", countBetween(list, a, b));
        }
    }

    return 0;
}
