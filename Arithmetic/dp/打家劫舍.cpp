#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int cache[1000];
int f[1000];
int n;
int dfs(int i){
    if(i<0)return 0;
    if(cache[i]!=-1)return cache[i];
    int res;
    res=max(dfs(i-1),dfs(i-2)+a[i]);
    cache[i]=res;
    return res;
}
void dp(){
    for(int i=0;i<n;i++){
        f[i+2]=max(f[i+1],f[i]+a[i]);
    }
}
int main(){
    memset(cache,-1,sizeof cache);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",dfs(n-1));
    dp();
    printf("%d\n",f[n+1]);
    return 0;
}