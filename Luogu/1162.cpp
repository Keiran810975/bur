#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
typedef pair<int,int> pii;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int g[50][50];
int st[50][50];
queue <pii> q;  
void bfs(int x0,int y0){
    q.push({x0,y0});
    g[x0][y0]=3;
    st[x0][y0]=1;
    while(q.size()&&!q.empty()){
        pii t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<0||a>n+1||b<0||b>n+1)continue;
            if(g[a][b]==1)continue;
            if(st[a][b])continue;
            q.push({a,b});
            st[a][b]=1;
            g[a][b]=3;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    bfs(0,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]==3)printf("0 ");
            else if(g[i][j]==1)printf("1 ");
            else printf("2 ");
        }
        printf("\n");
    }
    return 0;
}