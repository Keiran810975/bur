#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#define MAX 100
typedef struct info{
    char name[200];
    char parentname[200];
    int type;
    char date[200];
}info;
//多叉树存储文件的结构体
typedef struct BiTree{
    info val;
    struct BiTree *child[100];//儿子们
    int numChile;//记录儿子的数量
}BiTree;
//创建新结点
BiTree* createNode(info val) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
        newNode->val = val;
        newNode->numChile=0;
        for(int i=0;i<100;i++){
            newNode->child[i]=NULL;
        }
    return newNode;
}
//暴力搜索插入(不是二叉排序树)
void insertNode(BiTree** root, info newVal) {
    if(strcmp(newVal.parentname,"-")==0){
        *root=createNode(newVal);
        return;
    }
    //if((*root)=NULL)return;
    if (strcmp((*root)->val.name,newVal.parentname)==0) { 
        // 在目标节点后插入新节点
        BiTree* newNode = createNode(newVal);
        //newNode->child[] = root->right;
        (*root)->child[(*root)->numChile++]=newNode;
    } else {
        // 递归查找目标节点
        for(int i=0;i<(*root)->numChile;i++){
            insertNode(&((*root)->child[i]),newVal);
        }
    }
}
typedef struct {
    BiTree* node;
    char path[1000]; // 假设路径长度不超过1000
} QueueNode;
BiTree* searchByLevel(BiTree* root, char *target, char *path) {
    if (root == NULL)
        return NULL;

    // 创建队列用于层次遍历
    QueueNode queue[1000]; // 假设二叉树节点数量不超过1000
    int front = 0, rear = 0;

    // 初始化队列
    queue[rear].node = root;
    strcpy(queue[rear].path, root->val.name);
    rear++;

    while (front < rear) {
        QueueNode current = queue[front++];
        BiTree* currentNode = current.node;
        strcpy(path, current.path);

        if (strcmp(target, currentNode->val.name) == 0) {
            return currentNode; // 找到目标值，返回节点指针
        }

        // 将当前节点的儿子节点加入队列，并记录路径
        for (int i = 0; i < currentNode->numChile; i++) {
            if (currentNode->child[i]) {
                queue[rear].node = currentNode->child[i];
                snprintf(queue[rear].path, sizeof(queue[rear].path), "%s->%s", current.path, currentNode->child[i]->val.name);
                rear++;
            }
        }
    }

    return NULL; // 未找到目标值
}
// //按层次遍历顺序搜索
// BiTree* searchByLevel(BiTree* root, char *target,char *path){
//     if (root == NULL)
//         return NULL;
//     // 创建队列用于层次遍历
//     BiTree* queue[1000]; // 假设二叉树节点数量不超过1000
//     int front = 0, rear = 0;
//     queue[rear++] = root;
    
//     //用字符串记录路径

//     while (front < rear) {
//         BiTree* current = queue[front++];
//         if (strcmp(target,current->val.name)==0) {
//             return current; // 找到目标值，返回节点指针
//         }
//         // 将当前节点的左右子节点加入队列
//         for(int i=0;i<current->numChile;i++){
//             if(current->child[i])queue[rear++]=current->child[i];
//         }
//     }
//     return NULL; // 未找到目标值
// }
//二叉搜索??--->用中序遍历会得到从小到大的排??
//先序遍历
void preTree(BiTree *p){
    if(p==NULL)return;
    printf("%s\n",p->val.name);
    for(int i=0;i<p->numChile;i++){
        preTree(p->child[i]);
    }
}
int main(){
    BiTree *p=(BiTree*)malloc(sizeof(BiTree));
    FILE *op=fopen("files.txt","r");
    info temp;
    while(fscanf(op,"%s%s%d%s",temp.name,temp.parentname,&temp.type,temp.date)!=EOF){
        insertNode(&p,temp);
    }
    char path[200]={'\0'};
    char s[100];
    scanf("%s",s);
    searchByLevel(p,s,path);
    printf("%s\n",path);
    //preTree(p);
    return 0;
}