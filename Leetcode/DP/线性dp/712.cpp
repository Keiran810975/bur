#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minimumDeleteSum(string s1, string s2) {
    int n=s1.length(),m=s2.length();
    vector<vector<int>> f(n+1,vector<int>(m+1));
    f[0][0]=0;
    for(int i=1;i<=n;i++)f[i][0]=s1[i-1]+f[i-1][0];
    for(int i=1;i<=m;i++)f[0][i]=s2[i-1]+f[0][i-1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                f[i][j]=f[i-1][j-1];
            }else{
                f[i][j]=min(f[i][j-1]+s2[i-1],f[i-1][j]+s1[i-1]);
            }
        }
    }     
    return f[n][m];           
}
int main(){

    return 0;
}