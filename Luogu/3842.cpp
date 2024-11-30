#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[20050][2];
int main(){
    int n;
    cin>>n;
    int l[n+1],r[n+1];
    l[0]=1,r[0]=1;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]);
    }
    dp[0][0]=0;
    dp[0][1]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=min(dp[i-1][0]+r[i]-l[i]+abs(l[i-1]-r[i]),dp[i-1][1]+r[i]-l[i]+abs(r[i-1]-r[i]));
        dp[i][1]=min(dp[i-1][0]+r[i]-l[i]+abs(l[i-1]-l[i]),dp[i-1][1]+r[i]-l[i]+abs(r[i-1]-l[i]));
    }
    printf("%d\n",min(dp[n][0]+abs(n-l[n]),dp[n][1]+abs(n-r[n]))+n-1);
    return 0;
}