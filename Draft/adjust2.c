#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_CHILDREN 3
// 多叉树节点结构体定义
typedef struct BiTree {
    int val;//港口编号
    int left,right;//两个登机口
    struct BiTree* child[MAX_CHILDREN]; // 儿子们
    int numChild; // 记录儿子的数量
} BiTree;
typedef struct port{
    int id;
    int flow;
}port;
// 创建新节点
BiTree* createNode(int value) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
    newNode->val = value;
    newNode->numChild = 0;
    newNode->left=0;
    newNode->right=0;
    for (int i = 0; i < MAX_CHILDREN; ++i) {
        newNode->child[i] = NULL;
    }
    return newNode;
}
// 查找节点
BiTree* findNode(BiTree* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;

    for (int i = 0; i < root->numChild; i++) {
        BiTree* found = findNode(root->child[i], val);
        if (found != NULL) return found;
    }
    return NULL;
}

// 插入元素
void insertElement(BiTree* root, int val, int newValue) {
    BiTree* targetNode = findNode(root, val);
    if (targetNode == NULL) {
        printf("节点 %d 不存在\n", val);
        return;
    }
    // 新建节点
    BiTree* newNode = createNode(newValue);
    // 查找插入位置
    int insertIndex = 0;
    while (insertIndex < targetNode->numChild && targetNode->child[insertIndex]->val < newValue) {
        insertIndex++;
    }
    // 将新节点插入到对应位置
    for (int i = targetNode->numChild; i > insertIndex; --i) {
        targetNode->child[i] = targetNode->child[i - 1];
    }
    targetNode->child[insertIndex] = newNode;
    targetNode->numChild++;
}
int cmp(const void *x,const void *y){
    port xx = *(port*)x;
    port yy = *(port*)y;
    if(xx.flow<yy.flow)return 1;
    if(xx.flow>yy.flow)return -1;
    if(xx.flow==yy.flow){
        if(xx.id>yy.id)return 1;
        if(xx.id<yy.id)return -1;
        return 0;
    }
}
// 定义队列节点的结构体
typedef struct QueueNode {
    BiTree* treeNode;
    struct QueueNode* next;
} QueueNode;
// 定义队列的结构体
typedef struct Queue {
    QueueNode* front; // 队首
    QueueNode* rear;  // 队尾
} Queue;

// 创建一个新的队列节点
QueueNode* createQueueNode(BiTree* treeNode) {
    QueueNode* newQueueNode = (QueueNode*)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    return newQueueNode;
}

// 创建一个空队列
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// 检查队列是否为空
bool isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

// 将树节点入队
void enqueue(Queue* queue, BiTree* treeNode) {
    QueueNode* newQueueNode = createQueueNode(treeNode);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newQueueNode;
        return;
    }
    queue->rear->next = newQueueNode;
    queue->rear = newQueueNode;
}

// 将树节点出队
BiTree* dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    BiTree* treeNode = temp->treeNode;
    free(temp);
    return treeNode;
}
int portUnsort[300];
int j=0;
// 多叉树的层序遍历函数
void levelOrderTraversal(BiTree* root) {
    if (root == NULL) {
        return;
    }
    Queue* queue = createQueue(); // 创建一个队列
    enqueue(queue, root); // 根节点入队
    while (!isQueueEmpty(queue)) {
        BiTree* currentNode = dequeue(queue); // 获取队首节点
        if(currentNode->left!=0)portUnsort[j++]=currentNode->left;
        if(currentNode->right!=0)portUnsort[j++]=currentNode->right;
        //printf("%d ", currentNode->val); // 打印当前节点的值
        
        // 将当前节点的所有孩子入队
        for (int i = 0; i < currentNode->numChild; i++) {
            if (currentNode->child[i] != NULL) {
                enqueue(queue, currentNode->child[i]);
            }
        }
    }
    //printf("\n");
}
int numK=0;
int main() {
    BiTree *p=(BiTree*)malloc(sizeof(BiTree));
    int root;scanf("%d",&root);
    p->val=root;
    p->left=0;
    p->right=0;
    p->numChild=0;
    for(int i=0;i<3;i++)p->child[i]=NULL;
    int cnt=0;
    //创建根结点
    while(1){
        int n;scanf("%d",&n);
        if(n==-1)break;
        else{
            if(n>=100){
                BiTree *new=createNode(n);
                p->child[p->numChild++]=new;
            }
            else if(n<100){
                if(cnt==0){
                    p->left=n;
                    cnt++;
                    numK++;
                }else{
                    p->right=n;
                    numK++;
                }
            }
        }
    }
    while(1){
        cnt=0;
        BiTree *t=(BiTree*)malloc(sizeof(BiTree));
        int n;scanf("%d",&n);
        if(n==-1)break;
        else{
            t=findNode(p,n);
        }
        while(1){
            int x;scanf("%d",&x);
            if(x==-1)break;
            else{
                if(x<100){
                    if(cnt==0){
                        t->left=x;
                        //printf("^^%d^^",t->left);
                        cnt++;
                        numK++;
                    }else{
                        t->right=x;
                        numK++;
                    }
                }
                else if(x>=100){
                    BiTree *nn=createNode(x);
                    t->child[t->numChild++]=nn;
                }
            }
        }
    }
    //printf("$%d\n",numK);
    //printf("$%d %d\n",p->child[0]->left,p->child[0]->right);
    //printf("&%d\n",findNode(p,101)->numChild);
    port ff[numK+10];
    for(int i=0;i<numK;i++){
        scanf("%d%d",&ff[i].id,&ff[i].flow);
    }
    qsort(ff,numK,sizeof(port),cmp);
    levelOrderTraversal(p);
    //for(int i=0;i<numK;i++)printf("%d ",portUnsort[i]);
    //printf("\n");
    //for(int i=0;i<numK;i++)printf("%d ",ff[i].id);
    for(int i=0;i<numK;i++){
        printf("%d->%d\n",ff[i].id,portUnsort[i]);
    }
    return 0;
}
