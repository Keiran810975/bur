#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#define MAX 100
//存储一个结点的信息
typedef struct info{
    int id;
    int parid;
    int type;
    int numD;//端口号
    //int dep;
}info;
//多叉树存储文件的结构体
typedef struct BiTree{
    //int dep;
    info val;
    struct BiTree *father;
    struct BiTree *child[10];//儿子们
    int numChild;//记录儿子的数量
}BiTree;
BiTree* createNode(info val) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
        newNode->val = val;
        newNode->numChild=0;
        for(int i=0;i<10;i++){
            newNode->child[i]=NULL;
        }
    return newNode;
}
// 查找节点
BiTree* findNode(BiTree* root, int val) {
    if (root == NULL) return NULL;
    if (root->val.id == val) return root;

    for (int i = 0; i < 10; i++) {
        BiTree* found = findNode(root->child[i], val);
        if (found != NULL) return found;
    }
    return NULL;
}
void insertNode(BiTree** root, info newVal) {
    if(newVal.parid==-1){//根节点
        *root=createNode(newVal);
        return;
    }
    if((*root)==NULL)return;
    if ((*root)->val.id==newVal.parid){ 
        // 在目标节点后插入新节点
        BiTree* newNode = createNode(newVal);
        //newNode->child[] = root->right;
        (*root)->child[newVal.numD]=newNode;
    } else {
        // 递归查找目标节点
        for(int i=0;i<10;i++){
            insertNode(&((*root)->child[i]),newVal);
        }
    }
}
int findPath2(BiTree* root, BiTree* target, BiTree* path[], int* pathLength) {
    if (root == NULL) return 0;
    path[*pathLength] = root;
    (*pathLength)++;
    if (root == target) return 1;

    for (int i = 0; i < 10; i++) {
        if (findPath2(root->child[i], target, path, pathLength)) {
            return 1;
        }
    }
    (*pathLength)--;
    return 0;
}
//深度
int getDepth(BiTree* root, int target, int depth) {
    if (root == NULL) {
        return -1;  // 没有找到节点，返回-1
    }
    if (root->val.id == target) {
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
// void preTree(BiTree *p){
//     if(p==NULL)return;
//     printf("%d ",p->val.id);
//     //prenode[k++]=p->val.id;
//     for(int i=0;i<10;i++){
//         preTree(p->child[i]);
//     }
// }
int beat[2500];
int error[2500];
int good[2500];
int main(){
    int n;scanf("%d",&n);
    BiTree *root=(BiTree*)malloc(sizeof(BiTree));
    for(int i=0;i<n;i++){
        info new;
        scanf("%d%d%d%d",&new.id,&new.type,&new.parid,&new.numD);
        // if(new.type==2){
        //     printer[j++]=new.id;//存打印机编号
        // }
        insertNode(&root,new);
        //new.dep=getDepth(root,new.id,0);
    }


    //*********到此处为止，完成树的构建 */


    
    int j=0;
    while(1){
        int a;
        scanf("%d",&a);
        if(a==-1)break;
        beat[j++]=a;
    }
    //printf("%d\n",beat[0]);
    //for(int i=0;i<j;i++)printf("%d ",beat[i]);
    //printf("%d\n",j);
    for(int i=0;i<j;i++){
        BiTree *path[2500];
        BiTree *target=findNode(root,beat[i]);
        int pathlength=0;
        findPath2(root,target,path,&pathlength);
        for(int k=0;k<pathlength;k++){
            //printf("$%d",path[k]->val.id);
            good[path[k]->val.id]=1;//记录一定好用的交换机
        }
        //printf("\n");
    }
    for(int i=0;i<50;i++)printf("%d ",good[i]);
    return 0;
}