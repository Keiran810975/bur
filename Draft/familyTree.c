#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct BiTree{
    char name[50];
    struct BiTree *left;
    struct BiTree *right;
}BiTree;
//�����½��
BiTree* createNode(char *name) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
    strcpy(newNode->name,name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
//������������(���Ƕ���������)
void insertNodeLeft(BiTree* root, char *target, char *newVal) {
    if (root == NULL)
        return;
    if (strcmp(root->name,target)==0) {
        if(strcmp(newVal,"NULL")==0)root->left=NULL;
        else{
            BiTree* newNode = createNode(newVal);
            //newNode->left = root->right;
            root->left = newNode;
        }
    } else {
        // �ݹ����Ŀ��ڵ�
        insertNodeLeft(root->left, target, newVal);
        insertNodeLeft(root->right, target, newVal);
    }
}
void insertNodeRight(BiTree* root, char *target, char *newVal) {
    if (root == NULL)
        return;
    if (strcmp(root->name,target)==0) {
        // ��Ŀ��ڵ������½ڵ�
        if(strcmp(newVal,"NULL")==0)root->right=NULL;
        else{
            BiTree* newNode = createNode(newVal);
            //newNode->left = root->right;
            root->right = newNode;
        }
    } else {
        // �ݹ����Ŀ��ڵ�
        insertNodeRight(root->left, target, newVal);
        insertNodeRight(root->right, target, newVal);
    }
}
void preTree(BiTree *p){
    if(p==NULL)return;
    printf("%s ",p->name);
    preTree(p->left);
    preTree(p->right);
}
// ������нڵ�ṹ��
typedef struct QueueNode {
    BiTree *treeNode;
    struct QueueNode *next;
    struct QueueNode *parent;
} QueueNode;
// ������нṹ��
typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;
Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}
// ��Ӳ���
void enqueue(Queue *queue, BiTree *treeNode, QueueNode *parent) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    newNode->parent = parent;
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
// ���Ӳ���
QueueNode* dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    QueueNode *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return temp;
}
// �����ĳ�ڵ㵽Ŀ��ڵ�ľ���
int DistanceFromLCA(BiTree* root, char *target, int distance) {
    if (root == NULL) return -1;
    if (strcmp(root->name,target)==0) return distance;

    int left_distance = DistanceFromLCA(root->left, target, distance + 1);
    if (left_distance != -1) return left_distance;

    return DistanceFromLCA(root->right, target, distance + 1);
}
// ����LCA����:�����ڵ�������������(Lowest Common Ancestor, LCA)
BiTree* LCA(BiTree* root, char *n1, char *n2) {
    if (root == NULL) return NULL;
    if (strcmp(root->name,n1)==0 ||strcmp(root->name,n2)==0) return root;
    BiTree* left_lca = LCA(root->left, n1, n2);
    BiTree* right_lca = LCA(root->right, n1, n2);
    if (left_lca && right_lca) return root;
    return (left_lca != NULL) ? left_lca : right_lca;
}
int main(){
    FILE *op=fopen("in.txt","r");
    BiTree *root=(BiTree *)malloc(sizeof(BiTree));
    root=NULL;
    int n;
    fscanf(op,"%d",&n);
    for(int i=0;i<n;i++){
        char n1[50],n2[50],n3[50];
        fscanf(op,"%s%s%s",n1,n2,n3);//printf("%s %s %s\n",n1,n2,n3);
        if(root==NULL){
            root=createNode(n1);
            // strcpy(root->name,n1);
            // root->left=NULL;root->right=NULL;
        }
        insertNodeLeft(root,n1,n2);
        insertNodeRight(root,n1,n3);
    }
    //preTree(root);
    char s1[100],s2[100];scanf("%s%s",s1,s2);
    int h1=DistanceFromLCA(root,s1,0);
    int h2=DistanceFromLCA(root,s2,0);
    printf("&%d %d\n",h1,h2);
    if(h1!=h2){
        if(h1>h2)printf("%s %s %d",s1,s2,h1-h2);
        if(h1<h2)printf("%s %s %d",s2,s1,h2-h1);
    }else{
        BiTree *t=LCA(root,s1,s2);
        printf("%s\n",t->name);
    }
    return 0;
}