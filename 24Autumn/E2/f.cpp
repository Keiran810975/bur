#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
char g[1005][1005];
int x,y,xx,yy;
typedef pair<int,int> pii;
int dis[1005][1005];
queue <pii> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int bfs(int x1,int y1){
    while(!q.empty())q.pop();
    memset(dis,-1,sizeof dis);
    q.push({x1,y1});
    dis[x1][y1]=0;
    while(q.size()&&!q.empty()){
        pii t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a=t.first,b=t.second;
            int aa=t.first,bb=t.second;
            while((!(a+dx[i]<0||b+dy[i]<0||a+dx[i]>=n||b+dy[i]>=m))&&g[a+dx[i]][b+dy[i]]=='.'){
                a+=dx[i],b+=dy[i];
                if(a==xx&&b==yy){
                    return dis[t.first][t.second]+1;
                }
            }
            if(a==aa&&b==bb)continue;
            if(dis[a][b]!=-1)continue;
            dis[a][b]=dis[t.first][t.second]+1;
            q.push({a,b});
            if(a==xx&&b==yy)return dis[xx][yy];
        }   
    }
    return dis[xx][yy];
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        scanf("%d%d%d%d",&x,&y,&xx,&yy);
        x--;y--;xx--;yy--;
        for(int i=0;i<n;i++){
            scanf("%s",g[i]);
        }
        int res=bfs(x,y);
        printf("%d\n",res);
    }
    return 0;
}