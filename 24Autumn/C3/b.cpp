#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define int long long
const int MAX_N = 10005;
int p[MAX_N]; 
int dp[MAX_N];     
int cut[MAX_N];
int result[MAX_N];

signed main() {
    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &p[i]);
    }
    memset(dp, 0, sizeof(dp));
    memset(cut, 0, sizeof(cut));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if(i>=j)
            if (dp[i] < p[j] + dp[i - j]) {
                dp[i] = p[j] + dp[i - j];
                cut[i] = j;
            }
        }
    }
    printf("%lld\n", dp[n]);
    
    int length = n;
    int cnt = 0;

    while (length > 0) {
        result[cnt++] = cut[length];
        length -= cut[length];
    }

    printf("%lld\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%lld ", result[i]);
    }
    printf("\n");

    return 0;
}
