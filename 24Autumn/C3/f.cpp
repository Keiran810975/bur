#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char s[2005],t[2005];
//子串
int dfs(int i,int j){
    if(i<0||j<0)return 0;
    if(s[i]==t[j])return dfs(i-1,j-1)+1;
    return max(dfs(i-1,j),dfs(i,j-1));
}
//子序列
int dfs2(int i,int j){
    if(i<0||j<0)return 0;
    if(s[i]==t[j])return dfs2(i-1,j-1);
    return max(dfs2(i-1,j),dfs2(i,j-1));
}
int f[2005][2005];
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
int ff[2005][2005];

void dp2(){
    int ans=0;
    int n=strlen(s),m=strlen(t);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i]==t[j]){
                ff[i+1][j+1]=ff[i][j]+1;
                ans=max(ans,ff[i+1][j+1]);
            }
            else{
                ff[i+1][j+1]=0;
            }
        }
    }
    printf("%d ",ans);
}
int main(){
    int ff;
    scanf("%d",&ff);
    while(ff--){
        scanf("%s%s",s,t);
        dp2();
        dp();
    }
    return 0;
}