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
}info;
//������洢�ļ��Ľṹ��
typedef struct BiTree{
    info val;
    struct BiTree *father;
    struct BiTree *child[10];//������
    int numChild;//��¼���ӵ�����
}BiTree;
//�����½��
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
//������������(���Ƕ���������)
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
//LCA(������int)
BiTree* findLCA2(BiTree* root, int val1, int val2) {
    BiTree* n1 = findNode(root, val1);
    BiTree* n2 = findNode(root, val2);
    if (n1 == NULL || n2 == NULL) return NULL;
    BiTree* path1[100];
    BiTree* path2[100];
    int pathLength1 = 0, pathLength2 = 0;
    if (!findPath2(root, n1, path1, &pathLength1) || !findPath2(root, n2, path2, &pathLength2)) {
        return NULL; // �������һ���ڵ㲻������
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
//���������
int findDistance(BiTree* root, int val1, int val2) {
    BiTree* lca = findLCA2(root, val1, val2);
    if (lca == NULL) return -1;

    int d1 = findDistanceFromLCA(lca, val1);
    int d2 = findDistanceFromLCA(lca, val2);

    return d1 + d2;
}
//�����֮���·��
void routineBetweenNodes(BiTree* root, int val1, int val2, int path[], int* pathLength) {
    BiTree* lca = findLCA2(root, val1, val2);
    if (lca == NULL) return;

    BiTree* path1[100];
    BiTree* path2[100];
    int pathLength1 = 0, pathLength2 = 0;

    findPath2(lca, findNode(root, val1), path1, &pathLength1);
    findPath2(lca, findNode(root, val2), path2, &pathLength2);

    // ���path1�����нڵ㵽���·����
    for (int i = pathLength1-2; i>=0; i--) {
        path[(*pathLength)++] = path1[i]->val.id;
    }

    // ���path2�����нڵ㵽���·���У���������LCA
    for (int i = 0; i<pathLength2; i++) {
        if (path2[i] != lca) {
            path[(*pathLength)++] = path2[i]->val.id;
        }
    }
}
int printer[500];
int prenode[500];//�����豸������id
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
        //     printer[j++]=new.id;//���ӡ�����
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