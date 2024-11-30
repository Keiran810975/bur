#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// ����������ṹ��
typedef struct BiTree {
    int val;
    struct BiTree *left;
    struct BiTree *right;
} BiTree;

// ������нڵ�ṹ��
typedef struct QueueNode {
    BiTree *treeNode;
    struct QueueNode *next;
    struct QueueNode *parent;
} QueueNode;
// ������нṹ��
typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;
// ����һ���½ڵ�
BiTree* createNode(int val) {
    BiTree *newNode = (BiTree*)malloc(sizeof(BiTree));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// ��ʼ������
Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}
// ��Ӳ���
void enqueue(Queue *queue, BiTree *treeNode, QueueNode *parent) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    newNode->parent = parent;
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
// ���Ӳ���
QueueNode* dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    QueueNode *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return temp;
}
// ��ӡ·��
void printPath(QueueNode *node) {
    if (node == NULL) {
        return;
    }
    printPath(node->parent);
    printf("%d ", node->treeNode->val);
}
// ����һ��ֵ����ӡ������·�������ղ�α���˳��
void searchAndPrintPathLevel(BiTree *root, int target) {
    if (root == NULL) {
        return;
    }
    Queue *queue = createQueue();
    enqueue(queue, root, NULL);
    while (!isQueueEmpty(queue)) {
        QueueNode *current = dequeue(queue);
        // ��ӡ��ǰ�ڵ��ֵ
        printf("%d ", current->treeNode->val);
        if (current->treeNode->val == target) {
            printf("\nPath to %d: ", target);
            printPath(current);
            printf("\n");
            return;
        }
        if (current->treeNode->left != NULL) {
            enqueue(queue, current->treeNode->left, current);
        }
        if (current->treeNode->right != NULL) {
            enqueue(queue, current->treeNode->right, current);
        }
    }
    printf("Value %d not found in the tree.\n", target);
}
void bstInsert(BiTree **p,int data){
    if(*p==NULL){                      //���������
        *p=createNode(data);
        // BiTree *newnode=(BiTree *)malloc(sizeof(BiTree));
        // newnode->val=data;
        // newnode->left=NULL;
        // newnode->right=NULL;
        //*p=newnode;
        return;
    }
    if(data>(*p)->val){            //���ǿ��������
        bstInsert(&((*p)->right),data);
    }else if(data<(*p)->val){
        bstInsert(&((*p)->left),data);
    }
}
//����������߶�
int treeHeight(BiTree* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}
// ����ڵ��ڶ������е����
int getDepth(BiTree* root, int target, int depth) {
    if (root == NULL) {
        return -1;  // û���ҵ��ڵ㣬����-1
    }
    if (root->val == target) {
        return depth;  // �ҵ��ڵ㣬���ص�ǰ���
    }
    
    // �ݹ�����������
    int leftDepth = getDepth(root->left, target, depth + 1);
    if (leftDepth != -1) {
        return leftDepth;  // ������������ҵ�Ŀ��ڵ㣬���������
    }
    
    // �ݹ�����������
    return getDepth(root->right, target, depth + 1);
}
//����������������
int countNodes(BiTree* root) {
    if (root == NULL) {
        return 0;
    } else {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}
//�����������Ҷ�����
int countLeaves(BiTree *root){
    if(root==NULL)return 0;
    else{
        if(root->left==NULL&&root->right==NULL)return 1;
        else return countLeaves(root->left)+countLeaves(root->right);
    }
}
//�������ľ���
void mirrorTree(BiTree *root){
    if(root==NULL)return;
    BiTree *temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}
// ����ָ���ڵ�ĸ��ڵ�
BiTree* findParentNode(BiTree* root, int target) {
    if (root == NULL || (root->left != NULL && root->left->val == target) || (root->right != NULL && root->right->val == target)) {
        return root;
    }
    BiTree* leftParent = findParentNode(root->left, target);
    if (leftParent != NULL) {
        return leftParent;
    }
    return findParentNode(root->right, target);
}
// �ж϶������Ƿ�Ϊ��ȫ������
bool isCompleteBinaryTree(BiTree* root) {
    if (root == NULL) {
        return true;
    }
    bool isLastLevel = false;
    BiTree* queue[100]; // �������Ľڵ㲻����100��
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        BiTree* currentNode = queue[front++];
        if (currentNode == NULL) {
            isLastLevel = true;
        } else {
            if (isLastLevel) {
                return false;
            }
            queue[rear++] = currentNode->left;
            queue[rear++] = currentNode->right;
        }
    }
    return true;
}
// ����LCA����:�����ڵ�������������(Lowest Common Ancestor, LCA)
BiTree* LCA(BiTree* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->val == n1 || root->val == n2) return root;
    BiTree* left_lca = LCA(root->left, n1, n2);
    BiTree* right_lca = LCA(root->right, n1, n2);
    if (left_lca && right_lca) return root;
    return (left_lca != NULL) ? left_lca : right_lca;
}
// �����ĳ�ڵ㵽Ŀ��ڵ�ľ���
int DistanceFromLCA(BiTree* root, int val, int distance) {
    if (root == NULL) return -1;
    if (root->val == val) return distance;

    int left_distance = DistanceFromLCA(root->left, val, distance + 1);
    if (left_distance != -1) return left_distance;

    return DistanceFromLCA(root->right, val, distance + 1);
}

