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
}info;
//多叉树存储文件的结构体
typedef struct BiTree{
    info val;
    struct BiTree *father;
    struct BiTree *child[10];//儿子们
    int numChild;//记录儿子的数量
}BiTree;
//创建新结点
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
//暴力搜索插入(不是二叉排序树)
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
//LCA(参数是int)
BiTree* findLCA2(BiTree* root, int val1, int val2) {
    BiTree* n1 = findNode(root, val1);
    BiTree* n2 = findNode(root, val2);
    if (n1 == NULL || n2 == NULL) return NULL;
    BiTree* path1[100];
    BiTree* path2[100];
    int pathLength1 = 0, pathLength2 = 0;
    if (!findPath2(root, n1, path1, &pathLength1) || !findPath2(root, n2, path2, &pathLength2)) {
        return NULL; // 如果其中一个节点不在树中
    }
    int i;
    for (i = 0; i < pathLength1 && i < pathLength2; i++) {
        if (path1[i] != path2[i]) {
            break;
        }
    }
    return path1[i-1];
}

int findDistanceFromLCA(BiTree* lca, int val) {
    if (lca == NULL) return -1;
    if (lca->val.id == val) return 0;

    int distance = -1;
    for (int i = 0; i <10; i++) {
        int d = findDistanceFromLCA(lca->child[i], val);
        if (d != -1) {
            distance = d + 1;
            break;
        }
    }
    return distance;
}
//两个结点间距
int findDistance(BiTree* root, int val1, int val2) {
    BiTree* lca = findLCA2(root, val1, val2);
    if (lca == NULL) return -1;

    int d1 = findDistanceFromLCA(lca, val1);
    int d2 = findDistanceFromLCA(lca, val2);

    return d1 + d2;
}
//两结点之间的路径
void routineBetweenNodes(BiTree* root, int val1, int val2, int path[], int* pathLength) {
    BiTree* lca = findLCA2(root, val1, val2);
    if (lca == NULL) return;

    BiTree* path1[100];
    BiTree* path2[100];
    int pathLength1 = 0, pathLength2 = 0;

    findPath2(lca, findNode(root, val1), path1, &pathLength1);
    findPath2(lca, findNode(root, val2), path2, &pathLength2);

    // 添加path1的所有节点到结果路径中
    for (int i = pathLength1-2; i>=0; i--) {
        path[(*pathLength)++] = path1[i]->val.id;
    }

    // 添加path2的所有节点到结果路径中，但不包括LCA
    for (int i = 0; i<pathLength2; i++) {
        if (path2[i] != lca) {
            path[(*pathLength)++] = path2[i]->val.id;
        }
    }
}
int printer[500];
int prenode[500];//所有设备的先序id
int k=0;
int j=0;
void preTree(BiTree *p){
    if(p==NULL)return;
    printf("%d ",p->val.id);
    //prenode[k++]=p->val.id;
    if(p->val.type==2)printer[j++]=p->val.id;
    for(int i=0;i<10;i++){
        preTree(p->child[i]);
    }
}
int main(){
    int n,m;scanf("%d%d",&n,&m);
    BiTree *root=(BiTree*)malloc(sizeof(BiTree));
    for(int i=0;i<n;i++){
        info new;
        scanf("%d%d%d%d",&new.id,&new.type,&new.parid,&new.numD);
        // if(new.type==2){
        //     printer[j++]=new.id;//存打印机编号
        // }
        insertNode(&root,new);
    }
    int min=9999;
    int minId=0;
    preTree(root);
    printf("\n%d\n",findDistance(root,11,19));
    for(int i=0;i<j;i++){
        if(findDistance(root,m,printer[i])<min){
            minId=printer[i];
            min=findDistance(root,m,printer[i]);
        }
    }
    printf("%d\n",minId);
    int path[100];
    int plen=0;
    routineBetweenNodes(root,minId,m,path,&plen);
    for(int i=0;i<plen;i++)printf("%d ",path[i]);
    return 0;
}