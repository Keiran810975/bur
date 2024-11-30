#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct BiTree {
    int val;
    struct BiTree *left;
    struct BiTree *right;
} BiTree;

// 定义队列节点结构
typedef struct QueueNode {
    BiTree *node;
    struct QueueNode *next;
} QueueNode;

// 定义链队列结构
typedef struct LinkQueue {
    QueueNode *front;
    QueueNode *rear;
} LinkQueue;

// 初始化队列
void initQueue(LinkQueue *Q) {
    Q->front = Q->rear = NULL;
}

// 检查队列是否为空
int isEmptyQueue(LinkQueue *Q) {
    return Q->front == NULL;
}

// 入队操作
void pushQueue(LinkQueue *Q, BiTree *node) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (isEmptyQueue(Q)) {
        Q->front = Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

// 出队操作
BiTree *popQueue(LinkQueue *Q) {
    if (isEmptyQueue(Q)) {
        return NULL;
    }
    QueueNode *temp = Q->front;
    BiTree *node = temp->node;
    Q->front = Q->front->next;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    free(temp);
    return node;
}

// 层次遍历并按层换行，同时显示每个节点的子节点值
void levelOrderTraversal_Shit(BiTree *root) {
    if (root == NULL) {
        return;
    }
    LinkQueue Q;
    initQueue(&Q);
    pushQueue(&Q, root);

    while (!isEmptyQueue(&Q)) {
        int levelSize = 0;
        LinkQueue tempQueue;
        initQueue(&tempQueue);

        // 将当前层的所有节点加入临时队列，并统计当前层节点数
        while (!isEmptyQueue(&Q)) {
            BiTree *temp = popQueue(&Q);
            printf("节点: %d", temp->val);
            if (temp->left) {
                printf(" 左子节点: %d", temp->left->val);
                pushQueue(&tempQueue, temp->left);
            } else {
                printf(" 左子节点: NULL");
            }
            if (temp->right) {
                printf(" 右子节点: %d", temp->right->val);
                pushQueue(&tempQueue, temp->right);
            } else {
                printf(" 右子节点: NULL");
            }
            printf(" | ");
        }
        printf("\n");

        // 将下一层的所有节点加入主队列
        while (!isEmptyQueue(&tempQueue)) {
            pushQueue(&Q, popQueue(&tempQueue));
        }
    }
}
void levelOrderTraversal(BiTree *root) {
    if (root == NULL) {
        return;
    }
    LinkQueue Q;
    initQueue(&Q);
    pushQueue(&Q, root);

    while (!isEmptyQueue(&Q)) {
        int levelSize = 0;
        LinkQueue tempQueue;
        initQueue(&tempQueue);

        // 将当前层的所有节点加入临时队列，并统计当前层节点数
        while (!isEmptyQueue(&Q)) {
            BiTree *temp = popQueue(&Q);
            printf("%d ", temp->val);
            if (temp->left != NULL) {
                pushQueue(&tempQueue, temp->left);
            }
            if (temp->right != NULL) {
                pushQueue(&tempQueue, temp->right);
            }
        }
        printf("\n");

        // 将下一层的所有节点加入主队列
        while (!isEmptyQueue(&tempQueue)) {
            pushQueue(&Q, popQueue(&tempQueue));
        }
    }
}

// 主函数示例
int main() {
    // 示例二叉树构建（使用手动方式，实际情况应构建二叉树）
    BiTree *root = (BiTree *)malloc(sizeof(BiTree));
    root->val = 1;
    root->left = (BiTree *)malloc(sizeof(BiTree));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (BiTree *)malloc(sizeof(BiTree));
    root->right->val = 3;
    root->right->left = (BiTree *)malloc(sizeof(BiTree));
    root->right->left->val = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = NULL;

    // 调用层次遍历并按层换行函数
    levelOrderTraversal(root);

    // 释放内存（实际应用中应释放所有分配的内存）
    free(root->left);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}
