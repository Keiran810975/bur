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

// ͨ��ǰ��������������������
TreeNode* buildTree(char* preorder, char* inorder, int inorderStart, int inorderEnd, int* preorderIndex) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // ������ǰ�ڵ�
    char current = preorder[*preorderIndex];
    (*preorderIndex)++;
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
    node->left = buildTree(preorder, inorder, inorderStart, inorderIndex - 1, preorderIndex);
    node->right = buildTree(preorder, inorder, inorderIndex + 1, inorderEnd, preorderIndex);

    return node;
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

// �������
void printInorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%c ", node->val);
    printInorder(node->right);
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

int main() {
    char preorder[] = {'A', 'B', 'D', 'C', 'E', 'F', 'G'};
    char inorder[] = {'D', 'B', 'C', 'A', 'F', 'E', 'G'};
    //char postorder[]={'D','E','B','F','G','C','A'};
    int preorderIndex = 0;
    //int postorderIndex = sizeof(postorder) / sizeof(postorder[0]) - 1;
    int len = sizeof(inorder) / sizeof(inorder[0]);

    TreeNode* root = buildTree(preorder, inorder, 0, len - 1, &preorderIndex);
    //TreeNode* root2 = buildTree2(inorder, postorder, 0, len - 1, &postorderIndex);
    printf("Inorder traversal: ");
    printInorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    printPreorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    printPostorder(root);
    printf("\n");

    // printf("Pre: ");
    // printPreorder(root2);
    // printf("\n");
    return 0;
}
