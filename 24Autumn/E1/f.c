#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int mod = 1e9+7;
//计算组合数
long long C(int n, int m) {
    long long dp[n+1][m+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m && j <= i; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1; // C(n, 0) = 1 和 C(n, n) = 1
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n,m,k;
        scanf("%d%d%d", &n, &m, &k);
        if(m<2*k){
            printf("0\n");
        }else{
            long long a=C(n,k)%mod;
            long long b=C(2*n-2*k,m-2*k)-(n-k)%mod;
            long long ans=a*b%mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}