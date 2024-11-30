#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX(a,b) a>b?a:b
typedef struct AVLTree{
    int val;
    int height;
    struct AVLTree *left;
    struct AVLTree *right;
}AVLTree;
//生成新结点
AVLTree *newnode(int data){
    AVLTree *p=(AVLTree *)malloc(sizeof(AVLTree));
    p->val=data;
    p->height=1;
    p->left=NULL;
    p->right=NULL;
    return p;
}
//获取树高
int GetHeight(AVLTree *p){
    if(p==NULL)return 0;
    return p->height;
}
//获取平衡因子
int GetBalance(AVLTree *p){
    return GetHeight(p->left)-GetHeight(p->right);
}
//左旋函数
//当前结点的右子树作为新的根结点，当前结点会作为新的根节点的左子树
//如果新的根结点原来就有左子树，则原来的左子树就作为旧根结点的右子树
AVLTree *LeftRotate(AVLTree *root){
    AVLTree *newroot=root->right;
    AVLTree *temp=newroot->left;
    newroot->left=root;
    root->right=temp;
    root->height=1+MAX(GetHeight(root->left),GetHeight(root->right));
    newroot->height=1+MAX(GetHeight(newroot->left),GetHeight(newroot->right));
    return newroot;
}
//右旋函数(和左旋相反)
AVLTree *RightRotate(AVLTree *root){
    AVLTree *newroot=root->left;
    AVLTree *temp=newroot->right;
    newroot->right=root;
    root->left=temp;
    root->height=1+MAX(GetHeight(root->left),GetHeight(root->right));     //更新树高
    newroot->height=1+MAX(GetHeight(newroot->left),GetHeight(newroot->right));
    return newroot;
}
//插入节点
AVLTree *AVLInsert(AVLTree *p,int data){
    if(p==NULL)return newnode(data);
    if(data<p->val)p->left=AVLInsert(p->left,data);
    else if(data>p->val)p->right=AVLInsert(p->right,data);
    p->height=1+MAX(GetHeight(p->left),GetHeight(p->right));
    int balance=GetBalance(p);
    if(balance>1&&GetBalance(p->left)>0)return RightRotate(p);//LL型失衡
    if(balance<-1&&GetBalance(p->right)<0)return LeftRotate(p);//RR型失衡
    if(balance>1&&GetBalance(p->left)<0){                     //LR型失衡
        p->left=LeftRotate(p->left);
        return RightRotate(p);
    }
    if(balance<-1&&GetBalance(p->right)>0){                     //LR型失衡
        p->right=RightRotate(p->right);
        return LeftRotate(p);
    }
    return p;
}
int main(){
    printf("0");
    return 0;
}