#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;
bool a[100010];
int dp[100010];
int prefix[100010];
int main() {
    int n, m, l, r;
    cin >> n >> m;
    cin >> l >> r;

    for (int i = 0; i < m; ++i) {
        int f;
        cin >>f;
        a[f] = true;
    }
    a[n] = true;
    dp[0] = 1; 
    prefix[0] = 1;

    for (int i = 1; i <= n; ++i) {
        if (!a[i]) {
            prefix[i] = prefix[i - 1];
            continue;
        }
        int left = max(0, i - r), right = i - l;
        if (right >= 0) {
            dp[i] = (prefix[right] - (left > 0 ? prefix[left - 1] : 0) + MOD) % MOD;
        }
        prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n] << endl;
    return 0;
}
