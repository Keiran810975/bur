//每件物品可以重复选
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cap;//总容量
int w[1000],v[1000];//体积和价值
int cache[1000];
int n;
//i表示第i件物品（选不选），c表示包内剩余容量
int dfs(int i,int c){
    if(i<0)return 0;
    if(cache[i]!=-1)return cache[i];
    if(c<w[i])return dfs(i-1,c);
    int res=max(dfs(i-1,c),dfs(i-1,c-w[i])+v[i]);
    cache[i]=res;
    return res;
}
int f[1000][1000];
void dp(){
    for(int i=1;i<n;i++){
        for(int j=0;j<=cap;j++){
            //选不了
            if(j<w[i])f[i][j]=f[i-1][j];
            //可以选
            else{
                f[i][j]=max(f[i-1][j],f[i][j-w[i]]+v[i]);
            }
        }
    }
}
int f2[1010];
void dp2(){
    for(int i=1;i<=n;i++){
        for(int j=w[i];j<=cap;j++){
            f2[j]=max(f2[j],f2[j-w[i]]+v[i]);
        }
    }
    printf("%d\n",f2[cap]);
}
int main(){
    memset(cache,-1,sizeof cache);
    cin>>n>>cap;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++)cin>>v[i];
    dp();
    printf("%d\n",f[n][cap]);
    return 0;
}