#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
char o1[200],o2[200];
char secret[200],cypher[200];
typedef struct list{
    char val;
    struct list *next;
}list;
void PrintList(list *p){
    list *fff=p;
    while(fff!=NULL){
        printf("%d ",fff->val);
        fff=fff->next;
    }
}
void InsertTail(list *p,char new){
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
void PrintList2(list *p,int n){
    list *fff=p;
    while(n--){
        printf("%c ",fff->val);
        fff=fff->next;
    }
}
void f(){
    int cnt[200]={0};
    int l=strlen(o1);
    int j=0;
    for(int i=0;i<l;){
        if(cnt[o1[i]-' ']==0){
            o2[j]=o1[i];j++;
            cnt[o1[i]-' ']++;
        }else i++;
    }
    for(int i=0;i<l;i++)secret[i]=o2[i];
    for(int i=0;i<=94;i++){
        if(cnt[i]==0){
            secret[j]=' '+i;
            j++;
        }
    }
    //strcat(secret,'\0');
    //printf("%s\n",secret);
}
void CreateList(list *p){
    int l=strlen(secret);
    for(int i=1;i<l;i++){
        InsertTail(p,secret[i]);
    }
    list *fff=p;
    while(fff->next!=NULL){
        fff=fff->next;
    }
    fff->next=p;
}
void deal(list *p){
    list *fff=p;
    list *sss=p;
    while(sss->next!=fff)sss=sss->next;
    int loc,asc;
    for(int i=0;i<=94;i++){
        loc=fff->val;
        asc=fff->val;
        sss->next=fff->next;
        fff=fff->next;
        for(int k=0;k<asc-1;k++){
            fff=fff->next;
            sss=sss->next;
        }
        cypher[loc-' ']=fff->val;
    }
    //strcat(cypher,'\0');
    //printf("%s",cypher);
}
void output(){
    FILE *op=fopen("in.txt","r");
    FILE *ou=fopen("in_crpyt.txt","w");
    char ch;
    ch=fgetc(op);
    if(ch<32){
        while((ch=fgetc(op))!=EOF){     
         if(ch>=' '&&ch<='~'){
            if(cypher[ch-' ']=='o')fputc('i',ou);
            else fputc(cypher[ch-' '],ou);
         }else{
             fputc(ch,ou);
         }
     }
    }else{
        if(ch>=' '&&ch<='~'){
             fputc(cypher[ch-' '],ou);
         }else{
             fputc(ch,ou);
         }
        while((ch=fgetc(op))!=EOF){     
         if(ch>=' '&&ch<='~'){
             fputc(cypher[ch-' '],ou);
         }else{
             fputc(ch,ou);
         }
     }
    }
    //printf("%s",cypher);
    //fputs(cypher, ou);
}
int main(){
    gets(o1);
    //puts(o1);
    f();
    list *p=(list *)malloc(sizeof(list));
    p->val=secret[0];
    p->next=NULL;
    CreateList(p);
    deal(p);
    output();
    return 0;
}