#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct list{
    int ad;
    int size;
    struct list *next;
}list;
int n;
int apply[200];
int i=0;
void InsertTail(list *p,int new1,int new2){
    if(p==NULL)
    {
        list *head=(list *)malloc(sizeof(list));
        p=head;
        p->ad=new1;
        p->size=new2;
        p->next=NULL;
        return;
    }
    list *fff=p;
    while(fff->next!=NULL)fff=fff->next;
    list *newnode=(list *)malloc(sizeof(list));
    newnode->ad=new1;
    newnode->size=new2;
    newnode->next=NULL;
    //newnode->next=p;
    fff->next=newnode;
}
void PrintList(list *p){
    list *fff=p;
    while(fff!=NULL){
        printf("%d %d\n",fff->ad,fff->size);
        fff=fff->next;
    }
}
void PrintList2(list *p,int n){
    list *fff=p;
    //printf("%d %d\n",fff->ad,fff->size);
    while(n--){
        printf("%d %d\n",fff->ad,fff->size);
        fff=fff->next;
    }
}
void sc(list *p){
    scanf("%d",&n);
    int a,b;
    scanf("%d%d",&a,&b);
    p->ad=a;p->size=b;
    p->next=NULL;
    PrintList(p);
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        InsertTail(p,a,b);
        //PrintList(p);
    }
    PrintList(p);
    list *fff=p;
    while(fff->next!=NULL)fff=fff->next;
    fff->next=p;
    //PrintList(p);
    while(1){
        int x;
        scanf("%d",&x);
        if(x==-1)break;
        else{
            apply[i]=x;
            i++;
        }
    }
}
void deal(list *p){
    list *fff=p;
    list *sss=p;
    for(int k=0;k<n-1;k++)sss=sss->next;
    for(int j=0;j<i;j++){
        int cnt=0;
        //int sig=0;
        //printf("%d %d",sss->ad,sss->size);
        for(int k=0;k<n;k++){//////////////////
            if(fff->size<apply[j]){
            cnt++;
            fff=fff->next;
            sss=sss->next;
            }
        }
        if(cnt==n)continue;
        //if(sig==1)continue;
        int min=fff->size;
        // for(int k=0;k<n;k++){
        //     if(fff->size>=apply[j]&&fff->size<min){
        //         min=fff->size;
        //     }
        //     fff=fff->next;
        // }
        // //printf("%d ",min);
        // while(fff->size!=min){
        //     fff=fff->next;
        //     sss=sss->next;
        // }
        //printf("1 ");
        if(min==apply[j]){
            sss->next=fff->next;
            fff=fff->next;
            n--;
        }else if(min>apply[j]){
            fff->size=(fff->size)-apply[j];
        }
        //PrintList2(fff,n);
    }
    PrintList2(fff,n);
}
int main(){
    list *p=(list *)malloc(sizeof(list));
    //sc(p);
    scanf("%d",&n);
    int a,b;
    scanf("%d%d",&a,&b);
    p->ad=a;p->size=b;
    p->next=NULL;
    //PrintList(p);
    for(int j=1;j<n;j++){
        scanf("%d%d",&a,&b);
        InsertTail(p,a,b);
    }
    //PrintList(p);
    list *fff=p;
    while(fff->next!=NULL)fff=fff->next;
    fff->next=p;
    while(1){
        int x;
        scanf("%d",&x);
        if(x==-1)break;
        else{
            apply[i]=x;
            i++;
        }
    }
    //for(int j=0;j<i;j++)printf("%d ",apply[j]);
    deal(p);
    //printf("%d %d",p->ad,p->size);
    //PrintList2(p);
    return 0;
}