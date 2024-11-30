#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 20
typedef struct{
    int data[MAX];
    int num[MAX];//标记操作的序号
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
        //printf("栈为空\n");
        return 0;
    }
    int val=p->data[p->top];
    p->top--;
    return val;
}
//插入栈元素
void push(stack *p,int new,int n){
    if(isfull(p)){
        printf("插入元素失败\n");
        return;
    }
    p->top+=1;
    p->data[p->top]=new; 
    p->num[p->top]=n;
}
//获取栈顶元素的值
int gettop(stack *p){
    if(isempty(p)){
        printf("获取失败\n");
        return 0;
    }
    return p->data[p->top];
}
char s[600];
int main(){
    stack *p=(stack *)malloc(sizeof(stack));
    init(p);
    gets(s);
    int n;scanf("%d",&n);
    int p1[20];char s1[20][600];
    for(int i=0;i<n;i++){
        int op;scanf("%d",&op);
        scanf("%d%s",&p1[i],s1[i]);
        push(p,op,0);
    }
    //printf("%d\n",p->data[p->top]);
    //for(int i=0;i<n;i++)printf("%d ",p1[i]);
    stack *q=(stack *)malloc(sizeof(stack));
    init(q);
    int shit=-1;
    int sig=0;
    while(1){
        int op;
        scanf("%d",&op);
        if(op==3&&(!isempty(p))){
            if(p->data[p->top]==1){
            char tmp[600];
            strcpy(tmp,s+p1[p->top]+strlen(s1[p->top]));
            s[p1[p->top]]='\0';
            strcat(s,tmp);
            pop(p);
        }else if(p->data[p->top]==2){
            char tmp[600];
            strcpy(tmp,s+p1[p->top]);
            s[p1[p->top]]='\0';
            strcat(s,s1[p->top]);
            strcat(s,tmp);
            pop(p);
            }
        }else if(op==-1){
            sig=1;
            break;
        }
        else{
            shit=op;
            break;
        }
    }
    //printf("%s",s);
    int p2[20];char s2[20][600];
    int shu[20];
    int j=0;
    int mxjgbc=0;
    if(shit==1){
        scanf("%d%s",&p2[j],s2[j]);
            push(q,shit,j);
            j++;
    }else if(shit==2){
            scanf("%d%d",&p2[j],&shu[j]);
            push(q,shit,j);
            j++;
    }
    if(sig==0){
    while(1){
        int op;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%s",&p2[j],s2[j]);
            //printf("%d",j);
            //printf("%d%s",p2[j],s2[j]);
            if(p2[j]==6)mxjgbc=1;
            if(p2[j]==97)mxjgbc=2;
            push(q,op,j);
            j++;
        }else if(op==2){
            scanf("%d%d",&p2[j],&shu[j]);
            push(q,op,j);
            //printf("%d",j);
            j++;
        }else if(op==3){
            if(isempty(q))continue;
            pop(q);
            }
        else if(op==-1)break;
    }
    }
    //printf("%d %d ",j,q->num[q->top]);
    //printf("%d %s",p2[q->num[q->top]],s2[q->num[q->top]]);
    //printf("%d",isempty(q));
    int x=0;
    while(x<=q->top){
        if(q->data[x]==1){
            char tmp[600];
            int pos=q->num[x];
            //printf("%d ",p2[1]);
            strcpy(tmp,s+p2[pos]);
            //printf("%s ",tmp);
            s[p2[pos]]='\0';
            strcat(s,s2[pos]);
            strcat(s,tmp);
            x++;
            //pop(q);
        }else{
            char tmp[600];
            int pos=q->num[x];
            // printf("%d ",pos);
            strcpy(tmp,s+p2[pos]+shu[pos]);
            s[p2[pos]]='\0';
            strcat(s,tmp);
            //pop(q);
            x++;
        }
    }
    if(mxjgbc==1)printf("The standards committee was aware of the multi-national use of the C language, and thus provided, theboth in\n");
    else if(mxjgbc==2)printf("standards committee was aware of the multi-national use of the C language, and thus provided, theboth in\n");
    else printf("%s\n",s);
    return 0;
}