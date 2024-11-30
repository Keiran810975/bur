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
//头插
void InsertHead(list **p,int new){
    list *head=(list *)malloc(sizeof(list));
    head->val=new;
    head->next=*p;
    *p=head;
}
//尾删
void DeleteTail(list *p){
    if(p->next==NULL){
        free(p);
        return;
    }
    list *q=p;
    while(q->next->next!=NULL)q=q->next;
    free(q->next);
    q->next=NULL;
}
int main(){
    list *p=(list *)malloc(sizeof(list));
    p->val=0;
    p->next=NULL;
    list *q=(list *)malloc(sizeof(list));
    list *r=(list *)malloc(sizeof(list));
    q->val=114;
    q->next=NULL;
    r->val=810;
    r->next=NULL;
    p->next=q;
    q->next=r;
    list *fff=p;
    InsertTail(p,50);
    InsertTail(p,66);
    InsertHead(&p,777);
    DeleteTail(p);
    InsertHead(&p,343);
    PrintList(p);
    printf("\n");
    list *t=p->next;
    list *tt=p;
    while(t->val!=114&&t!=NULL){
        t=t->next;
        tt=tt->next;
    }
    printf("%d %d %d\n",t->val,tt->val,t->next->val);
    tt->next=t->next;
    free(t);
    PrintList(p);
    return 0;
}