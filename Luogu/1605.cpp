#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int n,m,t;
int sx,sy,fx,fy;
int cnt;
int g[10][10];
int st[10][10];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(int x,int y){
    if(x==fx&&y==fy){
            cnt++;
            st[x][y]=0;
            return;
        }
    for(int i=0;i<4;i++){
        int a=x+dx[i],b=y+dy[i];
        if(a<1||b<1||a>n||b>m)continue;
        if(st[a][b]||g[a][b]==1)continue;
        st[a][b]=1;
        dfs(a,b);
        st[a][b]=0;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
    st[sx][sy]=1;
    while(t--){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x][y]=1;
    }
    dfs(sx,sy);
    printf("%d\n",cnt);
    return 0;
}