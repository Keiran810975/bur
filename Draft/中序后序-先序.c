#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct TreeNode {
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// �����½ڵ�
TreeNode* createNode(char val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ͨ������������������������
TreeNode* buildTree(char* inorder, char* postorder, int inorderStart, int inorderEnd, int* postorderIndex) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // ������ǰ�ڵ�
    char current = postorder[*postorderIndex];
    (*postorderIndex)--;
    TreeNode* node = createNode(current);

    // ����˽ڵ�û���ӽڵ㣬���ؽڵ�
    if (inorderStart == inorderEnd) {
        return node;
    }

    // ������������ҵ���ǰ�ڵ������
    int inorderIndex;
    for (inorderIndex = inorderStart; inorderIndex <= inorderEnd; inorderIndex++) {
        if (inorder[inorderIndex] == current) {
            break;
        }
    }

    // �ݹ鹹����������������
    node->right = buildTree(inorder, postorder, inorderIndex + 1, inorderEnd, postorderIndex);
    node->left = buildTree(inorder, postorder, inorderStart, inorderIndex - 1, postorderIndex);

    return node;
}

// ǰ�����
void printPreorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printf("%c ", node->val);
    printPreorder(node->left);
    printPreorder(node->right);
}

// �������
void printInorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%c ", node->val);
    printInorder(node->right);
}

// �������
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
