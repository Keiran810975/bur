#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#define MAX 100
typedef struct BiTree{
    int val;
    struct BiTree *left;
    struct BiTree *right;
}BiTree;
typedef struct{
    BiTree* data[MAX];
    int top;
}stack;
//��ʼ��ջ
stack init(stack *p){     //��ջ�յ�ʱ�� ��ʼ��ջ��ָ��Ϊ-1
    p->top=-1;
}

//�ж�ջ�Ƿ�Ϊ��
int isempty(stack *p){
    return p->top==-1;  //******
}

//�ж�ջ�Ƿ���
int isfull(stack *p){
    return p->top==MAX-1;
}

//����ջԪ��(pop)
BiTree* pop(stack *p){
    if(isempty(p)){
        printf("ջΪ��\n");
        return NULL;
    }
    BiTree* val=p->data[p->top];
    p->top--;
    return val;
}

//����ջԪ��
void push(stack *p,BiTree *new){
    if(isfull(p)){
        printf("����Ԫ��ʧ��\n");
        return;
    }
    p->top+=1;
    p->data[p->top]=new; 
}

//��ȡջ��Ԫ�ص�ֵ
BiTree* gettop(stack *p){
    if(isempty(p)){
        printf("��ȡʧ��\n");
        return NULL;
    }
    return p->data[p->top];
}

//�����½��
BiTree* createNode(int val) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
    return newNode;
}

//������������(���Ƕ���������)
void insertNode(BiTree* root, int target, int newVal) {
    if (root == NULL)
        return;
    if (root->val == target) {
        // ��Ŀ��ڵ������½ڵ�
        BiTree* newNode = createNode(newVal);
        //newNode->left = root->right;
        root->right = newNode;
    } else {
        // �ݹ����Ŀ��ڵ�
        insertNode(root->left, target, newVal);
        insertNode(root->right, target, newVal);
    }
}

//����������,�����������õ���С���������
//�ڶ����������в���Ԫ��
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

//�ڶ����������в���Ԫ��(���ص�ַ)
BiTree *bstSearch(BiTree *p,int data){
    if(p==NULL)return NULL;//����
    if(data==p->val)return p;
    if(data>p->val)return bstSearch(p->right,data);
    if(data<p->val)return bstSearch(p->left,data);
    return NULL;//û���ҵ�
}

//ɾ�������������еĽ��
BiTree *bstDelete(BiTree *p,int data){
    if(p==NULL)return NULL;//����
    if(data<p->val){
        bstDelete(p->left,data);
        return p;
    }else if(data>p->val){
        bstDelete(p->right,data);
        return p;
    }else if(data==p->val){
        if(p->left==NULL&&p->right==NULL){
            BiTree *temp=p;
            free(p);
            temp=NULL;
            return temp;
        }else if(p->left!=NULL&&p->right==NULL){
            BiTree *temp=p->left;
            free(p);
            return temp;
        }else if(p->left==NULL&&p->right!=NULL){
            BiTree *temp=p->right;
            free(p);
            return temp;
        }else if(p->left!=NULL&&p->right!=NULL){//��Ҫɾ��������������������������С������������??
            BiTree *cur=p->right;               //�����޸ĺ������������ɾ���Ľ��(������Ҳ??)
            while(cur->left!=NULL)cur=cur->left;             //�ҵ��������ϵ���С��??
            cur->left=p->left;
            BiTree *temp=p->right;
            free(p);
            return temp;
        }
    }
    return p;        //δ�ҵ�Ҫɾ���Ľ�??
}

//��α�������������
BiTree* searchByLevel(BiTree* root, int target) {
    if (root == NULL)
        return NULL;

    // �����������ڲ�α���
    BiTree* queue[1000]; // ����������ڵ�����������1000
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        BiTree* current = queue[front++];
        if (current->val == target) {
            return current; // �ҵ�Ŀ��ֵ�����ؽڵ�ָ��
        }
        // ����ǰ�ڵ�������ӽڵ�������
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
    return NULL; // δ�ҵ�Ŀ��ֵ
}

//�����������(�ݹ�)
void preTree(BiTree *p){
    if(p==NULL)return;
    printf("%d ",p->val);
    preTree(p->left);
    preTree(p->right);
}

//�������
void midTree(BiTree *p){
    if(p==NULL)return;
    midTree(p->left);
    printf("%d ",p->val);
    midTree(p->right);
}

//����(����ջ�ҷǵݹ�)
void morrisInOrderTraversal(BiTree *root) {
    BiTree *current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d ", current->val);  // ���ʽڵ�
            current = current->right;    // �����ƶ�
        } else {
            // �ҵ���ǰ�ڵ��ǰ���ڵ�
            BiTree *pre = current->left;
            while (pre->right != NULL && pre->right != current) {
                pre = pre->right;
            }
            // ���ǰ���ڵ���Һ���Ϊ�գ��������Һ���ָ��ǰ�ڵ�
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
            // ���ǰ���ڵ���Һ����ǵ�ǰ�ڵ㣬�������Һ��ӻָ�Ϊ��
            // ���ʵ�ǰ�ڵ㲢�����ƶ�
            else {
                pre->right = NULL;
                printf("%d ", current->val);  // ���ʽڵ�
                current = current->right;
            }
        }
    }
}

//�������
void postTree(BiTree *p){
    if(p==NULL)return;
    postTree(p->left);
    postTree(p->right);
    printf("%d ",p->val);
}

