#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define infinty 1e7
int graph[100][100];//邻接矩阵
int vis[100];
int dis[100];
int numEdge[100][100];//存储边的编号
void initg(){//初始化邻接矩阵
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            graph[i][j]=infinty;
        }
    }
    for(int i=0;i<100;i++)graph[i][i]=0;
    for(int i=0;i<100;i++)dis[i]=infinty;
}
void prim(int n,int s){
    dis[s]=0;
    for(int i=0;i<n-1;i++){
        int min=infinty;
        int u=-1,v=-1;
        for(int j=0;j<n;j++){
            if(vis[j]==0&&dis[j]<min){
                min=dis[j];
                u=j;
            }
        }
        for(int k=0;k<n;k++){
            if(vis[k]==0&&graph[u][k]!=0&&graph[u][k]<dis[k]){
                dis[k]=graph[u][k];
                v=k;
            }
        }
        if(v!=-1){
            vis[v]=1;
            printf("Edge (%d, %d) added to MST with weight %d\n", u + 1, v + 1, graph[u][v]);
        }
    }
}
int main(){
    initg();
    int n,e;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){
        int a,x,y,w;
        scanf("%d%d%d%d",&a,&x,&y,&w);
        numEdge[x][y]=a;
        graph[x][y]=w;
        graph[y][x]=w;
    }
    prim(n,0);
    return 0;
}