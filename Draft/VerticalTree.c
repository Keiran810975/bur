#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
//垂序遍历
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

// 二叉树节点及其水平距离
typedef struct QueueNode {
    BiTree* node;
    int hd; // horizontal distance
    struct QueueNode* next;
} QueueNode;

// 队列结构体
typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

// 创建一个新的队列节点
QueueNode* newQueueNode(BiTree* node, int hd) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;
    return temp;
}

// 创建一个新的队列
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 入队操作
void enqueue(Queue* q, BiTree* node, int hd) {
    QueueNode* temp = newQueueNode(node, hd);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// 出队操作
QueueNode* dequeue(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return temp;
}

// 哈希表节点
typedef struct HashNode {
    int key;
    int value[100];
    int count;
    struct HashNode* next;
} HashNode;

// 哈希表
typedef struct HashMap {
    HashNode* table[1000];
} HashMap;

// 创建一个新的哈希表节点
HashNode* newHashNode(int key) {
    HashNode* temp = (HashNode*)malloc(sizeof(HashNode));
    temp->key = key;
    temp->count = 0;
    temp->next = NULL;
    return temp;
}

// 创建一个新的哈希表
HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    for (int i = 0; i < 1000; i++) {
        map->table[i] = NULL;
    }
    return map;
}

// 哈希函数
int hash(int key) {
    return (key + 500) % 1000;
}

// 插入键值对到哈希表
void insert(HashMap* map, int key, int value) {
    int h = hash(key);
    HashNode* node = map->table[h];
    while (node != NULL) {
        if (node->key == key) {
            node->value[node->count++] = value;
            return;
        }
        node = node->next;
    }
    node = newHashNode(key);
    node->value[node->count++] = value;
    node->next = map->table[h];
    map->table[h] = node;
}

// 获取哈希表中的所有键
int* getKeys(HashMap* map, int* size) {
    int* keys = (int*)malloc(1000 * sizeof(int));
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        HashNode* node = map->table[i];
        while (node != NULL) {
            keys[count++] = node->key;
            node = node->next;
        }
    }
    *size = count;
    return keys;
}

// 垂序遍历二叉树
void verticalOrderTraversal(BiTree* root) {
    if (root == NULL) {
        return;
    }

    Queue* q = createQueue();
    HashMap* map = createHashMap();

    enqueue(q, root, 0);

    while (q->front != NULL) {
        QueueNode* temp = dequeue(q);
        int hd = temp->hd;
        BiTree* node = temp->node;

        insert(map, hd, node->val);

        if (node->left != NULL) {
            enqueue(q, node->left, hd - 1);
        }
        if (node->right != NULL) {
            enqueue(q, node->right, hd + 1);
        }

        free(temp);
    }

    int size;
    int* keys = getKeys(map, &size);

    // 对键进行排序
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (keys[j] > keys[j + 1]) {
                int temp = keys[j];
                keys[j] = keys[j + 1];
                keys[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        int h = hash(keys[i]);
        HashNode* node = map->table[h];
        while (node != NULL) {
            if (node->key == keys[i]) {
                for (int j = 0; j < node->count; j++) {
                    printf("%d ", node->value[j]);
                }
            }
            node = node->next;
        }
    }

    free(keys);
}

int main() {
    // 创建一个示例二叉树
    BiTree* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Vertical Order Traversal of the tree: ");
    verticalOrderTraversal(root);
    printf("\n");

    // 释放二叉树的内存
    freeTree(root);
    return 0;
}
