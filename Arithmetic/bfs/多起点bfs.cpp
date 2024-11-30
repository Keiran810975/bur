//血色先锋队
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
typedef pair<int,int> pii;
int dis[1100][1100];
queue <pii> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void bfs(){
    while(q.size()&&!q.empty()){
        pii t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<1||a>n||b<1||b>m)continue;
            if(dis[a][b])continue;
            q.push({a,b});
            dis[a][b]=dis[t.first][t.second]+1;
        }   
    }
}
int main(){
    int a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=0;i<a;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        q.push({x,y});
        dis[x][y]=1;
    }
    bfs();
    for(int i=0;i<b;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",dis[x][y]-1);
    }
    return 0;
}