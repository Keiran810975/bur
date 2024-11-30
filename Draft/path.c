#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct edge{
    int numE;
    int adjvex;//邻接顶点
    struct edge *next;
}elink;
typedef struct vertex{
    struct edge *link;
}vlink;
int x,y;//顶点数，边数
elink *insertEdge(elink *head,int edge,int v){
    elink *e=(elink *)malloc(sizeof(elink));
    e->numE=edge;
    e->adjvex=v;
    e->next=NULL;
    if(head==NULL){
        head=e;
        return head;
    }
    elink *p=head;
    while(p->next!=NULL)p=p->next;
    p->next=e;
    return head;
}
vlink g[2000];
int vis[2000];
int path[2000];//路径号
void dfs(vlink g[],int v,int l){
    if(v==x-1){
        for(int i=0;i<l;i++)printf("%d ",path[i]);
        printf("\n");
        return;
    }
    for(elink *p=g[v].link;p!=NULL;p=p->next){
        if(vis[p->adjvex]==0){
            path[l]=p->numE;
            vis[v]=1;
            dfs(g,p->adjvex,l+1);
            vis[v]=0;
        }
    }
    return;
}
int main(){
    scanf("%d%d",&x,&y);
    for(int i=0;i<y;i++){//构建邻接表
        int e,v1,v2;
        scanf("%d%d%d",&e,&v1,&v2);
        g[v1].link=insertEdge(g[v1].link,e,v2);
        g[v2].link=insertEdge(g[v2].link,e,v1);
    }
    vis[0]=1;
    dfs(g,0,0);
    return 0;
}