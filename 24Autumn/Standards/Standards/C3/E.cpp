#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull dp[500001][8];
ull mod = 998244353;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	dp[0][7] = 1;
    dp[1][3] = dp[1][6] = dp[1][0] = 1;
    for (int i = 2; i <= 500000; ++i) {
        for (int j = 0; j <= 7; ++j) {
            if (j == 3 || j == 6) {
                dp[i][j] = (dp[i - 1][7] + dp[i - 1][j ^ 7]) % mod;
            } else if (j == 7) {
                if (i - 2 >= 0)
                    dp[i][j] = dp[i - 2][7];
                else
                    dp[i][j] = 1;
                dp[i][j] = (dp[i][j] + dp[i - 1][3] + dp[i - 1][6]) % mod;
            } else {
                dp[i][j] = dp[i - 1][7 ^ j];
            }
        }
    }
    
    int t;
    int n;
    
    cin >> t;
    for (int i = 0; i < t; ++i) {
    	cin >> n;
    	
		cout << dp[n][7] << endl;
	}
    return 0;
}
