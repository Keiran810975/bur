#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#define MAX 100
typedef struct info{
    char name[200];
    char parentname[200];
    int type;
    char date[200];
}info;
//������洢�ļ��Ľṹ��
typedef struct BiTree{
    info val;
    struct BiTree *child[100];//������
    int numChile;//��¼���ӵ�����
}BiTree;
//�����½��
BiTree* createNode(info val) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
        newNode->val = val;
        newNode->numChile=0;
        for(int i=0;i<100;i++){
            newNode->child[i]=NULL;
        }
    return newNode;
}
//������������(���Ƕ���������)
void insertNode(BiTree** root, info newVal) {
    if(strcmp(newVal.parentname,"-")==0){
        *root=createNode(newVal);
        return;
    }
    //if((*root)=NULL)return;
    if (strcmp((*root)->val.name,newVal.parentname)==0) { 
        // ��Ŀ��ڵ������½ڵ�
        BiTree* newNode = createNode(newVal);
        //newNode->child[] = root->right;
        (*root)->child[(*root)->numChile++]=newNode;
    } else {
        // �ݹ����Ŀ��ڵ�
        for(int i=0;i<(*root)->numChile;i++){
            insertNode(&((*root)->child[i]),newVal);
        }
    }
}
typedef struct {
    BiTree* node;
    char path[1000]; // ����·�����Ȳ�����1000
} QueueNode;
BiTree* searchByLevel(BiTree* root, char *target, char *path) {
    if (root == NULL)
        return NULL;

    // �����������ڲ�α���
    QueueNode queue[1000]; // ����������ڵ�����������1000
    int front = 0, rear = 0;

    // ��ʼ������
    queue[rear].node = root;
    strcpy(queue[rear].path, root->val.name);
    rear++;

    while (front < rear) {
        QueueNode current = queue[front++];
        BiTree* currentNode = current.node;
        strcpy(path, current.path);

        if (strcmp(target, currentNode->val.name) == 0) {
            return currentNode; // �ҵ�Ŀ��ֵ�����ؽڵ�ָ��
        }

        // ����ǰ�ڵ�Ķ��ӽڵ������У�����¼·��
        for (int i = 0; i < currentNode->numChile; i++) {
            if (currentNode->child[i]) {
                queue[rear].node = currentNode->child[i];
                snprintf(queue[rear].path, sizeof(queue[rear].path), "%s->%s", current.path, currentNode->child[i]->val.name);
                rear++;
            }
        }
    }

    return NULL; // δ�ҵ�Ŀ��ֵ
}
// //����α���˳������
// BiTree* searchByLevel(BiTree* root, char *target,char *path){
//     if (root == NULL)
//         return NULL;
//     // �����������ڲ�α���
//     BiTree* queue[1000]; // ����������ڵ�����������1000
//     int front = 0, rear = 0;
//     queue[rear++] = root;
    
//     //���ַ�����¼·��

//     while (front < rear) {
//         BiTree* current = queue[front++];
//         if (strcmp(target,current->val.name)==0) {
//             return current; // �ҵ�Ŀ��ֵ�����ؽڵ�ָ��
//         }
//         // ����ǰ�ڵ�������ӽڵ�������
//         for(int i=0;i<current->numChile;i++){
//             if(current->child[i])queue[rear++]=current->child[i];
//         }
//     }
//     return NULL; // δ�ҵ�Ŀ��ֵ
// }
//��������??--->�����������õ���С�������??
//�������
void preTree(BiTree *p){
    if(p==NULL)return;
    printf("%s\n",p->val.name);
    for(int i=0;i<p->numChile;i++){
        preTree(p->child[i]);
    }
}
int main(){
    BiTree *p=(BiTree*)malloc(sizeof(BiTree));
    FILE *op=fopen("files.txt","r");
    info temp;
    while(fscanf(op,"%s%s%d%s",temp.name,temp.parentname,&temp.type,temp.date)!=EOF){
        insertNode(&p,temp);
    }
    char path[200]={'\0'};
    char s[100];
    scanf("%s",s);
    searchByLevel(p,s,path);
    printf("%s\n",path);
    //preTree(p);
    return 0;
}