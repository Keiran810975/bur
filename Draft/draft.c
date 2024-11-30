#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct list{
    int val;
    struct list *next;
}list;
//打印链表
void PrintList(list *p){
    list *fff=p;
    while(fff!=NULL){
        printf("%d ",fff->val);
        fff=fff->next;
    }
}
void PrintList2(list *p){
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
}
//尾插
void InsertTail(list *p,int new){
    if(p==NULL)
    {
        list *head=(list *)malloc(sizeof(list));
        p=head;
        p->val=new;
        p->next=NULL;
        return;
    }
    list *fff=p;
    while(fff->next!=NULL)fff=fff->next;
    list *newnode=(list *)malloc(sizeof(list));
    newnode->val=new;
    newnode->next=NULL;
    fff->next=newnode;
}
int main(){
    list *p=(list *)malloc(sizeof(list));
    p->val=0;
    p->next=NULL;
    InsertTail(p,1);
    InsertTail(p,2);
    InsertTail(p,3);
    InsertTail(p,4);
    PrintList(p);
    printf("%d\n",p->val);
    PrintList2(p);
    printf("%d\n",p->val);

    return 0;
}