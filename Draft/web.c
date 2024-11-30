#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 200
typedef struct{
    char data[100][MAX];//网页名
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
char *pop(stack *p){
    if(isempty(p)){
        printf("栈为空\n");
        return 0;
    }
    //strcpy(val,p->data[p->top]);
    p->top--;
    int l=p->top+1;
    return p->data[l];
}
//插入栈元素
void push(stack *p,char *new){
    if(isfull(p)){
        printf("插入元素失败\n");
        return;
    }
    p->top+=1;
    strcpy(p->data[p->top],new);
}
//获取栈顶元素的值
char *gettop(stack *p){
    if(isempty(p)){
        printf("获取失败\n");
        return 0;
    }
    return p->data[p->top];
}
//清空栈
void clear(stack *p){
    p->top=-1;
}
char visitHistory[1000][100];


typedef struct wangzhan{
    char name[100];
    int cnt;//访问次数
}wangzhan;


int judge(char *s){
    int l=strlen(s);
    int cnt=0;
    for(int i=0;i<l;i++){
        if(s[i]=='/')cnt++;
    }
    if(cnt==3)return 1;
    else return 2;
}
char *tiqu(char *s){
    char *tmp=(char*)malloc(sizeof(s));
    int j=0;
    int l=strlen(s);
    int cnt=0;
    for(int i=0;i<l;i++){
        tmp[j++]=s[i];
        if(s[i]=='/')cnt++;
        if(cnt==3)break;
    }
    tmp[j]='\0';
    return tmp;
}
wangzhan wz[1000];
int main(){
    //printf("%d",judge("https://www.buaa.edu.cn/jgsz/jxkyjg.htm"));
    //printf("%s",tiqu("https://www.buaa.edu.cn/jgsz/jxkyjg.htm"));
    int j=1;
    char now[100];
    strcpy(now,"https://www.baidu.com/");//当前网站
    strcpy(visitHistory[0],"https://www.baidu.com/");
    stack *up=(stack*)malloc(sizeof(stack));
    stack *down=(stack*)malloc(sizeof(stack));
    init(up);
    init(down);
    //push(down,"https://www.baidu.com/");
    char op[10];
    int k=1;
    strcpy(wz[0].name,"https://www.baidu.com/");
    wz[0].cnt=1;
    while(1){
        scanf("%s",op);
        if(strcmp(op,"VISIT")==0){
            char v[100];
            scanf("%s",v);
            push(down,now);
            strcpy(visitHistory[j++],v);
            strcpy(now,v);
            clear(up);
            //printf("$%s\n",now);

            if(judge(v)==1){
                int sig=0;
                for(int i=0;i<k;i++){
                    if(strcmp(wz[i].name,v)==0){
                        wz[i].cnt++;
                        sig=1;
                        break;
                    }
                }
                if(sig==0){
                        strcpy(wz[k].name,v);
                        wz[k].cnt=1;
                        k++;
                    }
            }
            else if(judge(v)==2){
                char tmp[100]={'\0'};
                int l=strlen(v);
                int cnt=0;
                for(int i=0;i<l;i++){
                    tmp[i]=v[i];
                    if(v[i]=='/')cnt++;
                    if(cnt==3)break;
                }

                int sig=0;
                for(int i=0;i<k;i++){
                    if(strcmp(wz[i].name,tmp)==0){
                        wz[i].cnt++;
                        sig=1;
                        break;
                    }
                }
                if(sig==0){
                        strcpy(wz[k].name,tmp);
                        wz[k].cnt=1;
                        k++;
                    }
            }
        }
        else if(strcmp(op,"<<")==0){
            //printf("$%d$",down->top);
            if(!isempty(down)){
                //printf("8**\n");
                push(up,now);
                //char s[100];
                //printf("&&&&%s\n",now);
                strcpy(now,pop(down));
                //strcpy(now,s);
                strcpy(visitHistory[j++],now);
                //printf("$%s\n",now);

                if(judge(now)==1){
                for(int i=0;i<k;i++){
                    if(strcmp(wz[i].name,now)==0){
                        wz[i].cnt++;
                        break;
                    }
                }
            }
            else if(judge(now)==2){
                char tmp[100]={'\0'};
                int l=strlen(now);
                int cnt=0;
                for(int i=0;i<l;i++){
                    tmp[i]=now[i];
                    if(now[i]=='/')cnt++;
                    if(cnt==3)break;
                }
                for(int i=0;i<k;i++){
                    if(strcmp(wz[i].name,tmp)==0){
                        wz[i].cnt++;
                        break;
                    }
                }
            }
            }
        }
        else if(strcmp(op,">>")==0){
            //printf("%d$$\n",up->top);
            if(!isempty(up)){
                push(down,now);
                strcpy(now,pop(up));
                strcpy(visitHistory[j++],now);
                //printf("$%s\n",now);

                if(judge(now)==1){
                for(int i=0;i<k;i++){
                    if(strcmp(wz[i].name,now)==0){
                        wz[i].cnt++;
                        break;
                    }
                }
            }
            else if(judge(now)==2){
                char tmp[100]={'\0'};
                int l=strlen(now);
                int cnt=0;
                for(int i=0;i<l;i++){
                    tmp[i]=now[i];
                    if(now[i]=='/')cnt++;
                    if(cnt==3)break;
                }
                for(int i=0;i<k;i++){
                    if(strcmp(wz[i].name,tmp)==0){
                        wz[i].cnt++;
                        break;
                    }
                }
            }
            }
        }
        else if(strcmp(op,"QUIT")==0){
            int fff;
            scanf("%d",&fff);
            if(fff==1){
                for(int i=0;i<j;i++){
                    printf("%s\n",visitHistory[i]);
                }
                break;
            }
            else if(fff==0){
                //printf("$$%d\n",k);
                int index;
                int max=0;
                for(int i=0;i<k;i++){
                    if(wz[i].cnt>max){
                        max=wz[i].cnt;
                        index=i;
                    }
                }
                for(int i=0;i<j;i++){
                    printf("%s\n",visitHistory[i]);
                }
                char aaa[100];
                strcpy(aaa,wz[index].name);
                char temp[100]={'\0'};
                int ll=strlen(aaa);
                int g=0;
                for(int i=8;i<ll;i++){
                    if(aaa[i]=='/')break;
                    temp[g++]=aaa[i];
                }
                printf("%s %d\n",temp,max);
                break;
            }
        }
    }
    // for(int i=0;i<k;i++){
    //     printf("%s %d\n",wz[i].name,wz[i].cnt);
    // }
    //printf("%d\n",j);
    return 0;
}