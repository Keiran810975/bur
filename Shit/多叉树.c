#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_CHILDREN 100
// 多叉树节点结构体定义
typedef struct BiTree {
    int val;
    struct BiTree* child[MAX_CHILDREN]; // 儿子们
    int numChild; // 记录儿子的数量
} BiTree;
// 创建新节点
BiTree* createNode(int value) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
    newNode->val = value;
    newNode->numChild = 0;
    for (int i = 0; i < MAX_CHILDREN; ++i) {
        newNode->child[i] = NULL;
    }
    return newNode;
}
// 查找节点
BiTree* findNode(BiTree* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;

    for (int i = 0; i < root->numChild; i++) {
        BiTree* found = findNode(root->child[i], val);
        if (found != NULL) return found;
    }
    return NULL;
}
//计算多叉树高度
int multiHeight(BiTree* root) {
    if (root == NULL) return 0;
    int maxChildHeight = 0;
    for (int i = 0; i < root->numChild; i++) {
        maxChildHeight = (maxChildHeight > multiHeight(root->child[i])) ? maxChildHeight : multiHeight(root->child[i]);
    }
    return maxChildHeight + 1;
}
// 计算节点在多叉树中的深度
int getDepth(BiTree* root, int target, int depth) {
    if (root == NULL) {
        return -1;  // 没有找到节点，返回-1
    }
    if (root->val == target) {
        return depth;  // 找到节点，返回当前深度
    }
    
    for (int i = 0; i < root->numChild; ++i) {
        int childDepth = getDepth(root->child[i], target, depth + 1);
        if (childDepth != -1) {
            return childDepth;  // 如果在子节点中找到目标节点，返回其深度
        }
    }
    return -1;  // 如果所有子节点中都没有找到目标节点，返回-1
}
// 插入元素
void insertElement(BiTree* root, int val, int newValue) {
    BiTree* targetNode = findNode(root, val);
    if (targetNode == NULL) {
        printf("节点 %d 不存在\n", val);
        return;
    }
    // 新建节点
    BiTree* newNode = createNode(newValue);
    // 查找插入位置
    int insertIndex = 0;
    while (insertIndex < targetNode->numChild && targetNode->child[insertIndex]->val < newValue) {
        insertIndex++;
    }
    // 将新节点插入到对应位置
    for (int i = targetNode->numChild; i > insertIndex; --i) {
        targetNode->child[i] = targetNode->child[i - 1];
    }
    targetNode->child[insertIndex] = newNode;
    targetNode->numChild++;
}
// 打印多叉树
void printTree(BiTree* root) {
    if (root == NULL) {
        return;
    }
    printf("%d -> ", root->val);
    for (int i = 0; i < root->numChild; ++i) {
        printf("%d ", root->child[i]->val);
    }
    printf("\n");
    for (int i = 0; i < root->numChild; ++i) {
        printTree(root->child[i]);
    }
}
//先序遍历
void preTree(BiTree *root){
    if(root==NULL)return;
    printf("%d ",root->val);
    for(int i=0;i<root->numChild;i++){
        preTree(root->child[i]);
    }
}
// 后序遍历多叉树
void postOrderTraversal(BiTree* root) {
    if (root == NULL) {
        return;
    }

    // 先遍历所有子节点
    for (int i = 0; i < root->numChild; i++) {
        postOrderTraversal(root->child[i]);
    }

    // 然后访问当前节点
    printf("%d ", root->val);
}
// 释放多叉树的内存
void freeTree(BiTree* root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < root->numChild; ++i) {
        freeTree(root->child[i]);
    }
    free(root);
}
//删除指定结点
void deleteNode(BiTree* root, int value) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < root->numChild; ++i) {
        if (root->child[i]->val == value) {
            // 找到要删除的节点，释放其内存
            freeTree(root->child[i]);
            // 将最后一个子节点移动到当前位置
            root->child[i] = root->child[root->numChild - 1];
            root->child[root->numChild - 1] = NULL;
            root->numChild--;
            return;
        }
    }
    // 递归删除子节点中的目标值
    for (int i = 0; i < root->numChild; ++i) {
        deleteNode(root->child[i], value);
    }
}

