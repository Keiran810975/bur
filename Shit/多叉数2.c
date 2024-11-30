#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义树节点可以拥有的最大孩子数量
#define MAX_CHILDREN 10

// 定义树节点的结构体
typedef struct BiTree {
    int val;
    struct BiTree* child[MAX_CHILDREN]; // 孩子们
    int numChild; // 记录孩子的数量
} BiTree;
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

// 创建一个新的树节点
BiTree* createNode(int val) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
    newNode->val = val;
    newNode->numChild = 0;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        newNode->child[i] = NULL;
    }
    return newNode;
}

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

// 多叉树的层序遍历函数
void levelOrderTraversal(BiTree* root) {
    if (root == NULL) {
        return;
    }
    Queue* queue = createQueue(); // 创建一个队列
    enqueue(queue, root); // 根节点入队
    while (!isQueueEmpty(queue)) {
        BiTree* currentNode = dequeue(queue); // 获取队首节点
        printf("%d ", currentNode->val); // 打印当前节点的值
        // 将当前节点的所有孩子入队
        for (int i = 0; i < currentNode->numChild; i++) {
            if (currentNode->child[i] != NULL) {
                enqueue(queue, currentNode->child[i]);
            }
        }
    }
    printf("\n");
}

// 比较函数用于排序
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
// 多叉树的层序遍历并排序函数
void levelOrderTraversal_sort(BiTree* root) {
    if (root == NULL) {
        return;
    }
    
    Queue* queue = createQueue(); // 创建一个队列
    enqueue(queue, root); // 根节点入队
    
    while (!isQueueEmpty(queue)) {
        int levelSize = 0; // 记录当前层的节点数量
        QueueNode* current = queue->front;
        
        // 计算当前层的节点数量
        while (current != NULL) {
            levelSize++;
            current = current->next;
        }
        
        int* levelValues = (int*)malloc(levelSize * sizeof(int)); // 存储当前层的节点值
        int index = 0;
        
        // 处理当前层的所有节点
        for (int i = 0; i < levelSize; i++) {
            BiTree* currentNode = dequeue(queue); // 获取队首节点
            levelValues[index++] = currentNode->val; // 存储节点值
            
            // 将当前节点的所有孩子入队
            for (int j = 0; j < currentNode->numChild; j++) {
                if (currentNode->child[j] != NULL) {
                    enqueue(queue, currentNode->child[j]);
                }
            }
        }
        
        // 对当前层的节点值进行排序
        qsort(levelValues, levelSize, sizeof(int), compare);
        
        // 输出当前层的节点值
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", levelValues[i]);
        }
        printf("\n");
        
        free(levelValues); // 释放存储当前层节点值的数组
    }
}
//计算多叉树的结点总数
int countNodes(BiTree* root) {
    if (root == NULL) {
        return 0;
    }
    int count = 1; // 计算当前结点
    for (int i = 0; i < root->numChild; ++i) {
        count += countNodes(root->child[i]); // 递归计算孩子的结点数
    }

    return count;
}
//计算多叉树叶结点总数
int countLeaves(BiTree *root){
    if(root==NULL)return 0;
    if(root->numChild==0)return 1;
    int count=0;
    for(int i=0;i<root->numChild;i++){
        count+=countLeaves(root->child[i]);
    }
    return count;
}
void preTree(BiTree *p){
    if(p==NULL)return;
    printf("%d ",p->val);
    for(int i=0;i<p->numChild;i++){
        preTree(p->child[i]);
    }
}
int main() {
    // 创建一个示例树用于演示
    BiTree* root = createNode(1);
    root->child[0] = createNode(3);
    root->child[1] = createNode(2);
    root->numChild = 2;

    root->child[0]->child[0] = createNode(5);
    root->child[0]->child[1] = createNode(4);
    root->child[0]->numChild = 2;

    root->child[1]->child[0] = createNode(6);
    root->child[1]->numChild = 1;

    printf("层序遍历: ");
    levelOrderTraversal(root);
    printf("\n");
    preTree(root);
    printf("\n");
    levelOrderTraversal_sort(root);
    return 0;
}
