#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char s[1000];
int n;
int cache[1000][1000];
int dfs(int i,int j){
    if(i>j)return 0;
    if(cache[i][j]!=-1)return cache[i][j];
    if(i==j)return 1;
    if(s[i]==s[j])return dfs(i+1,j-1)+2;
    int a=max(dfs(i+1,j),dfs(i,j-1));
    cache[i][j]=a;
    return a;
}
int f[1000][1000];
void dp(){
    for(int i=0;i<n;i++)f[i][i]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]){
                f[i][j]=f[i+1][j-1]+2;
            }else{
                f[i][j]=max(f[i+1][j],f[i][j-1]);
            }
        }
    }
    printf("%d\n",f[0][n-1]);
}
int main(){
    memset(cache,-1,sizeof cache);
    scanf("%s",s);
    n=strlen(s);
    int res=dfs(0,n-1);
    cout<<res<<'\n';
    dp();
    return 0;
}