#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
typedef pair<int,int> pii;
queue <pii> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int bfs(int x1,int y1){
    q.push({x1,y1});
    while(q.size()&&!q.empty()){
        pii t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<1||a>n||b<1||b>n)continue;
            //if(g[a][b]!=0)continue;
            //if(dis[a][b]!=-1)continue;
            q.push({a,b});
        }   
    }
}
int main(){
    
    return 0;
}