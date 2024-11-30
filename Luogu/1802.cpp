#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x;
int lose[1010],win[1010],use[1010];
int cache[1010][1010];
int dfs(int i,int cap){
    if(i<1)return 0;
    if(cache[i][cap]!=-1)return cache[i][cap];
    if(use[i]>cap)return dfs(i-1,cap)+lose[i];
    return cache[i][cap]=max(dfs(i-1,cap)+lose[i],dfs(i-1,cap-use[i])+win[i]);

}
int f[1010][1010];
void dp(){
    for(int i=1;i<=n;i++){
        for(int j=x;j>=0;j--){
            if(use[i]>j){
                f[i][j]=f[i-1][j]+lose[i];
            }else{
                f[i][j]=max(f[i-1][j]+lose[i],f[i-1][j-use[i]]+win[i]);
            }
        }
    }
    printf("%lld\n",f[n][x]*5);
}
signed main(){
    scanf("%lld%lld",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&lose[i],&win[i],&use[i]);
    }
    // memset(cache,-1,sizeof cache);
    // int res=dfs(n,x);
    // printf("%d\n",res*5);
    dp();
    return 0;
}