#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000][1000];
int cache[1000][1000];
int dfs(int i,int j){
    if(i<0||j<0)return 0;
    if(cache[i][j]!=-1)return cache[i][j];
    int b=max(dfs(i-1,j)+a[i][j],dfs(i,j-1)+a[i][j]);
    cache[i][j];
    return b;
}
int f[1000][1000];
void dp(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            f[i+1][j+1]=max(f[i][j+1]+a[i][j],f[i+1][j]+a[i][j]);
        }
    }
    printf("%d\n",f[n][m]);
}
int main(){
    memset(cache,-1,sizeof cache);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int res=dfs(n-1,m-1);
    printf("%d\n",res);
    dp();
    return 0;
}