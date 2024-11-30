#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
typedef pair<int,int> pii;
queue <pii> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int dis[350][350];
int g[350][350];
int bfs(int x1,int y1){
    if(g[0][0]==0)return -1;
    memset(dis,-1,sizeof dis);
    q.push({x1,y1});
    dis[x1][y1]=0;
    while(q.size()&&!q.empty()){
        pii t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<0||b<0)continue;
            if(g[a][b]!=-1&&g[a][b]<=dis[t.first][t.second]+1)continue;
            if(dis[a][b]!=-1)continue;
            q.push({a,b});
            dis[a][b]=dis[t.first][t.second]+1;
            if(g[a][b]==-1)return dis[a][b];
        }
    }
    return -1;
}
int main(){
    memset(g,-1,sizeof g);
    scanf("%d",&n);
    int x,y,t;
    while(n--){
        scanf("%d%d%d",&x,&y,&t);
        if(g[x][y]==-1||g[x][y]>t)g[x][y]=t;
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a>=0&&b>=0){
                if(g[a][b]==-1||g[a][b]>t)g[a][b]=t;
            }
        }
    }
    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         printf("%d ",g[i][j]);
    //     }
    //     printf("\n");
    // }
    int res=bfs(0,0);
    printf("%d\n",res);
    return 0;
}