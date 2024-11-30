#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cap,n;
int v[50];
int dp[20020];
int main(){
    cin>>cap>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    fill(dp, dp + cap + 1, cap);
    for(int i=0;i<n;i++){
        for(int j=cap;j>=v[i];j--){
            dp[j]=min(dp[j],dp[j-v[i]]-v[i]);
        }
    }
    printf("%d\n",dp[cap]);

    return 0;
}