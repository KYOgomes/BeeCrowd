#include <stdio.h>
#include <string.h>

void print_sorobov(int number) {
    char top1[10] = "000000000";
    char top2[10] = "000000000";
    char bottom1[10] = "000000000";
    char bottom2[10] = "000000000";
    char bottom3[10] = "000000000";
    char bottom4[10] = "000000000";
    char bottom5[10] = "000000000";

    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%09d", number);

    for (int i = 0; i < 9; i++) {
        int digit = buffer[i] - '0';
        if (digit >= 5) {
            top2[i] = '1';
            digit -= 5;
        } else {
            top1[i] = '1';
        }

        if (digit >= 1) bottom1[i] = '1';
        if (digit >= 2) bottom2[i] = '1';
        if (digit >= 3) bottom3[i] = '1';
        if (digit >= 4) bottom4[i] = '1';
    }

    printf("%s\n%s\n---------\n%s\n%s\n%s\n%s\n%s\n\n", top1, top2, bottom1, bottom2, bottom3, bottom4, bottom5);
}

int main() {
    int number;
    while (scanf("%d", &number) != EOF) {
        print_sorobov(number);
    }
    return 0;
}
