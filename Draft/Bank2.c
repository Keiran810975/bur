#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 200
typedef struct{
    int number[MAX];//队列中顾客的序号
    int serve[MAX];//顾客的服务类型，值为1，2，3，对应时间为1，2，3
    int time[MAX];//队列中顾客的等待时间
    int front;
    int rear;
}queue;
//初始化队列
void init(queue *p){
    p->front=0;
    p->rear=0;
}
//判断队空
int isempty(queue *p){
    return p->front==p->rear;
}
//元素入队
void push(queue *p,int a,int b){
    p->rear=(p->rear+1)%MAX;
    p->number[p->rear]=a;
    p->serve[p->rear]=b;
    p->time[p->rear]=0;
}
//元素出队
int pop(queue *p){
    if(isempty(p)){
        printf("出队失败\n");
        return -1;
    }
    int val=p->serve[p->front+1];
    p->front=(p->front+1)%MAX;
    return val;
}
//获取队列中人数
int getNum(queue *q){
    return q->rear-q->front;
}
void swap(int *a,int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
int windows=3;//记录现在开的窗口数
int priQ[1000];//堆(小根堆)
int len;//记录堆的长度(就是现在正在接受服务的人的个数)
void put(int x){//把数加在最后,长度+1，利用堆的父子节点关系,一次次与父亲比较，如果比父亲小就交换，继续比较，直到比父亲大或到了根节点为止
    int f;
    len++;
    priQ[len]=x;
    int b=len;
    while(b!=1&&priQ[b]<priQ[b/2]){
        //swap(&priQ[b],&priQ[b/2]);
        int tmp=priQ[b];
        priQ[b]=priQ[b/2];
        priQ[b/2]=tmp;
        b=b/2;
    }
}
int get(){//取出堆顶
//长度-1，把最后一个提到第一个。利用堆的父子节点关系，用换到第一个的数与儿子比较，
//如果比孩子大，就与两个儿子之间较小的一个交换，直到没有儿子或比儿子小为止
    int x=priQ[1];
    priQ[1]=priQ[len];
    len--;
    int f=1,c;
    while(2*f<=len){
        if(2*f+1>len||priQ[2*f]<priQ[2*f+1])c=2*f;
        else c=2*f+1;
        if(priQ[f]>priQ[c]){
        //swap(&priQ[f],&priQ[c]);
        int tmp=priQ[f];
        priQ[f]=priQ[c];
        priQ[c]=tmp;
        f=c;
    }else return x;
    }
    return x;
}
int main(){
    queue *fff=(queue *)malloc(sizeof(queue));//存等待客户的队列
    init(fff);
    int n;scanf("%d",&n);
    int numCus[200];//每轮来的顾客人数
    for(int i=0;i<n;i++)scanf("%d",&numCus[i]);
    int cnt=1;
    int sum;
    for(int i=0;i<n;i++){
        int s[200];//每个顾客的服务类型
        for(int j=0;j<numCus[i];j++){
            scanf("%d",&s[j]);
            push(fff,cnt++,s[j]);//顾客入队
        }
        //现在要判断开几个窗口
        sum=getNum(fff);
        //printf("$%d$ ",sum);
        if(windows==3&&sum/3>=7)windows++;
        if(windows==4&&sum/4>=7)windows++;
        //printf("$%d$%d$ ",len,windows);
        while(len<windows&&(!isempty(fff))){
            printf("%d : %d\n",fff->number[fff->front+1],fff->time[fff->front+1]);
            int x=pop(fff);
            put(x);//排队的顾客接受服务
        }
        //printf("$%d$ ",len);
        sum=getNum(fff);
        //printf("*%d*",sum);
        while(sum/windows<7&&windows>3)windows--;
        //for(int j=1;j<=len;j++)printf("&%d& ",priQ[j]);
        for(int j=1;j<=len;j++){
            priQ[j]--;
        }
        if(priQ[1]==0&&len>0)get();
        if(priQ[1]==0&&len>0)get();
        if(priQ[1]==0&&len>0)get();
        if(priQ[1]==0&&len>0)get();
        if(priQ[1]==0&&len>0)get();
        //服务完毕，出去
        //for(int j=1;j<=len;j++)printf("#%d# ",priQ[j]);
        for(int j=0;j<MAX;j++)fff->time[j]+=1;
    }
    //printf("\n______________\n");
    //printf("^^^^%d  %d\n",getNum(fff),windows);
    while(!isempty(fff)){
        sum=getNum(fff);
        //printf("$%d$ ",sum);
        //printf("$%d$%d$ ",len,windows);
        while(len<windows&&(!isempty(fff))){
            printf("%d : %d\n",fff->number[fff->front+1],fff->time[fff->front+1]);
            int x=pop(fff);
            put(x);//排队的顾客接受服务
        }
        //printf("$%d$ ",len);
        sum=getNum(fff);
        //printf("*%d*",sum);
        while(sum/windows<7&&windows>3)windows--;
        //for(int j=1;j<=len;j++)printf("&%d& ",priQ[j]);
        for(int j=1;j<=len;j++){
            priQ[j]--;
        }
        if(priQ[1]==0&&len>0)get();
        if(priQ[1]==0&&len>0)get();
        if(priQ[1]==0&&len>0)get();
        if(priQ[1]==0&&len>0)get();
        if(priQ[1]==0&&len>0)get();
        //服务完毕，出去
        //for(int j=1;j<=len;j++)printf("#%d# ",priQ[j]);
        for(int j=0;j<MAX;j++)fff->time[j]+=1;
    }
    return 0;
}