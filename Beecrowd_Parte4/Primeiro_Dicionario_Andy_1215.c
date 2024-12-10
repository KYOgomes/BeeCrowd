#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_WORDS 5050
#define MAX_LEN 201

typedef struct {
    char word[MAX_LEN];
} String;

bool isAlphabetic(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void normalizeAndAdd(char *temp, String *dictionary, int *count) {
    int len = strlen(temp);
    int idx = 0;
    bool inWord = false;

    for (int i = 0; i < len; i++) {
        if (isAlphabetic(temp[i])) {
            dictionary[*count].word[idx++] = tolower(temp[i]);
            inWord = true;
        } else {
            if (inWord) {
                dictionary[*count].word[idx] = '\0';
                (*count)++;
                idx = 0;
                inWord = false;
            }
        }
    }

    if (inWord) {
        dictionary[*count].word[idx] = '\0';
        (*count)++;
    }
}

int compare(const void *a, const void *b) {
    return strcmp(((String *)a)->word, ((String *)b)->word);
}

int main() {
    String dictionary[MAX_WORDS];
    char tempInput[MAX_LEN];

    int count = 0;

    while (fgets(tempInput, sizeof(tempInput), stdin)) {
        normalizeAndAdd(tempInput, dictionary, &count);
    }

    qsort(dictionary, count, sizeof(String), compare);

    for (int i = 0; i < count; i++) {
        printf("%s\n", dictionary[i].word);
    }

    return 0;
}
