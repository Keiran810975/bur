#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_CHILDREN 100
typedef struct file{
    char name[30];
    int shuxing;
    char date[30];
}file;
typedef struct BiTree {
    int val;//��λ���ı��
    file info;//�������ļ�/Ŀ¼
    struct BiTree* child[MAX_CHILDREN]; // ������
    int numChild; // ��¼���ӵ�����
} BiTree;
// �����½ڵ�
BiTree* createNode(int value) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
    newNode->val = value;
    newNode->numChild = 0;
    for (int i = 0; i < MAX_CHILDREN; ++i) {
        newNode->child[i] = NULL;
    }
    return newNode;
}
// ���������ַ��������������
BiTree* parseTree(const char* input, int* index) {
    if (input[*index] == '\0') {
        return NULL;
    }
    // ��ȡ�ڵ�ֵ
    int value = 0;
    while (input[*index] >= '0' && input[*index] <= '9') {
        value = value * 10 + (input[*index] - '0');
        (*index)++;
    }
    BiTree* root = createNode(value);
    // ������� '(' ���ʾ���ӽڵ�
    if (input[*index] == '(') {
        (*index)++; // ���� '('
        while (input[*index] != ')') {
            root->child[root->numChild] = parseTree(input, index);
            root->numChild++;
            if (input[*index] == ',') {
                (*index)++; // ���� ','
            }
        }
        (*index)++; // ���� ')'
    }
    return root;
}
// ��ӡ�����
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
// ���ҽڵ�
BiTree* findNode(BiTree* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;

    for (int i = 0; i < root->numChild; i++) {
        BiTree* found = findNode(root->child[i], val);
        if (found != NULL) return found;
    }
    return NULL;
}
void insertNewFile(BiTree *root,char *path){
        
}
int main(){
    char input[100];
    scanf("%s",input);
    //const char* input = "1(2(4),3(5(7,8,9),6))";
    int index = 0;
    BiTree* root = parseTree(input, &index);
    //printTree(root);
    int x;
    file new;
    while(scanf("%d%s%d%s",&x,new.name,&new.shuxing,new.date)!=EOF){
        BiTree *tar=findNode(root,x);
        tar->info=new;
    }
    //�ļ����������
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        char path[300];
        scanf("%s",path);
    }
    return 0;
}