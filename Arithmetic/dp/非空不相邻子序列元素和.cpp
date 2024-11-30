#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int dfs(int i){
    if(i<0)return 0;
    return max(dfs(i-1),dfs(i-2)+a[i]);
}
int f[1000];
void dp(){
    for(int i=0;i<n;i++){
        f[i+2]=max(f[i+1],f[i]+a[i]);
    }
    printf("%d\n",f[n+1]);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int res=dfs(n-1);
    printf("%d\n",res);
    dp();
    return 0;
}