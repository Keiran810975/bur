#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int xx,yy;
char g[550][550];
int dis[550][550];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
typedef pair<int,int> pii;
deque <pii> q;
int bfs(int x,int y){
    memset(dis,-1,sizeof dis);
    q.clear();
    q.push_back({x,y});
    dis[x][y]=0;
    while(q.size()){
        pii t=q.front();
        q.pop_front();
        for(int i=0;i<4;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<0||a>=n||b<0||b>=m)continue;
            if(dis[a][b]!=-1)continue;
            if(g[a][b]==g[t.first][t.second]){
                dis[a][b]=dis[t.first][t.second];
                q.push_front({a,b});
            }
            if(g[a][b]!=g[t.first][t.second]){
                dis[a][b]=dis[t.first][t.second]+1;
                q.push_back({a,b});
            }
            if(a==xx&&b==yy){
                return dis[a][b];
            }
        }
    }
    return -1;
}
int main(){
    while(1){
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        for(int i=0;i<n;i++){
            scanf("%s",g[i]);
        }
        int x0,y0;
        scanf("%d%d%d%d",&x0,&y0,&xx,&yy);
        int res=bfs(x0,y0);
        printf("%d\n",res);
    }
    return 0;
}
