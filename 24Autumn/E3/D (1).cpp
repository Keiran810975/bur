#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
int col[N],num[N];
int ans,sum;
void calc(int x,int fa){
    num[x]+=col[x];
    for(auto i:g[x]){
        if(i!=fa){
            calc(i,x);
            num[x]+=num[i];
        }
    }
}
void dfs(int x,int fa){
    int fl=0;
    if(num[x]!=sum&&num[x]!=0)fl=1;
    for(auto i:g[x]){
        if(i!=fa){
            dfs(i,x);
            if(num[i]!=0&&num[i]!=num[x]-col[x]){
                fl=1;
            }
        }
    }
    if(fl==1&&col[x]!=1)ans++;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>col[i];
        sum+=col[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    calc(1,0);
    dfs(1,0);
    cout<<ans<<"\n";
}
