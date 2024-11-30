#include<iostream>
#include<cstring>
using namespace std;

const int mod = 998244353;
const int MAXN = 1000010;

int n, m, k;
bool isTrap[MAXN]; 
long long dp[MAXN][2]; 

int main() {
    cin >> n >> m >> k;
    
    memset(isTrap, 0, sizeof(isTrap));

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        isTrap[x] = true; 
    }

    if (isTrap[1]) {
        dp[1][0] = k - 1;  
        dp[1][1] = 0;
    } else {
        dp[1][0] = k - 1; 
        dp[1][1] = 1; 
    }

    for (int i = 2; i <= n; i++) {
        if (isTrap[i]) {
            dp[i][0] = (dp[i-1][0] * (k-2) % mod + dp[i-1][1] * (k-1) % mod) % mod;
            dp[i][1] = 0; 
        } else {
            dp[i][0] = (dp[i-1][0] * (k-2) % mod + dp[i-1][1] * (k-1) % mod) % mod;  
            dp[i][1] = dp[i-1][0] % mod; 
        }
    }
    long long result = (dp[n][0] + dp[n][1]) % mod;
    cout << result << endl;

    return 0;
}
