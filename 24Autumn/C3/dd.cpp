#include<iostream>
#include<cstring>
using namespace std;

int prices[200010];
long long dp[200010][2]; 

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &prices[i]);
        }
        dp[0][0] = 0;   
        dp[0][1] = prices[0]; 
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);   
            dp[i][1] = dp[i-1][0] + prices[i];          
        }
        cout << max(dp[n-1][0], dp[n-1][1]) << '\n';
    }
    
    return 0;
}
