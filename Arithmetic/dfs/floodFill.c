#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int m,n;
char g[110][110];
int st[110][110];
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
int cnt;
void dfs(int x,int y){
    for(int i=0;i<8;i++){
        int a=x+dx[i],b=y+dy[i];
        if(a<0||a>=n||b<0||b>=m)continue;
        if(g[a][b]=='.')continue;
        if(st[a][b])continue;
        st[a][b]=1;
        dfs(a,b);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",g[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='W'&&st[i][j]==0){
                cnt++;
                dfs(i,j);
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}