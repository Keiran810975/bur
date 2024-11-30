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
    list *q=(list *)malloc(sizeof(list));
    list *r=(list *)malloc(sizeof(list));
    r->val=1;
    r->next=NULL;
    q->next=r;
    //printf("%d",q->next->val);
    int n;scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int k,p;
        scanf("%d%d",&k,&p);
        if(p==0){
            list *nn=q;
            while(nn->next->val!=k)nn=nn->next;
            list *fff=(list *)malloc(sizeof(list));
            fff->val=i;
            fff->next=nn->next;
            nn->next=fff;
        }else if(p==1){
            list *nn=q;
            while(nn->val!=k)nn=nn->next;
            list *fff=(list *)malloc(sizeof(list));
            fff->val=i;
            fff->next=nn->next;
            nn->next=fff;
        }
    }
    int m;scanf("%d",&m);
    while(m--){
        int x;scanf("%d",&x);
        list *shit=q->next;
        list *dame=q;
        int cnt=0;
        for(int j=0;j<n;j++){
            if(shit->val!=x){
                shit=shit->next;
                dame=dame->next;
                cnt++;
            }else break;
        }
        if(cnt==n){
            n--;
            continue;
        }else{
            if(shit->next==NULL){
                dame->next=NULL;
            }else{
                dame->next=dame->next->next;
            }
            n--;
        }
    }
    list *e=q;
    while(e->next!=NULL){
        printf("%d ",e->next->val);
        e=e->next;
    }
    printf("\n");
    return 0;
}