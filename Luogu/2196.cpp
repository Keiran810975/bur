#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int g[50][50];
int num[50];
bool st[50];
int path[50],ans[50];
int cnt;
int m;
bool check(int x){
    for(int i=1;i<=n;i++){
        if(g[x][i]&&!st[i])return true;
    }
    return false;
}
void dfs(int x,int sum,int step){
    if(!check(x)){
        if(m<sum){
            m=sum;
            cnt=step;
            for(int i=1;i<=step;i++){
                ans[i]=path[i];
            }
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!g[x][i]||st[i])continue;
        st[i]=true;
        path[step+1]=i;
        dfs(i,step+1,sum+num[i]);
        st[i]=false;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        st[i]=true;
        path[1]=i;
        dfs(i,1,num[i]);
        st[i]=false;
    }
    for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);
    printf("\n%d\n",m);
    return 0;
}