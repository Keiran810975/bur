#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#define MAX 100
//�洢һ��������Ϣ
typedef struct info{
    int id;
    int parid;
    int type;
    int numD;//�˿ں�
    //int dep;
}info;
//������洢�ļ��Ľṹ��
typedef struct BiTree{
    //int dep;
    info val;
    struct BiTree *father;
    struct BiTree *child[10];//������
    int numChild;//��¼���ӵ�����
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
// ���ҽڵ�
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
    if(newVal.parid==-1){//���ڵ�
        *root=createNode(newVal);
        return;
    }
    if((*root)==NULL)return;
    if ((*root)->val.id==newVal.parid){ 
        // ��Ŀ��ڵ������½ڵ�
        BiTree* newNode = createNode(newVal);
        //newNode->child[] = root->right;
        (*root)->child[newVal.numD]=newNode;
    } else {
        // �ݹ����Ŀ��ڵ�
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
//���
int getDepth(BiTree* root, int target, int depth) {
    if (root == NULL) {
        return -1;  // û���ҵ��ڵ㣬����-1
    }
    if (root->val.id == target) {
        return depth;  // �ҵ��ڵ㣬���ص�ǰ���
    }
    
    for (int i = 0; i < root->numChild; ++i) {
        int childDepth = getDepth(root->child[i], target, depth + 1);
        if (childDepth != -1) {
            return childDepth;  // ������ӽڵ����ҵ�Ŀ��ڵ㣬���������
        }
    }
    return -1;  // ��������ӽڵ��ж�û���ҵ�Ŀ��ڵ㣬����-1
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
        //     printer[j++]=new.id;//���ӡ�����
        // }
        insertNode(&root,new);
        //new.dep=getDepth(root,new.id,0);
    }


    //*********���˴�Ϊֹ��������Ĺ��� */


    
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
            good[path[k]->val.id]=1;//��¼һ�����õĽ�����
        }
        //printf("\n");
    }
    for(int i=0;i<50;i++)printf("%d ",good[i]);
    return 0;
}