//�������(ջʵ��)
void preTreeStack(BiTree *p){
    stack *sss=(stack *)malloc(sizeof(stack));
    init(sss);
    push(sss,p);
    while(!isempty(sss)){
        BiTree *node=pop(sss);
        printf("%d ",node->val);
        if(node->right!=NULL)push(sss,node->right);
        if(node->left!=NULL)push(sss,node->left);
    }
}

//���򴴽�������?
void precreate(BiTree **p){
    int n;
    scanf("%d",&n);
    if(n==0){
        *p=NULL;
        return;
    }else{
        BiTree *newnode=(BiTree *)malloc(sizeof(BiTree));
        newnode->val=n;
        *p=newnode;
        precreate(&((*p)->left));
        precreate(&((*p)->right));
    }
}

//�������
void floorTree(BiTree *p){
    BiTree *tmp[100];
    int in=0;int out=0;
    tmp[in++]=p;
    while(in>out){
        if(tmp[out]){
            printf("%d ",tmp[out]->val);
            tmp[in++]=tmp[out]->left;
            tmp[in++]=tmp[out]->right;
        }
        out++;
    }
}

//�������
typedef struct{
    int head;
    int rear;
    BiTree data[100];
}LinkQueue;
int EmptyQueue (LinkQueue* Q){
	if (Q->head == Q->rear){
		return 0;
	}
	else{
		return 1;
	}
} 

void PushQueue (LinkQueue* Q, BiTree t){
	Q->rear = (Q->rear+1)%100;
	Q->data[Q->rear] = t;  
} 
void PopQueue (LinkQueue* Q){
	Q->head = (Q->head+1)%100;
}
void Leave (BiTree* t){
	LinkQueue Q;
	Q.head = 0;
	Q.rear = 0;
    BiTree* temp;    
	PushQueue (&Q, *t);
    while (EmptyQueue (&Q)){
		temp = &Q.data[Q.head+1];	
		printf ("%d ", temp->val);
		PopQueue (&Q);
        if (temp->left != NULL)   {
			PushQueue (&Q, *temp->left);
    	}   	
		if (temp->right != NULL){
			PushQueue (&Q, *temp->right);
		}	
	}		
}
//����(����汾)
// ������нڵ�ṹ��
typedef struct QueueNode {
    BiTree *treeNode;
    struct QueueNode *next;
    struct QueueNode *parent;
} QueueNode;
// ������нṹ��
typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;
// ��ʼ������
Queue* initQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
// �ж϶����Ƿ�Ϊ��
bool isEmpty(Queue *q) {
    return q->front == NULL;
}
// ��Ӳ���
void enqueue(Queue *q, BiTree *node) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
// ���Ӳ���
BiTree* dequeue(Queue *q) {
    if (isEmpty(q)) {
        return NULL;
    }
    QueueNode *temp = q->front;
    BiTree *node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return node;
}
// �ȽϺ�������������
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
// ��α��������ÿ���С����Ľڵ�ֵ
void levelOrderTraversal(BiTree *root) {
    if (root == NULL) {
        return;
    }
    Queue *q = initQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        int levelSize = 0;
        QueueNode *temp = q->front;
        while (temp != NULL) {
            levelSize++;
            temp = temp->next;
        }
        int *levelVals = (int*)malloc(levelSize * sizeof(int));
        for (int i = 0; i < levelSize; i++) {
            BiTree *node = dequeue(q);
            levelVals[i] = node->val;
            if (node->left) {
                enqueue(q, node->left);
            }
            if (node->right) {
                enqueue(q, node->right);
            }
        }

        qsort(levelVals, levelSize, sizeof(int), compare);
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", levelVals[i]);
        }
        printf("\n");
        free(levelVals);
    }
    free(q);
}
//����������һ��ֵ����������ʱ������·����ӡ����(dfs˳��)
int j;
int searchAndPrintPath(BiTree *root, int target,int path[]){
    if (root == NULL){
        return 0;
    }
    // ��ӡ��ǰ�ڵ��ֵ
    printf("%d ", root->val);
    path[j++]=root->val;
    if (root->val == target){
        return 1;
    }
    // ����������
    if (searchAndPrintPath(root->left, target,path)){
        return 1;
    }
    // ����������
    if (searchAndPrintPath(root->right, target,path)){
        return 1;
    }
    // �����ǰ·��û���ҵ�Ŀ��ֵ�������
    printf("Backtracking from %d\n", root->val);
    j--;
    return 0;
}
// ���ƶ�����
BiTree* copyTree(BiTree* root) {
    if (root == NULL) {
        return NULL;
    }

    // �����µĽڵ�
    BiTree* newRoot = createNode(root->val);

    // �ݹ鸴����������������
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);

    return newRoot;
}
int main(){
    int n;scanf("%d",&n);
    BiTree *sss=(BiTree *)malloc(sizeof(BiTree));
    // sss=NULL;
    while(n--){
        int t;scanf("%d",&t);
        bstInsert(&sss,t);
    }
    //preTreeStack(sss);
    //printf("\n");
    //midTreeStack(sss);
    // printf("%d\n",sss->val);
    //midTree(sss);
    // printf("\n");
    //floorTree(sss);
    //printf("\n");
    //Leave(sss);
     levelOrderTraversal(sss);
    // printf("\n");
    // int path[100];
    // searchAndPrintPath(sss,4,path);
    // printf("\n");
    // for(int i=0;i<j;i++)printf("%d ",path[i]);
    // printf("\n");
    // preTree(sss->left);
    // precreate(&sss);
    // preTree(sss);
    // printf("\n");
    // midTree(sss);
    // printf("\n");
    // postTree(sss);
    return 0;
}