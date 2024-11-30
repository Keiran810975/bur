#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
int col[N];
int n;
int dep[N],far[N][2];
int ans;
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    far[x][col[x]]=dep[x];
    for(int i:g[x]){
        if(i!=fa){
            dfs(i,x);
            for(int j=0;j<2;j++){
                if(far[x][j]!=-1&&far[i][j^1]!=-1){
                    ans = max(ans,far[x][j]-dep[x]+far[i][j^1]-dep[x]);
                }
            }
            for(int j=0;j<2;j++){
                far[x][j]=max(far[x][j],far[i][j]);
            }
        }
    }
    ans = max(ans,far[x][col[x]^1]-dep[x]);
}
int main(){
    int n;
    cin>>n;
    memset(far,-1,sizeof far);
    for(int i=1;i<=n;i++){
        cin>>col[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans<<"\n";
}