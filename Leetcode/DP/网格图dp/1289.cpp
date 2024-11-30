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
            int minn=INT_MAX;
            for(int k=0;k<n;k++){
                if(k==j)continue;
                minn=min(f[i-1][k+1],minn);
            }
            f[i][j+1]=minn+matrix[i][j];
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