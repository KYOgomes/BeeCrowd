#include <stdio.h>
#include <string.h>

void print_char_multiple_times(char c, int count) {
    for (int i = 0; i < count; i++) {
        putchar(c);
    }
}

int main() {
    int N;
    scanf("%d\n", &N);
    
    for (int t = 0; t < N; t++) {
        char line[1000];
        fgets(line, sizeof(line), stdin);
        
        int i = 0;
        while (i < strlen(line)) {
            char currentChar = line[i];
            
            if (currentChar == '0') {
                int count = 0;
                while (i < strlen(line) && line[i] == '0') {
                    count++;
                    i++;
                }
                
                if (count > 2) {
                    printf("#%d", count);
                } else {
                    print_char_multiple_times('0', count);
                }
                
            } else if (currentChar == ' ') {
                int count = 0;
                while (i < strlen(line) && line[i] == ' ') {
                    count++;
                    i++;
                }
                
                if (count > 2) {
                    printf("$%d", count);
                } else {
                    print_char_multiple_times(' ', count);
                }
                
            } else {
                putchar(currentChar);
                i++;
            }
        }
        
        printf("\n");
    }
    
    return 0;
}