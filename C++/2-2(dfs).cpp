#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
int n;
char tmp[200][200];
int mm[200][200];
pair<int,int>a,b;
int vis[200][200];
int ans=1e7;
void sc(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>tmp[i][j];
            if(tmp[i][j]=='A'){
                mm[i][j]=0;
                a.first=i;
                a.second=j;
            }
            else if(tmp[i][j]=='B'){
                mm[i][j]=3;
                b.first=i;
                b.second=j;
            }
            else if(tmp[i][j]=='+')mm[i][j]=1;
            else if(tmp[i][j]=='-')mm[i][j]=2;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vis[i][j]=1e7;
        }
    }
}
void dfs(int x,int y,int cnt){
    if(cnt>ans)return;
    if(cnt>vis[x][y])return;
    if(x<1||x>n||y<1||y>n)return;
    if(x==b.first&&y==b.second){
        ans=cnt;
        return;
    }
    vis[x][y]=cnt;
    int xx,yy;
    xx=x-1;yy=y;
    if(mm[xx][yy]!=mm[x][y])dfs(xx,yy,cnt+1);
    xx=x+1;yy=y;
    if(mm[xx][yy]!=mm[x][y])dfs(xx,yy,cnt+1);
    xx=x;yy=y-1;
    if(mm[xx][yy]!=mm[x][y])dfs(xx,yy,cnt+1);
    xx=x;yy=y+1;
    if(mm[xx][yy]!=mm[x][y])dfs(xx,yy,cnt+1);
}
int main(){
    sc();
    dfs(a.first,a.second,0);
    cout<<ans<<endl;
    return 0;
}