#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int jewelleryValue(vector<vector<int>>& frame) {
    int n=frame.size();
    int m=frame[0].size();
    int dp[210][210];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])+frame[i][j];
        }
    }
    return dp[n][m];
}
int main(){

    return 0;
}