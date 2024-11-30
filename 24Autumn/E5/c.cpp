#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int l,r;
bool a[100010];
int ans;
void dfs(int x){
    for(int i=l;i<=r;i++){
        if(x+i==n){
            ans++;
            ans%=998244353;
            return;
        }
        if(x+i>n)return;
        if(!a[x+i])continue;
        dfs(x+i);
    }
}
int main(){
    cin>>n>>m>>l>>r;
    for(int i=1;i<=m;i++){
        int f;
        cin>>f;
        a[f]=true;
    }
    dfs(0);
    printf("%d\n",ans);
    return 0;
}