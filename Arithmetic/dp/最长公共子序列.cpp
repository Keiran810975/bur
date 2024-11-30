//每件物品可以重复选
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char s[1000],t[1000];
int dfs(int i,int j){
    if(i<0||j<0)return 0;
    if(s[i]==t[j])return dfs(i-1,j-1);
    return max(dfs(i-1,j),dfs(i,j-1));
}
int f[1000][1000];
void dp(){
    int n=strlen(s),m=strlen(t);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i]==t[j])f[i+1][j+1]=f[i][j]+1;
            else{
                f[i+1][j+1]=max(f[i][j+1],f[i+1][j]);
            }
        }
    }
    printf("%d\n",f[n][m]);
}
int main(){
    scanf("%s%s",s,t);
    int res=dfs(strlen(s)-1,strlen(t)-1);
    printf("%d\n",res);
    dp();
    return 0;
}