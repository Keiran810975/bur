#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>> f(n + 2, vector<int>(n + 2, INT_MAX));

    for(int j=0;j<n;j++){
        f[0][j+1]=matrix[0][j];
    }
    int ans=INT_MAX;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            f[i][j+1]=min(min(f[i-1][j],f[i-1][j+1]),f[i-1][j+2])+matrix[i][j];
        }
    }
    for(int j=1;j<=n;j++){
        ans=min(ans,f[n-1][j]);
    }
    return ans;
}
int main(){

    return 0;
}