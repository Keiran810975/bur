#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define RED 1
#define BLACK 2
typedef int Key_Type;
//保存红黑树结点的结构体
typedef struct rbTree{
    unsigned char color;//红1  黑2
    struct rbTree *left;
    struct rbTree *right;
    struct rbTree *parent;
    Key_Type key;
    void *value;
}rbTree;
//保存红黑树外部结点
typedef struct rbTree_x{
    rbTree *root;//根结点
    rbTree *nil;//外部结点
}rbTree_x;
//生成新结点
rbTree* newNode(rbTree_x *p,int key){
    rbTree *node=(rbTree *)malloc(sizeof(rbTree));
    node->color=RED;
    node->key=key;
    node->value=NULL;
    node->left=p->nil;
    node->right=p->nil;
    node->parent=p->nil;
    return node;
}
//左旋函数
void LeftRotate(rbTree_x *p,rbTree *root){
    rbTree *newroot=root->right;
    rbTree *q=newroot->left;
    root->right=q;
    if(q!=p->nil)q->parent=root;
    if(root->parent==p->nil)p->root-newroot;
    else if(root==root->parent->left)root->parent->left=newroot;
    else if(root==root->parent->right)root->parent->right=newroot;
    newroot->left=root;
    root->parent=newroot;
}
//右旋函数
void RightRotate(rbTree_x *p,rbTree *root){
    rbTree *newroot=root->left;
    rbTree *q=newroot->right;
    root->left=q;
    if(q!=p->nil)q->parent=root;
    if(root->parent==p->nil)p->root-newroot;
    else if(root==root->parent->left)root->parent->left=newroot;
    else if(root==root->parent->right)root->parent->right=newroot;
    newroot->right=root;
    root->parent=newroot;
}
//调整插入后的失衡
void rbInsert_fix(rbTree_x *p,rbTree *u){
    
}
//插入新的结点
void rbInsert(rbTree_x *p,rbTree *z){
    rbTree *y=p->nil;
    rbTree *x=p->root;
    while(x!=p->nil){
        y=x;
        if(z->key<x->key)x=x->left;
        else if(z->key>x->key)x=x->right;
        else return;
    }
    z->parent=y;
    if(y==p->nil)p->root=z;
    else if(z->key<y->key)y->left=z;
    else if(z->key>y->key)y->right=z;
    //检测+调整现在的树是不是满足红黑树
}
int main(){

    return 0;
}