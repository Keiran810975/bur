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
//��ʼ������
void init(queue *p){
    p->front=0;
    p->rear=0;
}
//�ж϶ӿ�
int isempty(queue *p){
    return p->front==p->rear;
}
//�ж϶���
int isfull(queue *p){
    return (p->rear+1)%MAX==(p->front);
}
//Ԫ�����
void push(queue *p,int new){
    if(isfull(p)){
        printf("���ʧ��\n");
        return;
    }
    p->rear=(p->rear+1)%MAX;
    p->data[p->rear]=new;
}
//Ԫ�س���
int pop(queue *p){
    if(isempty(p)){
        printf("����ʧ��\n");
        return -1;
    }
    int val=p->data[p->front+1];
    p->front=(p->front+1)%MAX;
    return val;
}
//��ȡ��ͷԪ��
int getfront(queue *p){
    if(isempty(p)){
        printf("��ȡʧ��\n");
        return -1;
    }
    return p->data[p->front+1];
}
//��ȡ��βԪ��
int getrear(queue *p){
    if(isempty(p)){
        printf("��ȡʧ��\n");
        return -1;
    }
    return p->data[p->rear];
}
//��ȡ����Ԫ��
int get(queue *p,int n){
    if(isempty(p)){
        printf("��ȡʧ��\n");
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