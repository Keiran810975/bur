
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define inf -1e9
int n;
int prices[200010];
int cache[200010][2];
int dfs(int i,int flag){
    if(i<0){
        return 0;
    }   
    if(cache[i][flag]!=-1)return cache[i][flag];
    if(flag){
        int a=dfs(i-1,0)+prices[i];
        cache[i][flag]=a;
        return a;
    }else{
        int a=max(dfs(i-1,0),dfs(i-1,1));
        cache[i][flag]=a;
        return a;
    }
}

// int f[1000][1000];
// void dp(){
//     f[0][0]=0;
//     f[0][1]=inf;
//     for(int i=0;i<n;i++){
//         f[i+1][1]=max(f[i][1],f[i][0]-prices[i]);
//         f[i+1][0]=max(f[i][0],f[i][1]+prices[i]);
//     }
//     printf("%d\n",f[n][0]);
// }
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(cache,-1,sizeof cache);
        cin>>n;
        for(int i=0;i<n;i++)cin>>prices[i];
        int res=max(dfs(n-1,0),dfs(n-1,1));
        printf("%d\n",res);
    }
    
    //dp();
    return 0;
}