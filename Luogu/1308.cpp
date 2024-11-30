#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char target[20],text[20];
typedef struct biTree{
    char word[20];
    struct biTree *left;
    struct biTree *right;
    int cnt;
}biTree;
biTree *createNode(char *data){
    biTree *newnode=(biTree *)malloc(sizeof(biTree));
    strcpy(newnode->word,data);
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->cnt=0;
}
void bstInsert(biTree **p,char *data){
    if(*p==NULL){                      //空数的情况
        *p=createNode(data);
        return;
    }
    if(strcmp(data,(*p)->word)>0){            //不是空树的情况
        bstInsert(&((*p)->right),data);
    }else if(strcmp(data,(*p)->word)<0){
        bstInsert(&((*p)->left),data);
    }else if(strcmp(data,(*p)->word)==0){
        (*p)->cnt+=1;
    }
}
int sig=0;
int search(biTree *p,char *data){
    if(strcmp(data,p->word)==0){
        sig=1;
        return p->cnt;
        }
    if(strcmp(data,p->word)>0)search(p->right,data);
    if(strcmp(data,p->word)<0)search(p->left,data);
}
int main(){
    cin>>target;
    biTree *root=(biTree *)malloc(sizeof(biTree));
    while(scanf("%s",text)!=EOF){
        bstInsert(&root,text);
    }
    int 
    return 0;
}