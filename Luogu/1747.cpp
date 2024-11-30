#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
queue <pii> q;
int dx[]={-2,-1,1,2,2,1,-1,-2,-2,2,2,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1,2,2,-2,-2};
int dis[100][100];
int bfs(int x1,int y1){
    while(!q.empty())q.pop();
    memset(dis,-1,sizeof dis);
    dis[x1][y1]=0;
    q.push({x1,y1});
    while(q.size()&&!q.empty()){
        pii t=q.front();
        q.pop();
        for(int i=0;i<12;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<1||b<1)continue;
            if(dis[a][b]!=-1)continue;
            q.push({a,b});
            dis[a][b]=dis[t.first][t.second]+1;
            if(a==1&&b==1)return dis[a][b];
        }   
    }
    return dis[1][1];
}
int main(){
    int x,y,xx,yy;
    scanf("%d%d%d%d",&x,&y,&xx,&yy);
    int res=bfs(x,y);
    int ress=bfs(xx,yy);
    printf("%d\n%d\n",res,ress);
    return 0;
}