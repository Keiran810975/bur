#include <stdio.h>
#include <string.h>

#define MAX_N 100005

int count[MAX_N][32];
int a[MAX_N];
void preprocess(int n) {
    memset(count, 0, sizeof(count));
    for (int i = 1; i <= n; i++) {
        for (int bit = 0; bit < 32; bit++) {
            count[i][bit] = count[i-1][bit] + ((a[i] >> bit) & 1);
        }
    }
}
int query(int l, int r) {
    for (int bit = 0; bit < 32; bit++) {
        if ((count[r][bit] - count[l-1][bit]) % 2 != 0) {
            return 1;
        }
    }
    return 0;
}
int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n, q;
        scanf("%d %d", &n, &q);
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        
        preprocess(n);
        
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            
            if (query(l, r)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    
    return 0;
}
