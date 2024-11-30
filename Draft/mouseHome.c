#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1100
typedef struct{
    int dire[MAX];
    int step[MAX];
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
    int val=p->dire[p->top];
    p->top--;
    return val;
}
//插入栈元素
void push(stack *p,int new,int nn){
    if(isfull(p)){
        printf("插入元素失败\n");
        return;
    }
    p->top+=1;
    p->dire[p->top]=new; 
    p->step[p->top]=nn;
}
int gettop(stack *p){
    if(isempty(p)){
        printf("获取失败\n");
        return 0;
    }
    return p->dire[p->top];
}
int g2(stack *p){
    if(isempty(p)){
        printf("获取失败\n");
        return 0;
    }
    return p->step[p->top];
}
int opposite(int x,int y){
    if((x==1&&y==2)||(x==2&&y==1)||(x==3&&y==4)||(x==4&&y==3))return 1;
    return 0;
}
int turn(int a){
    if(a==1)return 2;
    if(a==2)return 1;
    if(a==3)return 4;
    if(a==4)return 3;
}
typedef struct way{
    int d;
    int s;
}way;
int main(){
    stack *p=(stack *)malloc(sizeof(stack));
    int a,b;
    while(1){
        scanf("%d-%d",&a,&b);
        if(a==0&&b==0)break;
        if(isempty(p))push(p,a,b);
        //如果方向相反
        else if(opposite(gettop(p),a)){
            p->step[p->top]-=b;
            if(p->step[p->top]==0)pop(p);
            else if(p->step[p->top]<0){
                p->dire[p->top]=turn(p->dire[p->top]);
                p->step[p->top]=-(p->step[p->top]);
            }
        }else{
            push(p,a,b);
        }
    }
    for(int i=p->top;i>0;i--)printf("%d-%d ",p->dire[i],p->step[i]);printf("\n");
    int j=0;
    way ff[1100];
    for(int i=p->top;i>0;i--){
        //printf("%d\n",p->dire[i]);
        int t1,t2;
        t1=turn(p->dire[i]);
        t2=p->step[i];
        if(j==0){
            ff[j].d=t1;
            ff[j].s=t2;
            j++;
        }else if(j>0&&ff[j-1].d==t1){
            ff[j-1].s+=t2;
        }else if(j>0&&ff[j-1].d!=t1){
            ff[j].d=t1;
            ff[j++].s=t2;
        }
    }
    //printf("%d\n",j);
    for(int i=0;i<j;i++){
        printf("%d-%d ",ff[i].d,ff[i].s);
    }
    return 0;
}