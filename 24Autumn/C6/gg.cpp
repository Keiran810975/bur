#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

int cap; 
int w[150], v[150], num[150]; 
int n; 

void dp2() {
    vector<int> dp(cap + 1, 0); 
    for (int i = 0; i < n; ++i) {
        int quantity = num[i];
        int weight = w[i];
        int value = v[i];

        for (int k = 1; k <= quantity; k *= 2) {
            int numItems = min(k, quantity);  // 取出最小的数量（1, 2, 4...）
            for (int j = cap; j >= numItems * weight; --j) {
                dp[j] = max(dp[j], dp[j - numItems * weight] + numItems * value);
            }
            quantity -= numItems; 
        }   
        if (quantity > 0) {
            for (int j = cap; j >= quantity * weight; --j) {
                dp[j] = max(dp[j], dp[j - quantity * weight] + quantity * value);
            }
        }
    }
    cout << dp[cap] << '\n';
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> cap;
        for (int i = 0; i < n; i++) {
            cin >> num[i] >> w[i] >> v[i];
        }
        dp2();
    }
    return 0;
}
