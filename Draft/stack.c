#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
typedef struct{
    int data[MAX];
    char s[MAX][500];
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
    p->top--;
    return val;
}
//插入栈元素
void push(stack *p,char s[]){
    if(isfull(p)){
        printf("插入元素失败\n");
        return;
    }
    p->top+=1;
    //p->data[p->top]=new; 
    strcpy(p->s[p->top],s);
}
//获取栈顶元素的值
char* gettop(stack *p){
    if(isempty(p)){
        printf("获取失败\n");
        return 0;
    }
    return p->s[p->top];
}
char sss[500][10000];
int mark[10000];
int main(){
    stack *p=(stack *)malloc(sizeof(stack));
    init(p);
    int op;
    int j=0;
    scanf("%d",&op);
    char f[500];scanf("%s",f);
    push(p,f);
    while(1){
        if(isempty(p))break;
        scanf("%d",&op);
        if(op==8){
            char func[500];
            scanf("%s",func);
            int sig=0,flag;
            for(int i=0;i<j;i++){
                if(strcmp(func,sss[i])==0){
                    flag=i;
                    sig=1;
                }
            }
            if(sig==0){
                strcpy(sss[j],func);
                strcat(sss[j],":");
                flag=j;
                j++;
            }
                char tmp[500];
                strcpy(tmp,gettop(p));
                for(int i=0;i<j;i++){
                    if(strcmp(tmp,sss[i])==0){
                        strcat(sss[i],func);
                        strcat(sss[i],",");
                        mark[i]=1;
                        }
                    }
                push(p,func);
        }else if(op==0){
            pop(p);
        }
    }
    for(int i=0;i<j;i++){
        if(mark[i]==1)printf("%s\n",sss[i]);
    }
    return 0;
}