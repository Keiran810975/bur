#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新节点
TreeNode* createNode(char val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 通过后序和中序遍历构建二叉树
TreeNode* buildTree(char* inorder, char* postorder, int inorderStart, int inorderEnd, int* postorderIndex) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // 创建当前节点
    char current = postorder[*postorderIndex];
    (*postorderIndex)--;
    TreeNode* node = createNode(current);

    // 如果此节点没有子节点，返回节点
    if (inorderStart == inorderEnd) {
        return node;
    }

    // 在中序遍历中找到当前节点的索引
    int inorderIndex;
    for (inorderIndex = inorderStart; inorderIndex <= inorderEnd; inorderIndex++) {
        if (inorder[inorderIndex] == current) {
            break;
        }
    }

    // 递归构建右子树和左子树
    node->right = buildTree(inorder, postorder, inorderIndex + 1, inorderEnd, postorderIndex);
    node->left = buildTree(inorder, postorder, inorderStart, inorderIndex - 1, postorderIndex);

    return node;
}

// 前序遍历
void printPreorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printf("%c ", node->val);
    printPreorder(node->left);
    printPreorder(node->right);
}

// 中序遍历
void printInorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%c ", node->val);
    printInorder(node->right);
}

// 后序遍历
void printPostorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%c ", node->val);
}

int main() {
    char inorder[] = {'D', 'B', 'E', 'A', 'F', 'C', 'G'};
    char postorder[] = {'D', 'E', 'B', 'F', 'G', 'C', 'A'};
    int postorderIndex = sizeof(postorder) / sizeof(postorder[0]) - 1;
    int len = sizeof(inorder) / sizeof(inorder[0]);

    TreeNode* root = buildTree(inorder, postorder, 0, len - 1, &postorderIndex);

    printf("Inorder traversal: ");
    printInorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    printPostorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    printPreorder(root);
    printf("\n");

    return 0;
}
