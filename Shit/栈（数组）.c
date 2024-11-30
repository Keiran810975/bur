#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
    int data[MAX];
    int top;
}stack;
stack init(stack *p){     //��ջ�յ�ʱ�� ��ʼ��ջ��ָ��Ϊ-1
    p->top=-1;
}
//�ж�ջ�Ƿ�Ϊ��
int isempty(stack *p){
    return p->top==-1;  //******
}
//�ж�ջ�Ƿ���
int isfull(stack *p){
    return p->top==MAX-1;
}
//����ջԪ��(pop)
int pop(stack *p){
    if(isempty(p)){
        printf("ջΪ��\n");
        return 0;
    }
    int val=p->data[p->top];
    p->top--;
    return val;
}
//����ջԪ��
void push(stack *p,int new){
    if(isfull(p)){
        printf("����Ԫ��ʧ��\n");
        return;
    }
    p->top+=1;
    p->data[p->top]=new; 
}
//��ȡջ��Ԫ�ص�ֵ
int gettop(stack *p){
    if(isempty(p)){
        printf("��ȡʧ��\n");
        return 0;
    }
    return p->data[p->top];
}
int main(){
    stack sss;//����һ��ջ
    init(&sss);
    push(&sss,3);
    push(&sss,5);
    push(&sss,514);
    push(&sss,810);
    push(&sss,114);
    printf("%d\n",isfull(&sss));
    printf("%d\n",gettop(&sss));
    int val=pop(&sss);
    printf("%d\n%d\n",val,gettop(&sss));
    return 0;
}