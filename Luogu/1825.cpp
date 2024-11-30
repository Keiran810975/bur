#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;

char g[400][400];
int dis[400][400];
typedef pair<int,int> pii;
pii d1[30];
pii d2[30];

queue <pii> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int bfs(int x1,int y1){
    memset(dis,-1,sizeof dis);
    if(g[x1][y1]>='A'&&g[x1][y1]<='Z'){
        if()
    }
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
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        getchar();
        for(int j=1;j<=m;j++){
            scanf("%c",&g[i][j]);
            if(g[i][j]>='A'&&g[i][j]<='Z'){
                if(d1[g[i][j]-'A'] == pii{0,0}){
                    d1[g[i][j]-'A']=pii{i,j};
                }else{
                    d2[g[i][j]-'A']=pii{i,j};
                }
            }
        }
    }
    return 0;
}