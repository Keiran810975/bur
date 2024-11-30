#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int g[1100][1100];
int x,y,xx,yy;
typedef pair<int,int> pii;
int dis[1100][1100];
queue <pii> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int bfs(int x1,int y1){
    memset(dis,-1,sizeof dis);
    while(!q.empty()) q.pop();
    q.push({x1,y1});
    dis[x1][y1]=0;
    while(q.size()&&!q.empty()){
        pii t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a = t.first, b = t.second;
            while (1) {
                a += dx[i];
                b += dy[i];
                if (a < 1 || a > n || b < 1 || b > m) break;
                if (dis[a][b] != -1) continue;
                if ((i == 0 || i == 2) && g[a][b] != g[t.first][t.second]) { 
                    break;
                } 
                else if ((i == 1 || i == 3) && g[a][b] == g[t.first][t.second]) {
                    break;
                }
                dis[a][b] = dis[t.first][t.second] + 1;
                q.push({a, b});
                if (a == n && b == m) return dis[n][m];
            }
        }
    }
    return dis[xx][yy];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&g[i][j]);
        x=1,y=1,xx=n,yy=m;
        int res=bfs(x,y);
        printf("%d\n",res);
    }
    
    return 0;
}