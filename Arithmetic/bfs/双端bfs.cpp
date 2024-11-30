#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int g[1100][1100];
int dis[1100][1100];
int vis[1100][1100];
int x,y,xx,yy;
typedef pair<int,int> pii;
queue <pii> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int bfs(){
    memset(dis,-1,sizeof dis);
    q.push({x,y});
    q.push({xx,yy});
    dis[x][y]=0,dis[xx][yy]=0;
    vis[x][y]=1,vis[xx][yy]=2;
    while(q.size()&&!q.empty()){
        pii t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<1||a>n||b<1||b>n)continue;
            if(g[a][b]!=0)continue;
            if(vis[a][b]+vis[t.first][t.second]==3){
                return dis[a][b]+dis[t.first][t.second]+1;
            }
            if(dis[a][b]!=-1)continue;
            dis[a][b]=dis[t.first][t.second]+1;
            vis[a][b]=vis[t.first][t.second];
            q.push({a,b});
        }
    }
    return -1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%1d",&g[i][j]);
    scanf("%d%d%d%d",&x,&y,&xx,&yy);
    int res=bfs();
    printf("%d\n",res);
    return 0;
}