#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int graph[200][200];
int vis[200];
int x,y;
int cnt;
int que[200];
int head=1,tail=1;
void reset(){
    for(int i=0;i<200;i++){
        vis[i]=0;
        que[i]=0;
        }
    cnt=0;
    int que[200];
    head=1,tail=1;
}
void dfs(int cur){
    printf("%d ",cur);
    cnt++;
    if(cnt==x)return;
    for(int i=1;i<=x;i++){
        if(graph[cur][i]==1&&vis[i]==0){
            vis[i]=1;
            dfs(i);
        }
    }
    return;
}
void bfs(int cur){

}
int main(){
    scanf("%d%d",&x,&y);
    for(int i=0;i<y;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    dfs(0);
    printf("\n");
    reset();
    int cur=0;
    que[tail++]=0;
    vis[0]=1;
    while(head<tail){
        cur=que[head];
        for(int i=0;i<x;i++){
            if(graph[cur][i]==1&&vis[i]==0){
                que[tail++]=i;
                vis[i]=1;
            }
            if(tail>x)break;
        }
        head++;
    }
    for(int i=1;i<tail;i++)printf("%d ",que[i]);
    printf("\n");
    int del;scanf("%d",&del);
    for(int i=0;i<y;i++){
        graph[del][i]=0;
        graph[i][del]=0;
    }
    reset();
    dfs(0);
    printf("\n");
    reset();
    cur=0;
    que[tail++]=0;
    vis[0]=1;
    while(head<tail){
        cur=que[head];
        for(int i=0;i<x;i++){
            if(graph[cur][i]==1&&vis[i]==0){
                que[tail++]=i;
                vis[i]=1;
            }
            if(tail>x)break;
        }
        head++;
    }
    for(int i=1;i<tail;i++)printf("%d ",que[i]);
    printf("\n");
    return 0;
}