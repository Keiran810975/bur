#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int w,h;
char maze[25][25];
int cnt;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int st[25][25];
void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int a=x+dx[i],b=y+dy[i];
        if(a<0||a>=h||b<0||b>=w)continue;
        if(maze[a][b]!='.')continue;
        if(st[a][b])continue;
        st[a][b]=1;
        cnt++;
        dfs(a,b);       
    }
}
int main(){
    scanf("%d%d",&w,&h);
    for(int i=0;i<h;i++)scanf("%s",maze[i]);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(maze[i][j]=='@'){
                st[i][j]=1;
                dfs(i,j);
                break;
            }
        }
    }
    printf("%d\n",cnt+1);
    return 0;
}