#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree {
    int val;
    struct BiTree *left;
    struct BiTree *right;
} BiTree;

// 创建一个新的节点
BiTree* createNode(int val) {
    BiTree* node = (BiTree*)malloc(sizeof(BiTree));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 递归构建二叉搜索树
BiTree* sortedArrayToBST(int* nums, int start, int end) {
    if (start > end) {
        return NULL;
    }

    // 中间元素作为根节点
    int mid = start + (end - start) / 2;
    BiTree* root = createNode(nums[mid]);

    // 递归构建左子树和右子树
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

// 中序遍历打印二叉搜索树
void inOrderTraversal(BiTree* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}

// 释放二叉树的内存
void freeTree(BiTree* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
void floorTree(BiTree *p){
    BiTree *tmp[100];
    int in=0;int out=0;
    tmp[in++]=p;
    while(in>out){
        if(tmp[out]){
            printf("%d ",tmp[out]->val);
            tmp[in++]=tmp[out]->left;
            tmp[in++]=tmp[out]->right;
        }
        out++;
    }
}
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
int main() {
    int nums[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int n = sizeof(nums) / sizeof(nums[0]);

    BiTree* root = sortedArrayToBST(nums, 0, n - 1);

    printf("In-order traversal of the constructed BST: ");
    //inOrderTraversal(root);
    levelOrderTraversal(root);
    printf("\n");

    freeTree(root);
    return 0;
}
