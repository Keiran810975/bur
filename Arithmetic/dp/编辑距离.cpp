#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char s[3000],t[3000];
int dp[3000][3000];
int main(){
    scanf("%s%s",s,t);
    int l1=strlen(s),l2=strlen(t);
    for(int i=1;i<=l1;i++)dp[i][0]=i;
    for(int i=1;i<=l2;i++)dp[0][i]=i;
    for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
            if(s[i]==t[j]){
                dp[i+1][j+1]=dp[i][j];
            }else{
                dp[i+1][j+1]=min(min(dp[i][j+1],dp[i+1][j]),dp[i][j])+1;
            }
        }
    }
    printf("%d\n",dp[l1][l2]);

    return 0;
}