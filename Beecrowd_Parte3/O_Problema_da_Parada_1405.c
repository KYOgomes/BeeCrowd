#include <stdio.h>
#include <string.h>
//erro de tudo
#define MAX 1000
#define MAX_LINES 100

int R[10];
char program[MAX_LINES][50];
int visited[MAX_LINES][MAX];
int L;

int run(int line);
int parseArg(char* s);
int findEndif(int line);

int main() {
    int N;
    while (scanf("%d %d\n", &L, &N), L || N) {
        for (int i = 0; i < L; i++) {
            fgets(program[i], 50, stdin);
        }
        memset(R, 0, sizeof(R));
        R[0] = N;
        memset(visited, 0, sizeof(visited));
        int result = run(0);
        if (result == -1) {
            printf("*\n");
        } else {
            printf("%d\n", result);
        }
    }
    return 0;
}

int run(int line) {
    if (line == L) return R[9];
    if (visited[line][R[0]]) return -1;
    visited[line][R[0]] = 1;
    char cmd[10];
    char args[20];
    sscanf(program[line], "%s %s", cmd, args);
    if (strcmp(cmd, "MOV") == 0) {
        int a, b;
        sscanf(args, "%d,%d", &a, &b);
        R[a] = parseArg(b);
        return run(line + 1);
    } else if (strcmp(cmd, "ADD") == 0) {
        int a, b;
        sscanf(args, "%d,%d", &a, &b);
        R[a] = (R[a] + parseArg(b)) % MAX;
        return run(line + 1);
    } else if (strcmp(cmd, "SUB") == 0) {
        int a, b;
        sscanf(args, "%d,%d", &a, &b);
        R[a] = (R[a] - parseArg(b) + MAX) % MAX;
        return run(line + 1);
    } else if (strcmp(cmd, "MUL") == 0) {
        int a, b;
        sscanf(args, "%d,%d", &a, &b);
        R[a] = (R[a] * parseArg(b)) % MAX;
        return run(line + 1);
    } else if (strcmp(cmd, "DIV") == 0) {
        int a, b;
        sscanf(args, "%d,%d", &a, &b);
        R[a] = parseArg(b) == 0 ? 0 : R[a] / parseArg(b);
        return run(line + 1);
    } else if (strcmp(cmd, "MOD") == 0) {
        int a, b;
        sscanf(args, "%d,%d", &a, &b);
        R[a] = parseArg(b) == 0 ? 0 : R[a] % parseArg(b);
        return run(line + 1);
    } else if (strcmp(cmd, "IFEQ") == 0) {
        int a, b;
        sscanf(args, "%d,%d", &a, &b);
        if (R[a] == parseArg(b)) return run(line + 1);
        else return run(findEndif(line) + 1);
    } else if (strcmp(cmd, "IFNEQ") == 0) {
        int a, b;
        sscanf(args, "%d,%d", &a, &b);
        if (R[a] != parseArg(b)) return run(line + 1);
        else return run(findEndif(line) + 1);
    } else if (strcmp(cmd, "IFG") == 0) {
        int a, b;
        sscanf(args, "%d,%d", &a, &b);
        if (R[a] > parseArg(b)) return run(line + 1);
        else return run(findEndif(line) + 1);
    } else if (strcmp(cmd, "IFL") == 0) {
        int a, b;
        sscanf(args, "%d,%d", &a, &b);
        if (R[a] < parseArg(b)) return run(line + 1);
        else return run(findEndif(line) + 1);
    } else if (strcmp(cmd, "IFGE") == 0) {
        int a, b;
        sscanf(args, "%d,%d", &a, &b);
        if (R[a] >= parseArg(b)) return run(line + 1);
        else return run(findEndif(line) + 1);
    } else if (strcmp(cmd, "IFLE") == 0) {
        int a, b;
        sscanf(args, "%d,%d", &a, &b);
        if (R[a] <= parseArg(b)) return run(line + 1);
        else return run(findEndif(line) + 1);
    } else if (strcmp(cmd, "CALL") == 0) {
        int a;
        sscanf(args, "%d", &a);
        int result = run(parseArg(a));
        if (result == -1) return -1;
        R[9] = result;
        return run(line + 1);
    } else if (strcmp(cmd, "RET") == 0) {
        int a;
        sscanf(args, "%d", &a);
        return parseArg(a);
    } else {
        return -1;
    }
}

int parseArg(char* s) {
    if (s[0] == 'R') {
        return R[s[1] - '0'];
    } else {
        return atoi(s);
    }
}

int findEndif(int line) {
    int count = 1;
    while (count > 0) {
        line++;
        if (strncmp(program[line], "IF", 2) == 0) count++;
        else if (strcmp(program[line], "ENDIF") == 0) count--;
    }
    return line;
}