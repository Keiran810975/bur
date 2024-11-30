#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int m[110][110];
int f,v;
int dp[110][110];//dpij：前i个花盆放j颗花
int main(){
    cin>>f>>v;
    for(int i=1;i<=f;i++){
        for(int j=1;j<=v;j++){
            cin>>m[i][j];
        }
    }
     for(int i=1;i<=f;i++)
        dp[i][i]=dp[i-1][i-1]+m[i][i];
    dp[0][0] = 0;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=f;j++){
            dp[i+1][j+1]=max(dp[i][j]+m[i][j],dp[i][j+1]);
        }
    }
    cout<<dp[v+1][f+1]<<endl;

    return 0;
}