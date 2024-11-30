#include <stdio.h>
#include <stdlib.h>

// 双向二叉树节点结构体定义
typedef struct BiTree {
    int val;
    struct BiTree *left;
    struct BiTree *right;
    struct BiTree *parent; // 指向父节点的指针
} BiTree;

// 创建新节点
BiTree* createNode(int value) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL; // 初始化父节点指针为 NULL
    return newNode;
}

// 二叉搜索树插入元素函数
BiTree* insertBST(BiTree* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->val) {
        root->left = insertBST(root->left, value);
        root->left->parent = root; // 设置左子节点的父节点指针
    } else if (value > root->val) {
        root->right = insertBST(root->right, value);
        root->right->parent = root; // 设置右子节点的父节点指针
    }
    return root;
}
//搜索元素
BiTree* search(BiTree* root, int value) {
    if (root == NULL || root->val == value) {
        return root;
    }
    if (value < root->val) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// 删除元素
BiTree* deleteNode(BiTree* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->val) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->val) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            BiTree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BiTree* temp = root->left;
            free(root);
            return temp;
        }
        BiTree* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

//中序遍历
void inorderTraversal(BiTree* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}
int main() {
    BiTree* root = NULL;

    // 插入元素
    root = insertBST(root, 10);
    insertBST(root, 5);
    insertBST(root, 15);
    insertBST(root, 3);
    insertBST(root, 8);
    insertBST(root, 12);
    insertBST(root, 18);

    // 打印插入后的二叉搜索树
    printf("二叉搜索树中序遍历结果：");
    inorderTraversal(root);
    printf("\n");
    return 0;
}
