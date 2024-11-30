#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 7
typedef struct{
    int data[MAX];
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
void push(queue *p,int new){
    if(isfull(p)){
        printf("入队失败\n");
        return;
    }
    p->rear=(p->rear+1)%MAX;
    p->data[p->rear]=new;
}
//元素出队
int pop(queue *p){
    if(isempty(p)){
        printf("出队失败\n");
        return -1;
    }
    int val=p->data[p->front+1];
    p->front=(p->front+1)%MAX;
    return val;
}
//获取队头元素
int getfront(queue *p){
    if(isempty(p)){
        printf("获取失败\n");
        return -1;
    }
    return p->data[p->front+1];
}
//获取队尾元素
int getrear(queue *p){
    if(isempty(p)){
        printf("获取失败\n");
        return -1;
    }
    return p->data[p->rear];
}
//提取队中元素
int get(queue *p,int n){
    if(isempty(p)){
        printf("获取失败\n");
        return -1;
    }
    return p->data[n];
}
int main(){
    queue sss;
    init(&sss);
    push(&sss,7);
    push(&sss,6);
    push(&sss,5);
    push(&sss,810);
    push(&sss,3);
    push(&sss,114);
    int a=pop(&sss);
    int b=pop(&sss);
    push(&sss,99);
    int c=getfront(&sss);
    int d=getrear(&sss);
    int e=get(&sss,4);
    printf("%d %d %d %d %d",a,b,c,d,e);
    return 0;
}