#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    int f[110][110];
    memset(f,0,sizeof f);
    for(int i=0;i<m;i++){
        f[i][0]=1;
    }
    for(int i=0;i<n;i++){
        f[0][i]=1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            f[i][j]=f[i-1][j]+f[i][j-1];
        }
    }        
    return f[m-1][n-1];
}
//空间优化
int uniquePaths2(int m, int n) {
    vector<int> f(n,1);
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            f[j]=f[j-1];
        }
    }
}
int main(){

    return 0;
}