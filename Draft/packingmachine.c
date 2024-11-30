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
stack init(stack *p){     //当栈空的时候 初始化栈顶指针为-1
    p->top=-1;
}
//判断栈是否为空
int isempty(stack *p){
    return p->top==-1;  //******
}
//判断栈是否满
int isfull(stack *p){
    return p->top==Smax-1;
}
//弹出栈元素(pop)
char pop(stack *p){
    if(isempty(p)){
        printf("栈为空\n");
        return 0;
    }
    char val=p->data[p->top];
    p->top--;
    return val;
}
//插入栈元素
void push(stack *p,char new){
    if(isfull(p)){
        printf("插入元素失败\n");
        return;
    }
    p->top+=1;
    p->data[p->top]=new; 
}
//获取栈顶元素的值
char gettop(stack *p){
    if(isempty(p)){
        printf("获取失败\n");
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