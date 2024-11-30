#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// 定义二叉树结构体
typedef struct BiTree {
    int val;
    struct BiTree *left;
    struct BiTree *right;
} BiTree;

// 定义队列节点结构体
typedef struct QueueNode {
    BiTree *treeNode;
    struct QueueNode *next;
    struct QueueNode *parent;
} QueueNode;
// 定义队列结构体
typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;
// 创建一个新节点
BiTree* createNode(int val) {
    BiTree *newNode = (BiTree*)malloc(sizeof(BiTree));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// 初始化队列
Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
// 判断队列是否为空
int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}
// 入队操作
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
// 出队操作
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
// 打印路径
void printPath(QueueNode *node) {
    if (node == NULL) {
        return;
    }
    printPath(node->parent);
    printf("%d ", node->treeNode->val);
}
// 搜索一个值并打印出搜索路径（按照层次遍历顺序）
void searchAndPrintPathLevel(BiTree *root, int target) {
    if (root == NULL) {
        return;
    }
    Queue *queue = createQueue();
    enqueue(queue, root, NULL);
    while (!isQueueEmpty(queue)) {
        QueueNode *current = dequeue(queue);
        // 打印当前节点的值
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
    if(*p==NULL){                      //空数的情况
        *p=createNode(data);
        // BiTree *newnode=(BiTree *)malloc(sizeof(BiTree));
        // newnode->val=data;
        // newnode->left=NULL;
        // newnode->right=NULL;
        //*p=newnode;
        return;
    }
    if(data>(*p)->val){            //不是空树的情况
        bstInsert(&((*p)->right),data);
    }else if(data<(*p)->val){
        bstInsert(&((*p)->left),data);
    }
}
//计算二叉树高度
int treeHeight(BiTree* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}
// 计算节点在二叉树中的深度
int getDepth(BiTree* root, int target, int depth) {
    if (root == NULL) {
        return -1;  // 没有找到节点，返回-1
    }
    if (root->val == target) {
        return depth;  // 找到节点，返回当前深度
    }
    
    // 递归搜索左子树
    int leftDepth = getDepth(root->left, target, depth + 1);
    if (leftDepth != -1) {
        return leftDepth;  // 如果左子树中找到目标节点，返回其深度
    }
    
    // 递归搜索右子树
    return getDepth(root->right, target, depth + 1);
}
//计算二叉树结点总数
int countNodes(BiTree* root) {
    if (root == NULL) {
        return 0;
    } else {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}
//计算二叉树总叶结点数
int countLeaves(BiTree *root){
    if(root==NULL)return 0;
    else{
        if(root->left==NULL&&root->right==NULL)return 1;
        else return countLeaves(root->left)+countLeaves(root->right);
    }
}
//二叉树的镜像
void mirrorTree(BiTree *root){
    if(root==NULL)return;
    BiTree *temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}
// 查找指定节点的父节点
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
// 判断二叉树是否为完全二叉树
bool isCompleteBinaryTree(BiTree* root) {
    if (root == NULL) {
        return true;
    }
    bool isLastLevel = false;
    BiTree* queue[100]; // 假设树的节点不超过100个
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
// 查找LCA函数:两个节点的最近公共祖先(Lowest Common Ancestor, LCA)
BiTree* LCA(BiTree* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->val == n1 || root->val == n2) return root;
    BiTree* left_lca = LCA(root->left, n1, n2);
    BiTree* right_lca = LCA(root->right, n1, n2);
    if (left_lca && right_lca) return root;
    return (left_lca != NULL) ? left_lca : right_lca;
}
// 计算从某节点到目标节点的距离
int DistanceFromLCA(BiTree* root, int val, int distance) {
    if (root == NULL) return -1;
    if (root->val == val) return distance;

    int left_distance = DistanceFromLCA(root->left, val, distance + 1);
    if (left_distance != -1) return left_distance;

    return DistanceFromLCA(root->right, val, distance + 1);
}

// 计算两个节点之间的距离
int nodeDistance(BiTree* root, int n1, int n2) {
    BiTree* lca = LCA(root, n1, n2);
    if (lca == NULL) return -1;
    int d1 = DistanceFromLCA(lca, n1, 0);
    int d2 = DistanceFromLCA(lca, n2, 0);
    return d1 + d2;
}
//找结点
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
// int path[100]; // 保存路径节点值的数组
// int pathIndex = 0; // 路径数组的索引
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
// //找到两结点之间的路径
// void routineBetweenNodes(BiTree* root, int val1, int val2,int Path[]) {
//     pathIndex = 0;
//     // 查找值为 val1 的节点的路径
//     findPathUtil(root, val1, Path, 0);
//     // 将值为 val2 的节点添加到路径数组中
//     findPathUtil(root, val2, Path, pathIndex);
// }
// 辅助函数，用于找到从根节点到目标节点的路径
int findPath(BiTree *root, int target, int path[], int *pathLength) {
    if (root == NULL) {
        return 0;
    }
    // 将当前节点的值添加到路径中
    path[*pathLength] = root->val;
    (*pathLength)++;
    // 检查当前节点是否为目标节点
    if (root->val == target) {
        return 1;
    }
    // 检查目标节点是否在左子树或右子树中
    if ((root->left && findPath(root->left, target, path, pathLength)) ||
        (root->right && findPath(root->right, target, path, pathLength))) {
        return 1;
    }
    // 如果目标节点不在左右子树中，从路径中移除当前节点的值
    (*pathLength)--;
    return 0;
}
// 函数用于找到两个节点之间的路径
void findPathBetweenNodes(BiTree *root, int start, int end) {
    int path1[100];
    int path2[100];
    int pathLength1 = 0, pathLength2 = 0;
    // 找到从根节点到起始节点的路径
    if (!findPath(root, start, path1, &pathLength1)) {
        printf("起始节点不在树中。\n");
        return;
    }
    // 找到从根节点到目标节点的路径
    if (!findPath(root, end, path2, &pathLength2)) {
        printf("目标节点不在树中。\n");
        return;
    } 
    // 找到公共路径的长度
    int i = 0;
    while (i < pathLength1 && i < pathLength2 && path1[i] == path2[i]) {
        i++;
    }
    i--;
    // 打印从起始节点到公共祖先节点的路径
    for (int j = pathLength1 - 1; j >= i; j--) {
        printf("%d ", path1[j]);
    }
    // 打印从公共祖先节点到目标节点的路径
    for (int j = i+1; j < pathLength2; j++) {
        printf("%d ", path2[j]);
    }
    printf("\n");
}
int main() {
    // 创建一个示例二叉树
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