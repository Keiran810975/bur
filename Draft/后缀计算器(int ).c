#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1000
char a[1000];
char temp[1000];
int tt[1000];int reverse[1000];
typedef struct{
    int data[MAX];
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
    return p->top==MAX-1;
}
//弹出栈元素(pop)
int pop(stack *p){
    if(isempty(p)){
        printf("栈为空\n");
        return 0;
    }
    int val=p->data[p->top];
    (p->top)-=1;
    return val;
}
//插入栈元素
void push(stack *p,int new){
    if(isfull(p)){
        printf("插入元素失败\n");
        return;
    }
    p->top+=1;
    p->data[p->top]=new; 
}
//获取栈顶元素的值
int gettop(stack *p){
    if(isempty(p)){
        printf("获取失败\n");
        return 0;
    }
    return p->data[p->top];
}
int num(int c){
    if(c==-1||c==-2)return 1;
    if(c==-3||c==-4)return 2;
}
int issign(int c){
    if(c==-1||c==-2||c==-3||c==-4)return 1;
    if(c==-5||c==-6)return 2;
    return 0;
}
int main(){
    gets(a);
    int len=strlen(a);
    int j=0;
    for(int i=0;i<len;i++){
        if(a[i]!=' '&&a[i]!='='){
            temp[j]=a[i];j++;
        }
    }
    j=0;
    for(int i=0;i<len;i++){
        if(temp[i]=='+'){tt[j]=-1;j++;}
        if(temp[i]=='-'){tt[j]=-2;j++;}
        if(temp[i]=='*'){tt[j]=-3;j++;}
        if(temp[i]=='/'){tt[j]=-4;j++;}
        if(temp[i]=='('){tt[j]=-5;j++;}
        if(temp[i]==')'){tt[j]=-6;j++;}
        if(temp[i]>='0'&&temp[i]<='9'){
            int x=temp[i]-'0';
            while(temp[i+1]>='0'&&temp[i+1]<='9'){
                x=10*x+temp[i+1]-'0';
                i++;
            }
            tt[j]=x;
            j++;
        }
    }
    //for(int i=0;i<j;i++)printf("%d ",tt[i]);printf("\n");
    stack *sss=(stack*)malloc(sizeof(stack));
    init(sss);
    int ll=strlen(temp);
    int k=0;
    int sig=0;//记录栈内是否有左括号（个数）
    for(int i=0;i<j;i++){
        //printf("%d\n",sig);
        if(!issign(tt[i])){//数字直接输出
            reverse[k]=tt[i];k++;
        }else if(tt[i]==-5){//左括号都入栈
            push(sss,tt[i]);
            sig++;
        }else if(tt[i]==-6){//如果有右括号,不断出栈，直到遇到左括号
            while(1){
                int x=pop(sss);
                if(x!=-5){
                    reverse[k]=x;k++;
                }else{
                    sig--;
                    break;
                }
            }
        }
        else{
            if(isempty(sss)){//栈空运算符直接入栈
                push(sss,tt[i]);
            }else if(tt[i]==-3||tt[i]==-4){
                while(sss->data[sss->top]!=-1&&sss->data[sss->top]!=-2&&sss->data[sss->top]!=-5&&(!isempty(sss))){
                    int x=pop(sss);
                    reverse[k++]=x;
                }
                push(sss,tt[i]);
            }else if(tt[i]==-1||tt[i]==-2){
                while(sss->data[sss->top]!=-5&&(!isempty(sss))){
                    int x=pop(sss);
                    reverse[k++]=x;
                }
                push(sss,tt[i]);
            }
        }
    }
    while(!isempty(sss)){
        reverse[k]=pop(sss);k++;
    }
    for(int i=0;i<=k;i++)printf("%d ",reverse[i]);printf("\n");
    stack *fff=(stack*)malloc(sizeof(stack));
    init(fff);
    for(int i=0;i<k;i++){
        if(!issign(reverse[i])){
            push(fff,reverse[i]);
        }
        else{
            int c=pop(fff);
            int d=pop(fff);
            //printf("$%d %d$ ",c,d);
            int e;
            if(reverse[i]==-1)e=c+d;
            else if(reverse[i]==-2)e=d-c;
            else if(reverse[i]==-4){
                if(c==0)e=0;
                else e=d/c;
            }
            else if(reverse[i]==-3)e=c*d;
            push(fff,e);
        }
        //printf("%d ",gettop(fff));
    }
    //printf("1\n");
    int final=pop(fff);
    printf("%d\n",final);
    return 0;
}   