// 查找从节点到根的路径
int findPath(BiTree* root, BiTree* target, BiTree* path[], int* pathLength) {
    if (root == NULL) return 0;
    path[*pathLength] = root;
    (*pathLength)++;
    if (root == target) return 1;

    for (int i = 0; i < root->numChild; i++) {
        if (findPath(root->child[i], target, path, pathLength)) {
            return 1;
        }
    }

    (*pathLength)--;
    return 0;
}
//LCA函数(参数是结点)
BiTree* findLCA(BiTree* root, BiTree* n1, BiTree* n2) {
    BiTree* path1[100];
    BiTree* path2[100];
    int pathLength1 = 0, pathLength2 = 0;

    if (!findPath(root, n1, path1, &pathLength1) || !findPath(root, n2, path2, &pathLength2)) {
        return NULL; // 如果其中一个节点不在树中
    }

    int i;
    for (i = 0; i < pathLength1 && i < pathLength2; i++) {
        if (path1[i] != path2[i]) {
            break;
        }
    }
    return path1[i-1];
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&
//###########################
//找到从节点到根节点的路径
int findPath2(BiTree* root, BiTree* target, BiTree* path[], int* pathLength) {
    if (root == NULL) return 0;
    path[*pathLength] = root;
    (*pathLength)++;
    if (root == target) return 1;
    for (int i = 0; i < root->numChild; i++) {
        if (findPath2(root->child[i], target, path, pathLength)) {
            return 1;
        }
    }
    (*pathLength)--;
    return 0;
}
//LCA(参数是int)
BiTree* findLCA2(BiTree* root, int val1, int val2) {
    BiTree* n1 = findNode(root, val1);
    BiTree* n2 = findNode(root, val2);
    if (n1 == NULL || n2 == NULL) return NULL;
    BiTree* path1[100];
    BiTree* path2[100];
    int pathLength1 = 0, pathLength2 = 0;
    if (!findPath2(root, n1, path1, &pathLength1) || !findPath2(root, n2, path2, &pathLength2)) {
        return NULL; // 如果其中一个节点不在树中
    }
    int i;
    for (i = 0; i < pathLength1 && i < pathLength2; i++) {
        if (path1[i] != path2[i]) {
            break;
        }
    }
    return path1[i-1];
}
//辅助函数
int findDistanceFromLCA(BiTree* lca, int val) {
    if (lca == NULL) return -1;
    if (lca->val == val) return 0;

    int distance = -1;
    for (int i = 0; i < lca->numChild; i++) {
        int d = findDistanceFromLCA(lca->child[i], val);
        if (d != -1) {
            distance = d + 1;
            break;
        }
    }
    return distance;
}
//两个结点间距
int findDistance(BiTree* root, int val1, int val2) {
    BiTree* lca = findLCA2(root, val1, val2);
    if (lca == NULL) return -1;

    int d1 = findDistanceFromLCA(lca, val1);
    int d2 = findDistanceFromLCA(lca, val2);

    return d1 + d2;
}
//两结点之间的路径
void routineBetweenNodes(BiTree* root, int val1, int val2, int path[], int* pathLength) {
    BiTree* lca = findLCA2(root, val1, val2);
    if (lca == NULL) return;
    BiTree* path1[100];
    BiTree* path2[100];
    int pathLength1 = 0, pathLength2 = 0;
    findPath2(lca, findNode(root, val1), path1, &pathLength1);
    findPath2(lca, findNode(root, val2), path2, &pathLength2);
    // 添加path1的所有节点到结果路径中
    for (int i = 0; i < pathLength1; i++) {
        path[(*pathLength)++] = path1[i]->val;
    }
    // 添加path2的所有节点到结果路径中，但不包括LCA
    for (int i = pathLength2 - 1; i >= 0; i--) {
        if (path2[i] != lca) {
            path[(*pathLength)++] = path2[i]->val;
        }
    }
}
int main() {
    // BiTree* root = createNode(1);
    // insertElement(root, 1, 2);
    // insertElement(root, 1, 3);
    // insertElement(root, 3, 4);
    // insertElement(root, 3, 5);
    // insertElement(root, 4, 6);
    // deleteNode(root,5);
    // BiTree *p=findNode(root,3);
    // printf("$%d %d$\n",p->val,p->numChild);
    // printf("多叉树的结构：\n");
    // printTree(root);
    BiTree* root = createNode(1);

    BiTree* node2 = createNode(2);
    BiTree* node3 = createNode(3);
    BiTree* node4 = createNode(4);
    BiTree* node5 = createNode(5);
    BiTree* node6 = createNode(6);
    BiTree* node7 = createNode(7);

    root->child[root->numChild++] = node2;
    root->child[root->numChild++] = node3;

    node2->child[node2->numChild++] = node4;
    node2->child[node2->numChild++] = node5;

    node3->child[node3->numChild++] = node6;
    node3->child[node3->numChild++] = node7;

    int val1 = 4;
    int val2 = 7;
    BiTree* lca = findLCA2(root, val1, val2);
    if (lca != NULL) {
        printf("LCA of %d and %d is %d\n", val1, val2, lca->val);
    } else {
        printf("LCA not found\n");
    }
    int distance = findDistance(root, val1, val2);
    if (distance != -1) {
        printf("Distance between %d and %d is %d\n", val1, val2, distance);
    } else {
        printf("Nodes not found or not in the same tree\n");
    }
    printf("\n_______________\n");
    printTree(root);
    printf("\n");
    postOrderTraversal(root);
    return 0;
}
