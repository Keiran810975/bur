#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[100100];
int dp[101000];
int flag[100100];
const int inf = -1e9;
signed main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(dp, 0, sizeof(dp));
        memset(flag, 0, sizeof(flag));
        int res=inf;
        int n, w;
        scanf("%lld%lld", &n, &w);
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        dp[0] = a[0];
        dp[1] = a[1] + a[0];
        flag[0] = flag[1] = 1;
        for (int i = 0; i < n; i++) {
            int sum = dp[i] - w;
            if (i == 0) sum = dp[i];
            int step = 1;
            int j = i + step;
            while (j < n) {
                sum += a[j];
                if (flag[j])
                    dp[j] =max(dp[j], sum);
                else dp[j] = sum;
                flag[j] = 1;
                step++;
                j += step;
            }
            if (sum > res) res = sum;
            dp[i] = max(dp[i], dp[i]-w);
        }
        printf("%lld\n", res);
        
    }
    return 0;
}