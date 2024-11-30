#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
//二叉树
typedef struct BiTree{
    int val;
    int depth;
    struct BiTree *left;
    struct BiTree *right;
}BiTree;
//二叉搜索树--->用中序遍历会得到从小到大的排序
//在二叉搜索树中插入元素
void bstInsert(BiTree **p,int data,int d){
    if(*p==NULL){                      //空数的情况
        BiTree *newnode=(BiTree *)malloc(sizeof(BiTree));
        newnode->val=data;
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->depth=d;
        *p=newnode;
        return;
    }
    if(data>=(*p)->val){            //不是空树的情况
        bstInsert(&((*p)->right),data,++d);
    }else if(data<(*p)->val){
        bstInsert(&((*p)->left),data,++d);
    }
}
//在二叉搜索树中查找元素(返回地址)
BiTree *bstSearch(BiTree *p,int data){
    if(p==NULL)return NULL;//空树
    if(data==p->val)return p;
    if(data>p->val)return bstSearch(p->right,data);
    if(data<p->val)return bstSearch(p->left,data);
    return NULL;//没有找到
}
//删除二叉搜索树中的结点
BiTree *bstDelete(BiTree *p,int data){
    if(p==NULL)return NULL;//空树
    if(data<p->val){
        bstDelete(p->left,data);
        return p;
    }else if(data>p->val){
        bstDelete(p->right,data);
        return p;
    }else if(data==p->val){
        if(p->left==NULL&&p->right==NULL){
            BiTree *temp=p;
            free(p);
            temp=NULL;
            return temp;
        }else if(p->left!=NULL&&p->right==NULL){
            BiTree *temp=p->left;
            free(p);
            return temp;
        }else if(p->left==NULL&&p->right!=NULL){
            BiTree *temp=p->right;
            free(p);
            return temp;
        }else if(p->left!=NULL&&p->right!=NULL){//让要删除结点的左子树都放在右子树最小结点的左子树上，
            BiTree *cur=p->right;               //并让修改后的右子树代替删除的结点(反过来也行)
            while(cur->left!=NULL)cur=cur->left;             //找到右子树上的最小结点
            cur->left=p->left;
            BiTree *temp=p->right;
            free(p);
            return temp;
        }
    }
    return p;        //未找到要删除的结点
}
//树的先序遍历(递归)
void preTree(BiTree *p){
    if(p==NULL)return;
    printf("%d ",p->val);
    preTree(p->left);
    preTree(p->right);
}
//中序遍历
void midTree(BiTree *p){
    if(p==NULL)return;
    midTree(p->left);
    if(p->left==NULL&&p->right==NULL)
    printf("%d %d\n",p->val,p->depth);
    midTree(p->right);
}
//后序遍历
void postTree(BiTree *p){
    if(p==NULL)return;
    postTree(p->left);
    postTree(p->right);
    printf("%d ",p->val);
}
//先序创建二叉树
void precreate(BiTree **p){
    int n;
    scanf("%d",&n);
    if(n==0){
        *p=NULL;
        return;
    }else{
        BiTree *newnode=(BiTree *)malloc(sizeof(BiTree));
        newnode->val=n;
        *p=newnode;
        precreate(&((*p)->left));
        precreate(&((*p)->right));
    }
}
int main(){
    int n;scanf("%d",&n);
    BiTree *sss=(BiTree *)malloc(sizeof(BiTree));
    sss=NULL;
    while(n--){
        int t;scanf("%d",&t);
        bstInsert(&sss,t,1);
    }
    //preTree(sss);
    midTree(sss);
    return 0;
}