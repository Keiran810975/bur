#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
    char data[MAX][50];
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
char *pop(stack *p){
    p->top--;
    return p->data[p->top];
}
//����ջԪ��
void push(stack *p,char *new){
    if(isfull(p)){
        printf("����Ԫ��ʧ��\n");
        return;
    }
    p->top+=1;
    strcpy(p->data[p->top],new); 
}
//��ȡջ��Ԫ�ص�ֵ
char *gettop(stack *p){
    // if(isempty(p)){
    //     printf("��ȡʧ��\n");
    //     return 0;
    // }
    return p->data[p->top];
}
typedef struct func{
    char name[50];
    char call[250][50];
    int numCall;
}func;
func ans[300];
int j=0;
void save(char *s){
    int sig=0;
    for(int i=0;i<j;i++){
        if(strcmp(ans[i].name,s)==0){
            sig=1;
            break;
        }
    }
    if(sig==0){
        ans[j].numCall=0;
        strcpy(ans[j++].name,s);
    }
}
void called(char *host,char *son){
    for(int i=0;i<j;i++){
        if(strcmp(ans[i].name,host)==0){
            int sig=0;
            for(int k=0;k<ans[i].numCall;k++){
                if(strcmp(ans[i].call[k],son)==0){
                    sig=1;
                    break;
                }
            }
            if(sig==0)strcpy(ans[i].call[ans[i].numCall++],son);
        }
    }
}
int main(){
    stack *p=(stack*)malloc(sizeof(stack));
    init(p);
    int op;
    while(1){
        scanf("%d",&op);
        if(op==0){
            pop(p);
            if(isempty(p))break;
        }
        else if(op==8){
            char s[50];
            scanf("%s",s);
            if(isempty(p)){
                push(p,s);
                save(s);
            }
            else{
                called(gettop(p),s);
                save(s);
                push(p,s);
            }
        }
    }
    for(int i=0;i<j;i++){
        if(ans[i].numCall>0){
            printf("%s:",ans[i].name);
        for(int k=0;k<ans[i].numCall-1;k++){
            printf("%s,",ans[i].call[k]);
        }
        printf("%s\n",ans[i].call[ans[i].numCall-1]);
        }
    }
    return 0;
}