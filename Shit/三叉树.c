#include <stdio.h>
#include <stdlib.h>

// ˫��������ڵ�ṹ�嶨��
typedef struct BiTree {
    int val;
    struct BiTree *left;
    struct BiTree *right;
    struct BiTree *parent; // ָ�򸸽ڵ��ָ��
} BiTree;

// �����½ڵ�
BiTree* createNode(int value) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL; // ��ʼ�����ڵ�ָ��Ϊ NULL
    return newNode;
}

// ��������������Ԫ�غ���
BiTree* insertBST(BiTree* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->val) {
        root->left = insertBST(root->left, value);
        root->left->parent = root; // �������ӽڵ�ĸ��ڵ�ָ��
    } else if (value > root->val) {
        root->right = insertBST(root->right, value);
        root->right->parent = root; // �������ӽڵ�ĸ��ڵ�ָ��
    }
    return root;
}
//����Ԫ��
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

// ɾ��Ԫ��
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

//�������
void inorderTraversal(BiTree* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}
int main() {
    BiTree* root = NULL;

    // ����Ԫ��
    root = insertBST(root, 10);
    insertBST(root, 5);
    insertBST(root, 15);
    insertBST(root, 3);
    insertBST(root, 8);
    insertBST(root, 12);
    insertBST(root, 18);

    // ��ӡ�����Ķ���������
    printf("����������������������");
    inorderTraversal(root);
    printf("\n");
    return 0;
}
