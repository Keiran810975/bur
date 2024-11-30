#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        int n,V;
        scanf("%lld%lld",&n,&V);
        int w[n+5],v[n+5];
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&w[i],&v[i]);
        }
        int dp[V+5];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=V;j>=v[i];j--){
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
            }
        }
        printf("%lld\n",dp[V]);
    }

    return 0;
}