#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int n, m;
int g[MAXN][MAXN]; 
int dp[MAXN][MAXN]; //缓存
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j]; 
    dp[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int a = i + dx[k], b = j + dy[k];
        if (a >= 0 && a < n && b >= 0 && b < m && g[i][j] > g[a][b]) {
            dp[i][j] = max(dp[i][j], dfs(a, b) + 1);
        }
    }
    return dp[i][j];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d",&g[i][j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res = max(res, dfs(i, j));
        }
    }
    printf("%d\n",res);
    return 0;
}
