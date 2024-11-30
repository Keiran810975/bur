#include <stdio.h>
#include <stdlib.h>

// 定义哈夫曼树节点结构
typedef struct HuffmanNode {
    int weight;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

// 定义小根堆结构
typedef struct MinHeap {
    int size;
    int capacity;
    HuffmanNode **array;
} MinHeap;

// 创建一个新节点
HuffmanNode* newNode(int weight) {
    HuffmanNode* temp = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    temp->weight = weight;
    temp->left = temp->right = NULL;
    return temp;
}

// 创建一个小根堆
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (HuffmanNode**)malloc(minHeap->capacity * sizeof(HuffmanNode*));
    return minHeap;
}

// 交换两个哈夫曼树节点
void swapHuffmanNode(HuffmanNode** a, HuffmanNode** b) {
    HuffmanNode* t = *a;
    *a = *b;
    *b = t;
}

// 堆调整函数
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

// 检查小根堆是否有一个元素
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// 提取堆中最小值
HuffmanNode* extractMin(MinHeap* minHeap) {
    HuffmanNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// 向小根堆插入一个节点
void insertMinHeap(MinHeap* minHeap, HuffmanNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->weight < minHeap->array[(i - 1) / 2]->weight) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// 构建小根堆
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// 创建并构建一个小根堆
MinHeap* createAndBuildMinHeap(int weights[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(weights[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// 构建哈夫曼树
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

// 计算带权路径长度（WPL）
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
// 定义队列节点结构
typedef struct QueueNode {
    HuffmanNode *node;
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
// 出队操作
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
// 层序遍历并按层换行
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

        // 将当前层的所有节点加入临时队列，并统计当前层节点数
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
        // 将下一层的所有节点加入主队列
        while (!isEmptyQueue(&tempQueue)) {
            pushQueue(&Q, popQueue(&tempQueue));
        }
    }
}
// 层序遍历并按层换行，同时显示每个节点的子节点值
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

        // 将当前层的所有节点加入临时队列，并统计当前层节点数
        while (!isEmptyQueue(&Q)) {
            HuffmanNode *temp = popQueue(&Q);
            printf("节点: %d", temp->weight);
            if (temp->left) {
                printf(" 左子节点: %d", temp->left->weight);
                pushQueue(&tempQueue, temp->left);
            } else {
                printf(" 左子节点: NULL");
            }
            if (temp->right) {
                printf(" 右子节点: %d", temp->right->weight);
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
// 主函数：构建哈夫曼树并计算带权路径长度
int main() {
    int weights[] = {3,9,6,2,5};
    int size = sizeof(weights) / sizeof(weights[0]);
    HuffmanNode* root = buildHuffmanTree(weights, size);
    int wpl = 0;
    calculateWPL(root, 0, &wpl);
    //prehuffman(root);
    levelOrderTraversal(root);
    printf("\n");
    printf("带权路径长度 (WPL) 是 %d\n", wpl);
    return 0;
}
