#include <stdio.h>

int main() {
    int N;
    
    while (scanf("%d", &N) != EOF) {
        long long sumTotal = (long long) N * (N + 1) / 2;
        long long sumReturned = 0;
        
        for (int i = 0; i < N - 1; i++) {
            int returnedPen;
            scanf("%d", &returnedPen);
            sumReturned += returnedPen;
        }
        
        long long missingPen = sumTotal - sumReturned;
        printf("%lld\n", missingPen);
    }
    
    return 0;
}
