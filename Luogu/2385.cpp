#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int g[1100][1100];
int x,y,xx,yy;
typedef pair<int,int> pii;
int dis[1100][1100];
queue <pii> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int bfs(int x1,int y1){
    memset(dis,-1,sizeof dis);
    q.push({x1,y1});
    dis[x1][y1]=0;
    while(q.size()&&!q.empty()){
        pii t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<1||a>n||b<1||b>n)continue;
            if(g[a][b]!=0)continue;
            if(dis[a][b]!=-1)continue;
            q.push({a,b});
            dis[a][b]=dis[t.first][t.second]+1;

            if(a==xx&&b==yy)return dis[xx][yy];
        }   
    }
    return dis[xx][yy];
}
int main(){
    
    return 0;
}