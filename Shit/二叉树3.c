#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct BiTree {
    int val;
    struct BiTree *left;
    struct BiTree *right;
} BiTree;

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

// ������ʾ��
int main() {
    // ʾ��������������ʹ���ֶ���ʽ��ʵ�����Ӧ������������
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

    // ���ò�α��������㻻�к���
    levelOrderTraversal(root);

    // �ͷ��ڴ棨ʵ��Ӧ����Ӧ�ͷ����з�����ڴ棩
    free(root->left);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}
