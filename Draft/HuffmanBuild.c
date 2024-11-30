#include <stdio.h>
#include <stdlib.h>

// ������������ڵ�ṹ
typedef struct HuffmanNode {
    int weight;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

// ����С���ѽṹ
typedef struct MinHeap {
    int size;
    int capacity;
    HuffmanNode **array;
} MinHeap;

// ����һ���½ڵ�
HuffmanNode* newNode(int weight) {
    HuffmanNode* temp = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    temp->weight = weight;
    temp->left = temp->right = NULL;
    return temp;
}

// ����һ��С����
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (HuffmanNode**)malloc(minHeap->capacity * sizeof(HuffmanNode*));
    return minHeap;
}

// �����������������ڵ�
void swapHuffmanNode(HuffmanNode** a, HuffmanNode** b) {
    HuffmanNode* t = *a;
    *a = *b;
    *b = t;
}

// �ѵ�������
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->weight < minHeap->array[smallest]->weight)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->weight < minHeap->array[smallest]->weight)
        smallest = right;

    if (smallest != idx) {
        swapHuffmanNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// ���С�����Ƿ���һ��Ԫ��
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// ��ȡ������Сֵ
HuffmanNode* extractMin(MinHeap* minHeap) {
    HuffmanNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// ��С���Ѳ���һ���ڵ�
void insertMinHeap(MinHeap* minHeap, HuffmanNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->weight < minHeap->array[(i - 1) / 2]->weight) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// ����С����
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// ����������һ��С����
MinHeap* createAndBuildMinHeap(int weights[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(weights[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// ������������
HuffmanNode* buildHuffmanTree(int weights[], int size) {
    HuffmanNode *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(weights, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode(left->weight + right->weight);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// �����Ȩ·�����ȣ�WPL��
void calculateWPL(HuffmanNode* root, int depth, int* wpl) {
    if (!root)
        return;
    if (!root->left && !root->right) {
        *wpl += root->weight * depth;
    }
    calculateWPL(root->left, depth + 1, wpl);
    calculateWPL(root->right, depth + 1, wpl);
}
void prehuffman(HuffmanNode *p){
    if(p==NULL)return;
    printf("%d ",p->weight);
    prehuffman(p->left);
    prehuffman(p->right);
}
// ������нڵ�ṹ
typedef struct QueueNode {
    HuffmanNode *node;
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
void pushQueue(LinkQueue *Q, HuffmanNode *node) {
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
HuffmanNode *popQueue(LinkQueue *Q) {
    if (isEmptyQueue(Q)) {
        return NULL;
    }
    QueueNode *temp = Q->front;
    HuffmanNode *node = temp->node;
    Q->front = Q->front->next;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    free(temp);
    return node;
}
// ������������㻻��
void levelOrderTraversal(HuffmanNode *root) {
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
            HuffmanNode *temp = popQueue(&Q);
            printf("%d ", temp->weight);
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
// ������������㻻�У�ͬʱ��ʾÿ���ڵ���ӽڵ�ֵ
void levelOrderTraversal_Shit(HuffmanNode *root) {
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
            HuffmanNode *temp = popQueue(&Q);
            printf("�ڵ�: %d", temp->weight);
            if (temp->left) {
                printf(" ���ӽڵ�: %d", temp->left->weight);
                pushQueue(&tempQueue, temp->left);
            } else {
                printf(" ���ӽڵ�: NULL");
            }
            if (temp->right) {
                printf(" ���ӽڵ�: %d", temp->right->weight);
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
// ���������������������������Ȩ·������
int main() {
    int weights[] = {3,9,6,2,5};
    int size = sizeof(weights) / sizeof(weights[0]);
    HuffmanNode* root = buildHuffmanTree(weights, size);
    int wpl = 0;
    calculateWPL(root, 0, &wpl);
    //prehuffman(root);
    levelOrderTraversal(root);
    printf("\n");
    printf("��Ȩ·������ (WPL) �� %d\n", wpl);
    return 0;
}
