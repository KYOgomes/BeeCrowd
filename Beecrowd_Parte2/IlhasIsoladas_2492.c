#include <stdio.h>
#include <string.h>

#define MAX_T 1005
#define MAX_LEN 105

int main() {
    int T;
    char X[MAX_LEN], Y[MAX_LEN];
    char origConnections[MAX_T][MAX_LEN];
    char reverseConnections[MAX_T][MAX_LEN];
    int isFunction, invertible;

    while (scanf("%d", &T) == 1) {
        if (T == 0) break;
        
        isFunction = 1;
        invertible = 1;
        
        for (int i = 0; i < T; i++) {
            scanf("%s -> %s", X, Y);
            strcpy(origConnections[i], X);
            strcpy(reverseConnections[i], Y);
        }
        
        // Check if it's a function
        for (int i = 0; i < T; i++) {
            for (int j = i + 1; j < T; j++) {
                if (strcmp(origConnections[i], origConnections[j]) == 0) {
                    if (strcmp(reverseConnections[i], reverseConnections[j]) != 0) {
                        isFunction = 0;
                        break;
                    }
                }
            }
            if (!isFunction) break;
        }
        
        if (!isFunction) {
            printf("Not a function.\n");
        } else {
            // Check if it's invertible
            for (int i = 0; i < T; i++) {
                for (int j = i + 1; j < T; j++) {
                    if (strcmp(reverseConnections[i], reverseConnections[j]) == 0) {
                        if (strcmp(origConnections[i], origConnections[j]) != 0) {
                            invertible = 0;
                            break;
                        }
                    }
                }
                if (!invertible) break;
            }
            
            if (invertible) {
                printf("Invertible.\n");
            } else {
                printf("Not invertible.\n");
            }
        }
    }
    
    return 0;
}
