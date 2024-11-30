#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int hx,hy;
int g[100][100];
int f[100][100];
int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
void dp(){
    f[0][0]=g[0][0] ? 0 : 1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(g[i][j])f[i][j]=0;
            else{
                if(i>0)f[i][j]+=f[i-1][j];
                if(j>0)f[i][j]+=f[i][j-1];
            }
        }
    }
    printf("%lld\n",f[n][m]);
}
signed main(){
    scanf("%lld%lld%lld%lld",&n,&m,&hx,&hy);
    g[hx][hy]=1;
    for(int i=0;i<8;i++){
        int a=hx+dx[i],b=hy+dy[i];
        if(a<0||a>n||b<0||b>m)continue;
        g[a][b]=1;
    }
    dp();
    return 0;
}