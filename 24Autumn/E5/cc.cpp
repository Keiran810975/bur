#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int l,r;
bool a[100010];
int ans;
void dfs(int x){
    for(int i=l;i<=r;i++){
        if(x+i==n){
            ans++;
            ans%=998244353;
            return;
        }
        if(x+i>n)return;
        if(!a[x+i])continue;
        dfs(x+i);
    }
}
int dp[100010];
int main(){
    cin>>n>>m>>l>>r;
    for(int i=1;i<=m;i++){
        int f;
        cin>>f;
        a[f]=true;
    }
    a[n]=true;
    dp[0]=1;
    // dfs(0);
    // printf("%d\n",ans); 
    for(int i=1;i<=n;i++){
        if(!a[i])continue;
        for(int j=max(i-r,0);j<=i-l;j++){
            dp[i]+=dp[j];
            dp[i]%=998244353;
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
