#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
typedef pair<int,int> pii;
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
int g[50][50];
int st[50][50];
queue <pii> q;  
void bfs(int x0,int y0){
    q.push({x0,y0});
    st[x0][y0]=1;
    while(q.size()&&!q.empty()){
        pii t=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<1||a>n||b<1||b>n)continue;
            if(st[a][b])continue;
            q.push({a,b});
            st[a][b]=1;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    return 0;
}