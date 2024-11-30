#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100
typedef struct destination{
    char name[50];
    int distance;
}destination;

typedef struct carrige{
    char num[50];
    char des[50];
    int dis;
}carrige;
//��ṹ���ջ
typedef struct{
    carrige car[MAX];//����
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
carrige pop(stack *p){
    carrige val=p->car[p->top];
    p->top--;
    return val;
}
//����ջԪ��
void push(stack *p,carrige new){
    if(isfull(p)){
        printf("����Ԫ��ʧ��\n");
        return;
    }
    p->top+=1;
    p->car[p->top]=new; 
}
//��ȡջ��Ԫ�ص�ֵ
carrige gettop(stack *p){
    return p->car[p->top];
}
int pc=0;
carrige ff[100];
int main(){
    stack *a,*b,*c;
    a=(stack *)malloc(sizeof(stack));
    b=(stack *)malloc(sizeof(stack));
    c=(stack *)malloc(sizeof(stack));
    init(a);init(b);init(c);
    //printf("%d",b->top);
    int n;scanf("%d",&n);
    destination list[100];
    for(int i=0;i<n;i++){
        scanf("%s%d",list[i].name,&list[i].distance);
    }
    int m;scanf("%d",&m);
    //printf("%d\n",m);
    for(int i=0;i<m;i++){
        //printf("$");
        char s[100],c[100];
        scanf("%s%s",ff[i].num,s);
        for(int j=0;j<n;j++){
            if(strcmp(s,list[j].name)==0){
                ff[i].dis=list[j].distance;
                //printf("$");
                break;
            }
        }
        //printf("%d$",ff[i]->dis);
    }
    // for(int i=0;i<m;i++){
    //     printf("%d ",ff[i].dis);
    // }
    //printf("$$$");
    for(int i=m-1;i>=0;i--){
        //printf("#");
        push(b,ff[i]);
    }
    //printf("\n*%d*\n",b->top);
    for(int i=0;i<m;i++){
        int cnt=0;
        int max=0;
        int index=0;
        for(int j=b->top;j>=0;j--){
            if((b->car[j]).dis>max){
                index=j;
                max=b->car[j].dis;
            }
        }
        //printf("\n^%d^\n",index);
        int shit=b->top-index;
        for(int k=0;k<shit+1;k++){
            carrige x=pop(b);
            //printf("&");
            push(a,x);
            pc++;
        }
        //����c
        if(shit>0){
            carrige x=pop(a);
            push(c,x);
            for(int k=0;k<shit;k++){
                carrige y=pop(a);
                push(b,y);
            }
            carrige z=pop(c);
            push(a,z);
            pc++;
        }
    }
    for(int i=0;i<=a->top;i++){
        printf("%s ",a->car[i].num);
    }
    printf("\n");
    printf("%d\n",pc);
    return 0;
}