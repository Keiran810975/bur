#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int m[110][110];
int f,v;
int dp[110][110];//dpij：前i个花盆放j颗花
bool st[110];
int main(){
    cin>>f>>v;
    for(int i=1;i<=f;i++){
        for(int j=1;j<=v;j++){
            cin>>m[i][j];
        }
    }
    for(int i=1;i<=v;i++){
        for(int j=;j>=1;j--){
            dp[i][j]=max(dp[i-1][j-1]+m[i][j],dp[i-1][j]);
        }
    }
    cout<<dp[v][f]<<endl;

    return 0;
}