#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int nextPermutation(char *str, int size) {
    int i = size - 2;
    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }
    if (i < 0) {
        return 0;
    }
    int j = size - 1;
    while (str[j] <= str[i]) {
        j--;
    }
    swap(&str[i], &str[j]);
    for (int a = i + 1, b = size - 1; a < b; a++, b--) {
        swap(&str[a], &str[b]);
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char str[11];
        scanf("%s", str);
        int size = strlen(str);
        qsort(str, size, sizeof(char), compare);
        do {
            printf("%s\n", str);
        } while (nextPermutation(str, size));
        printf("\n");
    }
    return 0;
}