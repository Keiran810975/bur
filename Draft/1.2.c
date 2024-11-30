#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1000
char a[1000];
char reverse[1000],temp[1000];
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
    return p->top==MAX-1;
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
int gettop(stack *p){
    if(isempty(p)){
        printf("获取失败\n");
        return 0;
    }
    return p->data[p->top];
}
int num(char c){
    if(c=='+'||c=='-')return 1;
    if(c=='*'||c=='/')return 2;
}
int issign(char c){
    if(c=='+'||c=='-'||c=='/'||c=='*')return 1;
    return 0;
}
int main(){
    gets(a);
    int len=strlen(a);
    int j=0;
    for(int i=0;i<len;i++){
        if(a[i]!=' '){
            temp[j]=a[i];j++;
        }
    }
    stack *sss;
    init(sss);
    int ll=strlen(temp);
    int k=0;
    for(int i=0;i<ll;i++){
        if(temp[i]>='0'&&temp[i]<='9'){
            reverse[k]=temp[i];k++;
        }
        else{
            if(isempty(sss)){
                push(sss,temp[i]);
            }
            else if(num(temp[i])>sss->data[sss->top]){
                push(sss,temp[i]);
            }
            else{
                while(issign(sss->data[sss->top])&&(num(temp[i])<=num(sss->data[sss->top]))){
                        reverse[k]=pop(sss);k++;
                }
                push(sss,temp[i]);
            }
        }
    }
    printf("%s",reverse);
    return 0;
}