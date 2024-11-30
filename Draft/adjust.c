#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 10
typedef struct TreeNode { 
    int ID; //树节点的编号
    struct TreeNode *child[MAX]; 
} Tree;
typedef struct Port { 
    int num; 
    int size;
} Port;
// 多叉树节点结构体定义
typedef struct BiTree {
    int val;//港口编号
    int left,right;//两个登机口
    struct BiTree* child[5]; // 儿子们
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
    for (int i = 0; i <5; ++i) {
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
Tree node[2000];
int q[1000]; //q里存的是层次遍历序
int root, child;
int i, j, top = 0, num;
Tree *fff[200], *p;
void layerorder(Tree *t) 
{
    int front, rear;
    if (t != NULL) {
        fff[0] = t;
        front = -1, rear = 0;
        while (front < rear) //队列里还有元素
        {
            p = fff[++front];
            if (p->child[0] == NULL && p->child[1] == NULL && p->child[2] == NULL) {
                q[top] = p->ID; //存下层次遍历
                top++;
            }
            for (i = 0; i <= 3; i++) {
                if (p->child[i] != NULL) // 若子树非空
                {
                    fff[++rear] = p->child[i]; //继续
                }
            }
        }
    }
}
int cmp(const void *x,const void *y){
    Port xx = *(Port*)x;
    Port yy = *(Port*)y;
    if(xx.size<yy.size)return 1;
    if(xx.size>yy.size)return -1;
    if(xx.size==yy.size){
        if(xx.num>yy.num)return 1;
        if(xx.num<yy.num)return -1;
        return 0;
    }
}
// int cmp2(const void *p1, const void *p2) {
//     const Port *a = (const Port *) p1;
//     const Port *b = (const Port *) p2;
//     if (a->size != b->size) return b->size - a->size; //排人流 
//     else return a->ID - b->ID; //排编号 
// }
int main() {
    while (1)
    {
        scanf("%d", &root);
        if (root == -1) break;
        else {
            num++;
            node[root].ID = root;
            i = 0;
            while (1) {
                scanf("%d", &child);
                if (child == -1) break;
                else {
                    node[root].child[i] = &node[child];
                    node[child].ID = child;
                    i++;
                }
            }
        }
    }
    layerorder(&node[100]); 
    Port port[top];
    for (i = 0; i < top; i++) {
        scanf("%d %d", &port[i].num, &port[i].size); 
    }
    qsort(port, top, sizeof(Port), cmp);
    for (i = 0; i < top; i++)
        printf("%d->%d\n", port[i].num, q[i]);
    return 0;
}
