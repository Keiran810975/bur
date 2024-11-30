#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const long long inf=-1e18;
int t;
int n,m;
long long g[1000][1000];
long long cache[1000][1000];
long long dfs(int i,int j){
    if(i<0||j<0)return inf;
    if(i == 0 && j == 0) return g[0][0]; 
    if(cache[i][j]!=-1)return cache[i][j];
    long long b=max(dfs(i-1,j)+g[i][j],dfs(i,j-1)+g[i][j]);
    cache[i][j]=b;
    return b;
}

int f[1010][1010];
void dp(){
    f[1][1]=g[0][0];
    for (int j = 1; j < m; j++) {
        f[1][j+1]=f[1][j+1]+g[0][j];
    }
    for (int i = 1; i < n; i++) {
        f[i+1][1]=f[i][1]+g[i][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            f[i+1][j+1]=max(f[i][j+1],f[i+1][j])+g[i][j];
        }
    }
    printf("%d\n",f[n][m]);

}
int main(){
    scanf("%d",&t);
    while(t--){
        memset(cache,-1,sizeof(cache));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%lld",&g[i][j]);
            }
        }
        long long res=dfs(n-1,m-1);
        printf("%lld\n",res);
        //dp();
    }
    return 0;
}