#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct{
    person idy[300];
    int front;
    int rear;
}queue;
//初始化队列
void init(queue *p){
    p->front=100;
    p->rear=100;
}
typedef struct person{
    int x;
    int y;
    int z;
    int t;
}person;
person ff[150];
void swapStruct(person *x,person *y){
    person temp=*x;
    *x=*y;
    *y=temp;
}
void bubbleSort(person a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j].x>a[j+1].x){
                swapStruct(&a[j],&a[j+1]);
            }
        }
    }
}
void buff(queue *q){
    for(int i=q->front;i<=q->rear;i++){
        q->idy[i].t++;
    }
}
//元素入队
void push(queue *p,person new){
    p->rear=(p->rear+1);
    p->idy[p->rear]=new;
}
//元素出队
person pop(queue *p){
    person val=p->idy[p->front+1];
    p->front=(p->front+1);
    return val;
}
int isempty(queue *p){
    return p->front==p->rear;
}
int lengthQ;
int cntTime;
int ans[300];
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&ff[i].x,&ff[i].y,&ff[i].z);
        ff[i].t=0;
    }
    bubbleSort(ff,n);
    queue *q=(queue *)malloc(sizeof(queue));
    init(q);
    int maxT=ff[n-1].x;
    for(int i=0;i<n;i++){
        if(ff[i].z>lengthQ){
            q->front=(q->front)-1;
            q->idy[q->front]=ff[i];
            lengthQ++;
        }else{
            push(q,ff[i]);
            lengthQ++;
        }
        if(!isempty(q)){
            person aa=pop(q);
            ans[aa.y]=aa.x;
        }
    }
    return 0;
}