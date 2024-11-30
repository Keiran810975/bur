#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// �������ڵ����ӵ�е����������
#define MAX_CHILDREN 10

// �������ڵ�Ľṹ��
typedef struct BiTree {
    int val;
    struct BiTree* child[MAX_CHILDREN]; // ������
    int numChild; // ��¼���ӵ�����
} BiTree;
// ������нڵ�Ľṹ��
typedef struct QueueNode {
    BiTree* treeNode;
    struct QueueNode* next;
} QueueNode;
// ������еĽṹ��
typedef struct Queue {
    QueueNode* front; // ����
    QueueNode* rear;  // ��β
} Queue;

// ����һ���µ����ڵ�
BiTree* createNode(int val) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
    newNode->val = val;
    newNode->numChild = 0;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        newNode->child[i] = NULL;
    }
    return newNode;
}

// ����һ���µĶ��нڵ�
QueueNode* createQueueNode(BiTree* treeNode) {
    QueueNode* newQueueNode = (QueueNode*)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    return newQueueNode;
}

// ����һ���ն���
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}
// �������Ƿ�Ϊ��
bool isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

// �����ڵ����
void enqueue(Queue* queue, BiTree* treeNode) {
    QueueNode* newQueueNode = createQueueNode(treeNode);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newQueueNode;
        return;
    }
    queue->rear->next = newQueueNode;
    queue->rear = newQueueNode;
}

// �����ڵ����
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

// ������Ĳ����������
void levelOrderTraversal(BiTree* root) {
    if (root == NULL) {
        return;
    }
    Queue* queue = createQueue(); // ����һ������
    enqueue(queue, root); // ���ڵ����
    while (!isQueueEmpty(queue)) {
        BiTree* currentNode = dequeue(queue); // ��ȡ���׽ڵ�
        printf("%d ", currentNode->val); // ��ӡ��ǰ�ڵ��ֵ
        // ����ǰ�ڵ�����к������
        for (int i = 0; i < currentNode->numChild; i++) {
            if (currentNode->child[i] != NULL) {
                enqueue(queue, currentNode->child[i]);
            }
        }
    }
    printf("\n");
}

// �ȽϺ�����������
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
// ������Ĳ��������������
void levelOrderTraversal_sort(BiTree* root) {
    if (root == NULL) {
        return;
    }
    
    Queue* queue = createQueue(); // ����һ������
    enqueue(queue, root); // ���ڵ����
    
    while (!isQueueEmpty(queue)) {
        int levelSize = 0; // ��¼��ǰ��Ľڵ�����
        QueueNode* current = queue->front;
        
        // ���㵱ǰ��Ľڵ�����
        while (current != NULL) {
            levelSize++;
            current = current->next;
        }
        
        int* levelValues = (int*)malloc(levelSize * sizeof(int)); // �洢��ǰ��Ľڵ�ֵ
        int index = 0;
        
        // ����ǰ������нڵ�
        for (int i = 0; i < levelSize; i++) {
            BiTree* currentNode = dequeue(queue); // ��ȡ���׽ڵ�
            levelValues[index++] = currentNode->val; // �洢�ڵ�ֵ
            
            // ����ǰ�ڵ�����к������
            for (int j = 0; j < currentNode->numChild; j++) {
                if (currentNode->child[j] != NULL) {
                    enqueue(queue, currentNode->child[j]);
                }
            }
        }
        
        // �Ե�ǰ��Ľڵ�ֵ��������
        qsort(levelValues, levelSize, sizeof(int), compare);
        
        // �����ǰ��Ľڵ�ֵ
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", levelValues[i]);
        }
        printf("\n");
        
        free(levelValues); // �ͷŴ洢��ǰ��ڵ�ֵ������
    }
}
//���������Ľ������
int countNodes(BiTree* root) {
    if (root == NULL) {
        return 0;
    }
    int count = 1; // ���㵱ǰ���
    for (int i = 0; i < root->numChild; ++i) {
        count += countNodes(root->child[i]); // �ݹ���㺢�ӵĽ����
    }

    return count;
}
//��������Ҷ�������
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
    // ����һ��ʾ����������ʾ
    BiTree* root = createNode(1);
    root->child[0] = createNode(3);
    root->child[1] = createNode(2);
    root->numChild = 2;

    root->child[0]->child[0] = createNode(5);
    root->child[0]->child[1] = createNode(4);
    root->child[0]->numChild = 2;

    root->child[1]->child[0] = createNode(6);
    root->child[1]->numChild = 1;

    printf("�������: ");
    levelOrderTraversal(root);
    printf("\n");
    preTree(root);
    printf("\n");
    levelOrderTraversal_sort(root);
    return 0;
}
