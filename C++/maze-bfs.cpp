#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int nex[4][2]={{1,0},{-1,0},{0,1},{0,-1}};//移动的四个方向
int n,a[300][300];
int vis[300][300];
int tmp[300][300];
pair<int,int>st,ed;
struct node{
    int x,y,cnt;
};
bool check(int x,int y){//判断移动的正确性
    if(x<1||x>n||y<1||y>n||vis[x][y]==1)return false;
    return true;
}
int bfs(int x,int y){
    pair<int,int>u=make_pair(x,y);
    queue<node>q;
    q.push(node{x,y,0});
    vis[x][y]=1;
    while(!q.empty()){
        node u=q.front();
        if(u.x==ed.first&&u.y==ed.second)return u.cnt;//到终点
        q.pop();
        int x=u.x,y=u.y;
        //四个方向遍历
        for(int i=0;i<=3;i++){
            int xx=x+nex[i][0];
            int yy=y+nex[i][1];
            if(!check(xx,yy)||a[xx][yy]==a[x][y])continue;
            vis[xx][yy]=1;
            q.push(node{xx,yy,u.cnt+1});//bfs下一个点
        }
    }
    return -1;
}
void sc(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char x;
            cin>>x;
            if(x=='A')st.first=i,st.second=j,a[i][j]=-1;
            else if(x=='B')ed.first=i,ed.second=j,a[i][j]=-1;
            else if(x=='+')a[i][j]=1;
            else a[i][j]=0;
        }
    }
}
int main(){
    sc();
    cout<<bfs(st.first,st.second)<<endl;
    return 0;
}