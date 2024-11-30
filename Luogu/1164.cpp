#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int dp[10100];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=m;j>=a[i];j--){
            dp[j]+=dp[j-a[i]];
        }
    }
    printf("%d\n",dp[m]);

    return 0;
}