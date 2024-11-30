#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree {
    int val;
    struct BiTree *left;
    struct BiTree *right;
} BiTree;

// ����һ���µĽڵ�
BiTree* createNode(int val) {
    BiTree* node = (BiTree*)malloc(sizeof(BiTree));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// �ݹ鹹������������
BiTree* sortedArrayToBST(int* nums, int start, int end) {
    if (start > end) {
        return NULL;
    }

    // �м�Ԫ����Ϊ���ڵ�
    int mid = start + (end - start) / 2;
    BiTree* root = createNode(nums[mid]);

    // �ݹ鹹����������������
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

// ���������ӡ����������
void inOrderTraversal(BiTree* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}

// �ͷŶ��������ڴ�
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
// ������нڵ�ṹ
typedef struct QueueNode {
    BiTree *node;
    struct QueueNode *next;
} QueueNode;

// ���������нṹ
typedef struct LinkQueue {
    QueueNode *front;
    QueueNode *rear;
} LinkQueue;

// ��ʼ������
void initQueue(LinkQueue *Q) {
    Q->front = Q->rear = NULL;
}

// �������Ƿ�Ϊ��
int isEmptyQueue(LinkQueue *Q) {
    return Q->front == NULL;
}

// ��Ӳ���
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

// ���Ӳ���
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

// ��α��������㻻�У�ͬʱ��ʾÿ���ڵ���ӽڵ�ֵ
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

        // ����ǰ������нڵ������ʱ���У���ͳ�Ƶ�ǰ��ڵ���
        while (!isEmptyQueue(&Q)) {
            BiTree *temp = popQueue(&Q);
            printf("�ڵ�: %d", temp->val);
            if (temp->left) {
                printf(" ���ӽڵ�: %d", temp->left->val);
                pushQueue(&tempQueue, temp->left);
            } else {
                printf(" ���ӽڵ�: NULL");
            }
            if (temp->right) {
                printf(" ���ӽڵ�: %d", temp->right->val);
                pushQueue(&tempQueue, temp->right);
            } else {
                printf(" ���ӽڵ�: NULL");
            }
            printf(" | ");
        }
        printf("\n");

        // ����һ������нڵ����������
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

        // ����ǰ������нڵ������ʱ���У���ͳ�Ƶ�ǰ��ڵ���
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

        // ����һ������нڵ����������
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
