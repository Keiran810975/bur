#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<deque>
#include<list>
using namespace std;
typedef struct listnode{
    int val;
    struct listnode *next;
}listnode;
//尾插
void InsertTail(listnode *p,int aaa){
    if(p==NULL)
    {
        listnode *head=(listnode *)malloc(sizeof(listnode));
        p=head;
        p->val=aaa;
        p->next=NULL;
        return;
    }
    listnode *fff=p;
    while(fff->next!=NULL)fff=fff->next;
    listnode *newnode=(listnode *)malloc(sizeof(listnode));
    newnode->val=aaa;
    newnode->next=NULL;
    fff->next=newnode;
}
int main(){
   listnode *p=new listnode;
   int n;cin>>n;
   int first;cin>>first;
   for(int i=0;i<n-2;i++){
    int x;cin>>x;
    InsertTail(p,x);
   }
   int tail;cin>>tail;
   InsertTail(p,tail);
   int flag=1;
   int num=p->val;
   while(1){
    if(num==flag){
        
    }
   }
    return 0;
}