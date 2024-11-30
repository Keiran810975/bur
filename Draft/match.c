#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1000
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
char gettop(stack *p){
    if(isempty(p)){
        printf("获取失败\n");
        return 0;
    }
    return p->data[p->top];
}
FILE *op,*ou;
void f(char c){
    char d;
    if(c=='/'){
        if((d=getc(op))=='*'){
            char a,b;
            a=getc(op);
            b=getc(op);
            while(a!='*'||b!='/'){
                a=b;
                b=getc(op);
            }
        }else if(d=='/'){
            char a;
            a=getc(op);
            while(a!='\n'){
                a=getc(op);
            }
            putc('\n',ou);
        }else{
            putc(c,ou);
            putc(d,ou);
        }
    }else{
        putc(c,ou);
    }
}
void DComment(){//删除c文件中的注释
    op=fopen("example.c","r");
    ou=fopen("fileout.txt","w");
    char line[1000];
    char c;
    while((c=getc(op))!=EOF){
        f(c);
    }
    fclose(op);
    fclose(ou);
}
int numL=1;
//左括号1，右括号2，大括号左3右4
char b[1000];
int line[1000];
int numB=-1;
int sig=0;
void thatS(){
    op=fopen("fileout.txt","r");
    stack *q=(stack *)malloc(sizeof(stack));
    init(q);
    while(1){
        char t=fgetc(op);
        if(t==EOF)break;
        if(t=='\n')numL++;
        else if(t=='"'){
            while(1){
                t=fgetc(op);
                if(t=='\\')t=fgetc(op);
                else if(t=='"')break;
            }
        }else if(t=='\''){
            while(1){
                t=fgetc(op);
                if(t=='\\')t=fgetc(op);
                else if(t=='\'')break;
            }
        }else if(t=='('){
            push(q,1);
            b[++numB]=t;
            line[q->top]=numL;
        }else if(t=='{'){
            push(q,3);
            b[++numB]=t;
            line[q->top]=numL;
        }else if(t==')'){
            b[++numB]=t;
            line[q->top]=numL;
            //printf("%d\n",line[q->top-1]);
            if(isempty(q)){
                printf("without maching '%c' at line %d\n",t,numL);
                sig=1;
            }else{
                if(gettop(q)==1)pop(q);
                else{
                    printf("without maching '%c' at line %d\n",t,numL);
                    sig=1;
                }
            }
        }else if(t=='}'){
            b[++numB]=t;
            int l=line[q->top];
            line[q->top]=numL;
            //printf("%d\n",line[q->top-1]);
            if(isempty(q)){
                printf("without maching '%c' at line %d\n",t,numL);
                sig=1;
            }else{
                if(gettop(q)==1){
                    printf("without maching '%c' at line %d\n",'(',l);
                    sig=1;
                }
                else if(gettop(q)==3)pop(q);
                else{
                    printf("without maching '%c' at line %d\n",t,numL);
                    sig=1;
                }
            }
        }
    }
    if(q->top==0){
        char bbb;
        if(gettop(q)==1)bbb='(';
        else if(gettop(q)==3)bbb='{';
        printf("without maching '%c' at line %d\n",bbb,line[q->top]);
        sig=1;
    }
    if(sig==0){
        printf("%s\n",b);
    }
}
int main(){
    DComment();
    thatS();
    return 0;
}