// ���������ڵ�֮��ľ���
int nodeDistance(BiTree* root, int n1, int n2) {
    BiTree* lca = LCA(root, n1, n2);
    if (lca == NULL) return -1;
    int d1 = DistanceFromLCA(lca, n1, 0);
    int d2 = DistanceFromLCA(lca, n2, 0);
    return d1 + d2;
}
//�ҽ��
BiTree* searchNode(BiTree* root, int target) {
    if (root == NULL || root->val == target) {
        return root;
    }
    
    BiTree* leftResult = searchNode(root->left, target);
    BiTree* rightResult = searchNode(root->right, target);
    
    if (leftResult != NULL) {
        return leftResult;
    } else {
        return rightResult;
    }
}
// int path[100]; // ����·���ڵ�ֵ������
// int pathIndex = 0; // ·�����������
// void findPathUtil(BiTree* root, int target, int tempPath[], int index) {
//     if (root == NULL) {
//         return;
//     }
//     tempPath[index] = root->val;
//     index++;
//     if (root->val == target) {
//         for (int i = 0; i < index; i++) {
//             path[pathIndex++] = tempPath[i];
//         }
//         return;
//     }
//     findPathUtil(root->left, target, tempPath, index);
//     findPathUtil(root->right, target, tempPath, index);
// }
// //�ҵ������֮���·��
// void routineBetweenNodes(BiTree* root, int val1, int val2,int Path[]) {
//     pathIndex = 0;
//     // ����ֵΪ val1 �Ľڵ��·��
//     findPathUtil(root, val1, Path, 0);
//     // ��ֵΪ val2 �Ľڵ���ӵ�·��������
//     findPathUtil(root, val2, Path, pathIndex);
// }
// ���������������ҵ��Ӹ��ڵ㵽Ŀ��ڵ��·��
int findPath(BiTree *root, int target, int path[], int *pathLength) {
    if (root == NULL) {
        return 0;
    }
    // ����ǰ�ڵ��ֵ��ӵ�·����
    path[*pathLength] = root->val;
    (*pathLength)++;
    // ��鵱ǰ�ڵ��Ƿ�ΪĿ��ڵ�
    if (root->val == target) {
        return 1;
    }
    // ���Ŀ��ڵ��Ƿ�������������������
    if ((root->left && findPath(root->left, target, path, pathLength)) ||
        (root->right && findPath(root->right, target, path, pathLength))) {
        return 1;
    }
    // ���Ŀ��ڵ㲻�����������У���·�����Ƴ���ǰ�ڵ��ֵ
    (*pathLength)--;
    return 0;
}
// ���������ҵ������ڵ�֮���·��
void findPathBetweenNodes(BiTree *root, int start, int end) {
    int path1[100];
    int path2[100];
    int pathLength1 = 0, pathLength2 = 0;
    // �ҵ��Ӹ��ڵ㵽��ʼ�ڵ��·��
    if (!findPath(root, start, path1, &pathLength1)) {
        printf("��ʼ�ڵ㲻�����С�\n");
        return;
    }
    // �ҵ��Ӹ��ڵ㵽Ŀ��ڵ��·��
    if (!findPath(root, end, path2, &pathLength2)) {
        printf("Ŀ��ڵ㲻�����С�\n");
        return;
    } 
    // �ҵ�����·���ĳ���
    int i = 0;
    while (i < pathLength1 && i < pathLength2 && path1[i] == path2[i]) {
        i++;
    }
    i--;
    // ��ӡ����ʼ�ڵ㵽�������Ƚڵ��·��
    for (int j = pathLength1 - 1; j >= i; j--) {
        printf("%d ", path1[j]);
    }
    // ��ӡ�ӹ������Ƚڵ㵽Ŀ��ڵ��·��
    for (int j = i+1; j < pathLength2; j++) {
        printf("%d ", path2[j]);
    }
    printf("\n");
}
int main() {
    // ����һ��ʾ��������
    //int n;scanf("%d",&n);
    BiTree *sss=(BiTree *)malloc(sizeof(BiTree));
    sss=NULL;
    // while(n--){
    //     int t;scanf("%d",&t);
    //     bstInsert(&sss,t);
    // }
    bstInsert(&sss,7);
    bstInsert(&sss,2);
    bstInsert(&sss,3);
    bstInsert(&sss,4);
    bstInsert(&sss,1);
    bstInsert(&sss,9);
    bstInsert(&sss,10);
    bstInsert(&sss,8);
    bstInsert(&sss,12);
    int target = 5;
    printf("Search path for %d:\n", target);
    searchAndPrintPathLevel(sss, target);
    printf("%d\n%d\n",treeHeight(sss),countNodes(sss));
    printf("%d\n",findParentNode(sss,4)->val);
    printf("$$%d$$\n",LCA(sss,1,4)->val);
    findPathBetweenNodes(sss,1,4);
    return 0;
}