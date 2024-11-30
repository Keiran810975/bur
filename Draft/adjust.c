#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 10
typedef struct TreeNode { 
    int ID; //���ڵ�ı��
    struct TreeNode *child[MAX]; 
} Tree;
typedef struct Port { 
    int num; 
    int size;
} Port;
// ������ڵ�ṹ�嶨��
typedef struct BiTree {
    int val;//�ۿڱ��
    int left,right;//�����ǻ���
    struct BiTree* child[5]; // ������
    int numChild; // ��¼���ӵ�����
} BiTree;
typedef struct port{
    int id;
    int flow;
}port;
// �����½ڵ�
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
// ���ҽڵ�
BiTree* findNode(BiTree* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;

    for (int i = 0; i < root->numChild; i++) {
        BiTree* found = findNode(root->child[i], val);
        if (found != NULL) return found;
    }
    return NULL;
}

// ����Ԫ��
void insertElement(BiTree* root, int val, int newValue) {
    BiTree* targetNode = findNode(root, val);
    if (targetNode == NULL) {
        printf("�ڵ� %d ������\n", val);
        return;
    }
    // �½��ڵ�
    BiTree* newNode = createNode(newValue);
    // ���Ҳ���λ��
    int insertIndex = 0;
    while (insertIndex < targetNode->numChild && targetNode->child[insertIndex]->val < newValue) {
        insertIndex++;
    }
    // ���½ڵ���뵽��Ӧλ��
    for (int i = targetNode->numChild; i > insertIndex; --i) {
        targetNode->child[i] = targetNode->child[i - 1];
    }
    targetNode->child[insertIndex] = newNode;
    targetNode->numChild++;
}

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
int portUnsort[300];
int j=0;
// ������Ĳ����������
void levelOrderTraversal(BiTree* root) {
    if (root == NULL) {
        return;
    }
    Queue* queue = createQueue(); // ����һ������
    enqueue(queue, root); // ���ڵ����
    while (!isQueueEmpty(queue)) {
        BiTree* currentNode = dequeue(queue); // ��ȡ���׽ڵ�
        if(currentNode->left!=0)portUnsort[j++]=currentNode->left;
        if(currentNode->right!=0)portUnsort[j++]=currentNode->right;
        //printf("%d ", currentNode->val); // ��ӡ��ǰ�ڵ��ֵ
        
        // ����ǰ�ڵ�����к������
        for (int i = 0; i < currentNode->numChild; i++) {
            if (currentNode->child[i] != NULL) {
                enqueue(queue, currentNode->child[i]);
            }
        }
    }
    //printf("\n");
}
Tree node[2000];
int q[1000]; //q�����ǲ�α�����
int root, child;
int i, j, top = 0, num;
Tree *fff[200], *p;
void layerorder(Tree *t) 
{
    int front, rear;
    if (t != NULL) {
        fff[0] = t;
        front = -1, rear = 0;
        while (front < rear) //�����ﻹ��Ԫ��
        {
            p = fff[++front];
            if (p->child[0] == NULL && p->child[1] == NULL && p->child[2] == NULL) {
                q[top] = p->ID; //���²�α���
                top++;
            }
            for (i = 0; i <= 3; i++) {
                if (p->child[i] != NULL) // �������ǿ�
                {
                    fff[++rear] = p->child[i]; //����
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
//     if (a->size != b->size) return b->size - a->size; //������ 
//     else return a->ID - b->ID; //�ű�� 
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
