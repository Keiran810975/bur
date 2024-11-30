#include <stdio.h>

long long catalan(int n) {
    if (n == 0 || n == 1) return 1;
    long long C[n+1];
    C[0] = C[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        C[i] = 0;
        for (int j = 0; j < i; j++) {
            C[i] += C[j] * C[i - j - 1];
        }
    }
    return C[n];
}

int main() {
    int n;
    scanf("%d", &n);
    
    printf("n  : P(n)\n");
    for (int i = 1; i <= n; i++) {
        printf("%-3d: %lld\n", i, catalan(i-1));
    }
    
    return 0;
}
