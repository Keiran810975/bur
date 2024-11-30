#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
char aa[600][300];
char ch[300];int i=0;
typedef struct listnode{
    char s[300];
    struct listnode *next;
}listnode;//链表
//尾插
void InsertTail(listnode *p,char new[]){
    if(p==NULL)
    {
        listnode *head=(listnode *)malloc(sizeof(listnode));
        p=head;
        strcpy(p->s,new);
        p->next=NULL;
        return;
    }
    listnode *fff=p;
    while(fff->next!=NULL)fff=fff->next;
    listnode *newnode=(listnode *)malloc(sizeof(listnode));
    strcpy(newnode->s,new);
    newnode->next=NULL;
    fff->next=newnode;
}
void psort(){
    for(int j=0;j<i-1;j++){
        for(int k=0;k<i-1;k++){
            char tmp[300];
            if(strcmp(aa[k],aa[k+1])>0){
                strpcy(tmp,aa[k]);
                strcpy(aa[k],aa[k+1]);
                strcpy(aa[k+1],tmp);
            }
        }
    }
}
//读取books并排序，转成链表
void read(){
    FILE *op=fopen("books.txt","r");
    while(fgets(ch,300,op)!=NULL){
        strcpy(aa[i],ch);
        i++;
    }
    psort();
    listnode *p=(listnode *)malloc(sizeof(listnode));
    strcpy(p->s,aa[0]);
    for(int j=1;j<i;j++){
        InsertTail(p,aa[j]);
        j++;
    }
}
//打印链表
void PrintList(listnode *p){
    listnode *fff=p;
    while(fff!=NULL){
        printf("%s\n",fff->s);
        fff=fff->next;
    }
}
void midInsert(listnode *p,char new[]){
    if(strcmp(p->s,new)<0){
        p=p->next;
    }else{
        
    }
}
//操作
void fu(){
    while(1){
        int option;
        scanf("%d",&option);
        if(option==1){

        }
    }
}
int main(){
    

    return 0;
}