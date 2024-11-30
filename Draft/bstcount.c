#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct BiTree{
    char val[200];//单词
    int cnt;//单词出现次数
    struct BiTree *left;
    struct BiTree *right;
}BiTree;
//二叉搜索树--->用中序遍历会得到从小到大的排序
//在二叉搜索树中插入元素
void bstInsert(BiTree **p,char data[]){
    if(*p==NULL){                      //空数的情况
        BiTree *newnode=(BiTree *)malloc(sizeof(BiTree));
        strcpy(newnode->val,data);
        newnode->cnt=1;
        newnode->left=NULL;
        newnode->right=NULL;
        *p=newnode;
        return;
    }
    if(strcmp(data,(*p)->val)>0){            //不是空树的情况
        bstInsert(&((*p)->right),data);
    }else if(strcmp(data,(*p)->val)<0){
        bstInsert(&((*p)->left),data);
    }else if(strcmp(data,(*p)->val)==0){
        (*p)->cnt+=1;
        return;
    }
}
//树的先序遍历(递归)
void preTree(BiTree *p){
    if(p==NULL)return;
    printf("%s %d\n",p->val,p->cnt);
    preTree(p->left);
    preTree(p->right);
}
//中序遍历
void midTree(BiTree *p){
    if(p==NULL)return;
    midTree(p->left);
    printf("%s %d\n",p->val,p->cnt);
    midTree(p->right);
}
//后序遍历
void postTree(BiTree *p){
    if(p==NULL)return;
    postTree(p->left);
    postTree(p->right);
    printf("%d ",p->val);
}
void shit(){//处理文件
    FILE* op=fopen("article.txt","r");
    FILE *ou=fopen("fileout.txt","w");
    char c;
    while(fscanf(op,"%c",&c)!=EOF){
        //printf("<<<");
        if(c==' '||(c>='a'&&c<='z')||c=='\n')fprintf(ou,"%c",c);
        else if(c>='A'&&c<='Z'){
            c=tolower(c);
            fprintf(ou,"%c",c);
        }else{
            fprintf(ou," ");
        }
    }
    //printf("f");
    fclose(op);
    fclose(ou);
    //FILE *ooo=fopen("fileout.txt","w");
    //while(fscanf(ooo,"%c",&c)!=EOF)printf("%c",c);
    //printf("g");
}
int main(){
    BiTree *tree=(BiTree *)malloc(sizeof(BiTree));
    tree=NULL;
    // bstInsert(&tree,"aaaa");
    // printf("%s",tree->val);
    shit();
    FILE *ou=fopen("fileout.txt","r");
    char ss[100];
    int cnt=0;
    while(fscanf(ou,"%s",ss)!=EOF){
        bstInsert(&tree,ss);
    }
    printf("%s ",tree->val);
    if(tree->right!=NULL)printf("%s ",tree->right->val);
    if(tree->right->right!=NULL)printf("%s",tree->right->right->val);
    printf("\n");
    midTree(tree);
    return 0;
}