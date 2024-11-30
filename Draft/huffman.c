#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int priQ[100000];//堆(小根堆)
int len;//记录堆的长度
typedef struct BiTree{
    char c;//字符
    int val;//字符出现的次数
    struct BiTree *left;
    struct BiTree *right;
}BiTree;
//二叉搜索树--->用中序遍历会得到从小到大的排序
//在二叉搜索树中插入元素
BiTree *queue[100];
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void tswap(BiTree *x,BiTree *y){
    BiTree temp=*x;
    *x=*y;
    *y=temp;
}
void put(BiTree *newnode){//把数加在最后,长度+1，利用堆的父子节点关系,一次次与父亲比较，如果比父亲小就交换，继续比较，直到比父亲大或到了根节点为止
    int f;
    len++;
    queue[len]=newnode;
    int b=len;
    while(b!=1&&(queue[b]->val)<(queue[b/2]->val)){
        tswap(queue[b],queue[b/2]);
        b=b/2;
    }
}
BiTree* get(){//取出堆顶
//长度-1，把最后一个提到第一个。利用堆的父子节点关系，用换到第一个的数与儿子比较，
//如果比孩子大，就与两个儿子之间较小的一个交换，直到没有儿子或比儿子小为止
    BiTree *x=queue[1];
    queue[1]=queue[len];
    len--;
    int f,c;
    while(2*f<=len){
        if(2*f+1>len||queue[2*f]->val<queue[2*f+1]->val)c=2*f;
        else c=2*f+1;
        if(queue[f]->val<queue[c]->val){
        tswap(queue[f],queue[c]);
        f=c;
    }else return x;
    }
    return x;
}
void preTree(BiTree *p){
    if(p==NULL)return;
    printf("%d ",p->val);
    preTree(p->left);
    preTree(p->right);
}
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        char c;int x;
        scanf("%c",&c);
        getchar();
        scanf("%d",&x);
        BiTree *newnode=(BiTree *)malloc(sizeof(BiTree));
        newnode->val=x;
        newnode->c=c;
        newnode->left=NULL;
        newnode->right=NULL;
        put(newnode);
    }
    for(int i=0;i<n-1;i++){
        BiTree *j1=get();
        BiTree *j2=get();
        BiTree *new=(BiTree *)malloc(sizeof(BiTree));
        new->left=j1;
        new->right=j2;
        new->val=j1->val+j2->val;
        put(new);
    }
    BiTree *joi=queue[1];
    preTree(joi);
    return 0;
}