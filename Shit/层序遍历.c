#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ����������ڵ�ṹ��
typedef struct BiTree {
    int val;
    struct BiTree *left;
    struct BiTree *right;
} BiTree;
// ������нڵ�ṹ��
typedef struct QueueNode {
    BiTree *treeNode;
    struct QueueNode *next;
} QueueNode;
// ������нṹ��
typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;
// ��ʼ������
Queue* initQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
// �ж϶����Ƿ�Ϊ��
bool isEmpty(Queue *q) {
    return q->front == NULL;
}
// ��Ӳ���
void enqueue(Queue *q, BiTree *node) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
// ���Ӳ���
BiTree* dequeue(Queue *q) {
    if (isEmpty(q)) {
        return NULL;
    }
    QueueNode *temp = q->front;
    BiTree *node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return node;
}
// �ȽϺ�������������
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
// ��α��������ÿ���С����Ľڵ�ֵ
void levelOrderTraversal(BiTree *root) {
    if (root == NULL) {
        return;
    }
    Queue *q = initQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        int levelSize = 0;
        QueueNode *temp = q->front;
        while (temp != NULL) {
            levelSize++;
            temp = temp->next;
        }
        int *levelVals = (int*)malloc(levelSize * sizeof(int));
        for (int i = 0; i < levelSize; i++) {
            BiTree *node = dequeue(q);
            levelVals[i] = node->val;
            if (node->left) {
                enqueue(q, node->left);
            }
            if (node->right) {
                enqueue(q, node->right);
            }
        }

        qsort(levelVals, levelSize, sizeof(int), compare);
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", levelVals[i]);
        }
        printf("\n");
        free(levelVals);
    }
    free(q);
}

// ���Դ���
int main() {
    BiTree node1 = {3, NULL, NULL};
    BiTree node2 = {1, NULL, NULL};
    BiTree node3 = {4, NULL, NULL};
    BiTree node4 = {0, NULL, NULL};
    BiTree node5 = {2, NULL, NULL};
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;

    levelOrderTraversal(&node1);

    return 0;
}
