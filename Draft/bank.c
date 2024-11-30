#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 200
int window=3;//目前提供服务的窗口数
typedef struct{
    int id[MAX];//序号
    int waitime[MAX];//等待时间
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
//判断队满
int isfull(queue *p){
    return (p->rear+1)%MAX==(p->front);
}
//元素入队
void push(queue *p,int new,int new2){
    if(isfull(p)){
        printf("入队失败\n");
        return;
    }
    p->rear=(p->rear+1)%MAX;
    p->id[p->rear]=new;
    p->waitime[p->rear]=new2;
}
//元素出队
int pop(queue *p){
    if(isempty(p)){
        printf("出队失败\n");
        return -1;
    }
    int val=p->id[p->front+1];
    p->front=(p->front+1)%MAX;
    return val;
}
//获取队头元素
int getfront(queue *p){
    if(isempty(p)){
        printf("获取失败\n");
        return -1;
    }
    return p->id[p->front+1];
}
//获取队尾元素
int getrear(queue *p){
    if(isempty(p)){
        printf("获取失败\n");
        return -1;
    }
    return p->id[p->rear];
}
//提取队中元素
int get(queue *p,int n){
    if(isempty(p)){
        printf("获取失败\n");
        return -1;
    }
    return p->id[n];
}
int sum(queue *p){
    int x=(p->rear-p->front+MAX)%MAX;
    return x;
}
queue *fff;
void arrive(){
    int n;
    static int count=1;
    fff=(queue *)malloc(sizeof(queue));
    init(fff);
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n;i++){
        a=count++;
        b=0;
        push(fff,a,b);
    }
    while((sum(fff)/window)>=7&&window<=5)window++;
}
int service(){
    for(int i=0;i<window;i++){
        if(isempty(fff))return 0;
        else{
            int b=fff->id[fff->front+1];
            int a=pop(fff);
            printf("%d : %d",a,b);
        }
        if((sum(fff)/window)>=7&&window>3)window--;//where?
    }
    return 1;
}
int main(){
    int clock,sim;
    scanf("%d",&sim);
    for(clock=1;;clock++){
        if(!isempty(fff)){
            for(int i=0;i>MAX;i++){
                fff->waitime[i]+=1;
            }
        }
        if(clock<=sim)arrive();
        if(service()==0&&clock>sim)break;
    }
    return 0;
}