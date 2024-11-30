#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int n,m;
int f[400][400];
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i!=j){
                f[i][j]=inf;
            }
        }
    }
    for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
            f[u][v]=min(f[u][v],w);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    int q;
    scanf("%lld",&q);
    while(q--){
        int u,v;
        scanf("%lld%lld",&u,&v);
        if(f[u][v]==inf){
            printf("-1\n");
        }else{
            printf("%lld\n",f[u][v]);
        }
    }
    return 0;
}