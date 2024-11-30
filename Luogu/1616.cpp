#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,m;
int a[10100],b[10100];
int dp[10100000];
signed main(){
    scanf("%lld%lld",&t,&m);
    for(int i=0;i<m;i++){
        scanf("%lld%lld",&a[i],&b[i]);
    }
    for(int i=0;i<m;i++){
        for(int j=a[i];j<=t;j++){
            dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
        }
    }
    printf("%lld\n",dp[t]);
    
    return 0;
}