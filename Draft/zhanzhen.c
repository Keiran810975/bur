#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100
typedef struct func{
    char name[30];
    int zhen;
}func;
typedef struct{
    func data[MAX];
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
func pop(stack *p){
    // if(isempty(p)){
    //     printf("ջΪ��\n");
    //     return ;
    // }
    func val=p->data[p->top];
    p->top--;
    return val;
}
//����ջԪ��
void push(stack *p,func new){
    if(isfull(p)){
        printf("����Ԫ��ʧ��\n");
        return;
    }
    p->top+=1;
    p->data[p->top]=new; 
}
//��ȡջ��Ԫ�ص�ֵ
func gettop(stack *p){
    // if(isempty(p)){
    //     printf("��ȡʧ��\n");
    //     return 0;
    // }
    return p->data[p->top];
}
func ff[30];
int maxF,maxZ;
func ans1[100];
func ans2[100];
int j,k;
void remember1(stack *p){
    j=0;
    for(int i=0;i<maxF;i++){
        ans1[j++]=p->data[i];
    }
}
void remember2(stack *p){
    k=0;
    int t=p->top;
    for(int i=0;i<=t;i++){
        ans2[k++]=p->data[i];
    }
}
int cal(stack *p){
    int sum=0;
    for(int i=0;i<p->top+1;i++){
        sum+=p->data[i].zhen;
    }
    return sum;
}
int main(){
    stack *p=(stack *)malloc(sizeof(stack));
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s%d",ff[i].name,&ff[i].zhen);
        if(strcmp(ff[i].name,"main")==0){
            push(p,ff[i]);
        }
    }
    char s[100];gets(s);
    char op[10];
    while(scanf("%s",op)!=EOF){
        if(strcmp(op,"call")==0){
            char new[30];
            scanf("%s",new);
            for(int i=0;i<n;i++){
                if(strcmp(ff[i].name,new)==0){
                    push(p,ff[i]);
                    break;
                }
            }
            if(p->top+1>=maxF){
                maxF=p->top+1;
                remember1(p);
            }
        }
    }
    return 0;
}