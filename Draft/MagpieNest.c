#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_CHILDREN 3
// 多叉树节点结构体定义
typedef struct BiTree {
    int val;
    struct BiTree* child[MAX_CHILDREN]; // 儿子们
    int numChild; // 记录儿子的数量
} BiTree;
// 创建新节点
BiTree* createNode(int value) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
    newNode->val = value;
    newNode->numChild = 0;
    for (int i = 0; i < MAX_CHILDREN; ++i) {
        newNode->child[i] = NULL;
    }
    return newNode;
}
BiTree* findNode(BiTree* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;

    for (int i = 0; i < root->numChild; i++) {
        BiTree* found = findNode(root->child[i], val);
        if (found != NULL) return found;
    }
    return NULL;
}
void preTree(BiTree* root) {
    if (root == NULL) {
        return;
    }
        printf("%d ",root->val);
    for(int i=0;i<root->numChild;i++){
        preTree(root->child[i]);
    }
}
// 打印多叉树
void printTree(BiTree* root) {
    if (root == NULL) {
        return;
    }
    printf("%d -> ", root->val);
    for (int i = 0; i < root->numChild; ++i) {
        printf("%d ", root->child[i]->val);
    }
    printf("\n");
    for (int i = 0; i < root->numChild; ++i) {
        printTree(root->child[i]);
    }
}
// 计算节点在多叉树中的深度
int getDepth(BiTree* root, int target, int depth) {
    if (root == NULL) {
        return -1;  // 没有找到节点，返回-1
    }
    if (root->val == target) {
        return depth;  // 找到节点，返回当前深度
    }
    
    for (int i = 0; i < root->numChild; ++i) {
        int childDepth = getDepth(root->child[i], target, depth + 1);
        if (childDepth != -1) {
            return childDepth;  // 如果在子节点中找到目标节点，返回其深度
        }
    }
    return -1;  // 如果所有子节点中都没有找到目标节点，返回-1
}
int maxHeight=0;
int maxchild=0;
int ans[100];
int j=0;
BiTree *root;
void findMaxchild(BiTree *p){
    if(p==NULL)return;
        //int h=getDepth(root,p->val,0);
    int c=p->numChild;
    if(c>maxchild)maxchild=c;
    for(int i=0;i<p->numChild;i++){
        findMaxchild(p->child[i]);
    }
}
void findmaxheight(BiTree *p){
    if(p==NULL)return;
    int h=getDepth(root,p->val,0);
    if(h>maxHeight)maxHeight=h;
    for(int i=0;i<p->numChild;i++){
        findmaxheight(p->child[i]);
    }
}
void findAnswer(BiTree *p){
    if(p==NULL)return;
    int h=getDepth(root,p->val,0);
    int c=p->numChild;
    if(p->numChild==maxchild&&h==maxHeight){
        ans[j++]=p->val;
    }
}
int main(){
    root=(BiTree*)malloc(sizeof(BiTree));
    root=NULL;
    int n;scanf("%d",&n);
    int a,b,c,d;
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(root==NULL){
            root=createNode(a);
            if(b!=0){root->child[0]=createNode(b);root->numChild++;}
            else root->child[0]=NULL;
            if(c!=0){root->child[1]=createNode(c);root->numChild++;}
            else root->child[1]=NULL;
            if(d!=0){root->child[2]=createNode(d);root->numChild++;}
            else root->child[2]=NULL;
        }else{
            BiTree *t=findNode(root,a);
            if(b!=0){t->child[0]=createNode(b);t->numChild++;}
            else t->child[0]=NULL;
            if(c!=0){t->child[1]=createNode(c);t->numChild++;}
            else t->child[1]=NULL;
            if(d!=0){t->child[2]=createNode(d);t->numChild++;}
            else t->child[2]=NULL;
        }
    }
    preTree(root);
    printf("\n");
    //printTree(root);
    findMaxchild(root);
    findmaxheight(root);
    findAnswer(root);
    for(int i=0;i<j;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}