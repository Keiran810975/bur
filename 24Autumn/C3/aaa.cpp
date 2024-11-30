#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 1e9;
const int MAX_M = 10005; 
long long min(long long a,long long b,long long c){
    return min(min(a,b),c);
}
long long line[3][MAX_M];    
long long timee[3][3];     
long long dp[3][MAX_M];      
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int m;
        scanf("%d", &m);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &line[i][j]);
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &timee[i][j]);
            }
        }
        for (int i = 0; i < 3; i++) {
            dp[i][0] = line[i][0]; 
        }
    
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < 3; i++) {
                dp[i][j] = dp[i][j-1] + line[i][j];  
                for (int k = 0; k < 3; k++) {
                    if (i != k) {
                        dp[i][j] = min(dp[i][j], dp[k][j-1] + timee[k][i] + line[i][j]);
                    }
                }
            }
        }
        long long result = min({dp[0][m-1], dp[1][m-1], dp[2][m-1]});
        printf("%lld\n", result);
    }
    
    return 0;
}
