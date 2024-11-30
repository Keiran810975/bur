#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct list{
    int co;
    int in;
    struct list *next;
}list;
void ListBsort(list *head){
    list *pre,*p,*q;
    list *tail=NULL;
    while(head->next!=tail){
        pre=head;
        p=head->next;
        q=p->next;
        while(p->next!=tail){
            if(p->in<q->in){
                pre->next=q;
                p->next=q->next;
                q->next=p;
            }else p=p->next;
        q=p->next;
        pre=pre->next;
        }
        tail=p;
    }
}
void InsertTail(list *p,int a,int b){
    if(p==NULL){
        list *head=(list *)malloc(sizeof(list));
        p=head;
        p->co=a;
        p->in=b;
        p->next=NULL;
        return;
    }
    list *fff=p;
    while(fff->next!=NULL)fff=fff->next;
    list *newnode=(list *)malloc(sizeof(list));
    newnode->co=a;
    newnode->in=b;
    newnode->next=NULL;
    fff->next=newnode;
}
void multi(list *p,list *q,list *r){
    list *fff=p;
    list *sss=q;
    while(fff!=NULL){
        sss=q;
        while(sss!=NULL){
            int x,y;
            x=(fff->co)*(sss->co);
            y=(fff->in)+(sss->in);
            InsertTail(r,x,y);
            sss=sss->next;
        }
        fff=fff->next;
    }
}
void combine(list *r){
    list *fff=r->next;
    while(fff->next!=NULL){
        if(fff->in==fff->next->in){
            fff->co=fff->co+fff->next->co;
            fff->next=fff->next->next;
        }
        else fff=fff->next;
    }
}
void delete(list *r){
    list *fff=r;
    while(fff->next!=NULL){
        if(fff->next->co==0){
            fff->next=fff->next->next;
        }
        fff=fff->next;
    }
}
void PrintList(list *p){
    list *fff=p->next;
    while(fff!=NULL){
        printf("%d %d ",fff->co,fff->in);
        fff=fff->next;
    }
}
int main(){
    list *p=(list *)malloc(sizeof(list));
    list *q=(list *)malloc(sizeof(list));
    int a,b;
    p->co=1;
    p->in=2;
    p->next=NULL;
    q->co=1;
    q->in=2;
    q->next=NULL;
    //PrintList(p);
    char c;
    while(1){
        scanf("%d%d%c",&a,&b,&c);
        InsertTail(p,a,b);
        if(c=='\n')break;
    }
    //PrintList(p);
    //printf("\n");
    while(1){
        scanf("%d%d%c",&a,&b,&c);
        InsertTail(q,a,b);
        if(c=='\n')break;
    }
    //PrintList(q);
    //printf("\n");
    list *r=(list *)malloc(sizeof(list));
    r->co=1;
    r->in=2;
    r->next=NULL;
    multi(p->next,q->next,r);
    ListBsort(r);
    combine(r);
    delete(r);
    PrintList(r);
    return 0;
}