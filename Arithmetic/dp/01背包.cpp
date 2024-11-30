#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cap;//总容量
int w[1000],v[1000];//体积和价值
int cache[1000][1000];
int n;
//i表示第i件物品（选不选），c表示包内剩余容量
int dfs(int i,int c){
    if(i<0)return 0;
    if(cache[i][c]!=-1)return cache[i][c];
    if(c<w[i])return dfs(i-1,c);
    int res=max(dfs(i-1,c),dfs(i-1,c-w[i])+v[i]);
    cache[i][c]=res;
    return res;
}
int f[1000][1000];
void dp(){
    for(int i=0;i<n;i++){
        for(int j=cap;j>=0;j--){
            //选不了
            if(w[i]>j)f[i+1][j]=f[i][j];
            //可以选
            else{
                f[i+1][j]=max(f[i][j],f[i][j-w[i]]+v[i]);
            }
        }
    }
    printf("%d\n",f[n][cap]);
}
//优化(节省空间)
int ff[1000];
void dp2(){
    for(int i=1;i<=n;i++){
        for(int j=cap;j>=w[i];j--){
            ff[j]=max(ff[j],ff[j-w[i]]+v[i]);
        }
    }
}
int main(){
    memset(cache,-1,sizeof cache);
    cin>>cap>>n;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    //printf("%d\n",dfs(n-1,cap));
     dp();
    return 0;
}