#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 150
int Smax;
typedef struct{
    char data[MAX];
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
    return p->top==Smax-1;
}
//����ջԪ��(pop)
char pop(stack *p){
    if(isempty(p)){
        printf("ջΪ��\n");
        return 0;
    }
    char val=p->data[p->top];
    p->top--;
    return val;
}
//����ջԪ��
void push(stack *p,char new){
    if(isfull(p)){
        printf("����Ԫ��ʧ��\n");
        return;
    }
    p->top+=1;
    p->data[p->top]=new; 
}
//��ȡջ��Ԫ�ص�ֵ
char gettop(stack *p){
    if(isempty(p)){
        printf("��ȡʧ��\n");
        return 0;
    }
    return p->data[p->top];
}
int main(){
    char road[2000]={'\0'};
    int k=0;
    int n,m;
    scanf("%d%d%d",&n,&m,&Smax);
    stack *machines[150];
    for(int i=1;i<=n;i++){
        machines[i]=(stack*)malloc(sizeof(stack));
        init(machines[i]);
        for(int j=0;j<m;j++){
            char c;
            scanf("%c",&c);
            push(machines[i],c);
        }
        getchar();
    }
    stack *bucket=(stack*)malloc(sizeof(stack));
    init(bucket);
    int op;
    while(scanf("%d",&op)!=EOF){
        if(op==-1)break;
        if(op==0){
            if(!isempty(bucket)){
                char a=pop(bucket);
                road[k++]=a;
            }
        }
        else{
            char a=pop(machines[op]);
            if(isfull(bucket))road[k++]=a;
            else push(bucket,a);
        }
    }
    printf("%s\n",road);
    return 0;
}