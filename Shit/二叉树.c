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
//初始化栈
stack init(stack *p){     //当栈空的时候 初始化栈顶指针为-1
    p->top=-1;
}

//判断栈是否为空
int isempty(stack *p){
    return p->top==-1;  //******
}

//判断栈是否满
int isfull(stack *p){
    return p->top==MAX-1;
}

//弹出栈元素(pop)
BiTree* pop(stack *p){
    if(isempty(p)){
        printf("栈为空\n");
        return NULL;
    }
    BiTree* val=p->data[p->top];
    p->top--;
    return val;
}

//插入栈元素
void push(stack *p,BiTree *new){
    if(isfull(p)){
        printf("插入元素失败\n");
        return;
    }
    p->top+=1;
    p->data[p->top]=new; 
}

//获取栈顶元素的值
BiTree* gettop(stack *p){
    if(isempty(p)){
        printf("获取失败\n");
        return NULL;
    }
    return p->data[p->top];
}

//创建新结点
BiTree* createNode(int val) {
    BiTree* newNode = (BiTree*)malloc(sizeof(BiTree));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
    return newNode;
}

//暴力搜索插入(不是二叉排序树)
void insertNode(BiTree* root, int target, int newVal) {
    if (root == NULL)
        return;
    if (root->val == target) {
        // 在目标节点后插入新节点
        BiTree* newNode = createNode(newVal);
        //newNode->left = root->right;
        root->right = newNode;
    } else {
        // 递归查找目标节点
        insertNode(root->left, target, newVal);
        insertNode(root->right, target, newVal);
    }
}

//二叉搜索树,用中序遍历会得到从小到大的排列
//在二叉搜索树中插入元素
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

//在二叉搜索树中查找元素(返回地址)
BiTree *bstSearch(BiTree *p,int data){
    if(p==NULL)return NULL;//空树
    if(data==p->val)return p;
    if(data>p->val)return bstSearch(p->right,data);
    if(data<p->val)return bstSearch(p->left,data);
    return NULL;//没有找到
}

//删除二叉搜索树中的结点
BiTree *bstDelete(BiTree *p,int data){
    if(p==NULL)return NULL;//空树
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
        }else if(p->left!=NULL&&p->right!=NULL){//让要删除结点的左子树都放在右子树最小结点的左子树上??
            BiTree *cur=p->right;               //并让修改后的右子树代替删除的结点(反过来也??)
            while(cur->left!=NULL)cur=cur->left;             //找到右子树上的最小结??
            cur->left=p->left;
            BiTree *temp=p->right;
            free(p);
            return temp;
        }
    }
    return p;        //未找到要删除的结??
}

//层次遍历搜索二叉树
BiTree* searchByLevel(BiTree* root, int target) {
    if (root == NULL)
        return NULL;

    // 创建队列用于层次遍历
    BiTree* queue[1000]; // 假设二叉树节点数量不超过1000
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        BiTree* current = queue[front++];
        if (current->val == target) {
            return current; // 找到目标值，返回节点指针
        }
        // 将当前节点的左右子节点加入队列
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
    return NULL; // 未找到目标值
}

//树的先序遍历(递归)
void preTree(BiTree *p){
    if(p==NULL)return;
    printf("%d ",p->val);
    preTree(p->left);
    preTree(p->right);
}

//中序遍历
void midTree(BiTree *p){
    if(p==NULL)return;
    midTree(p->left);
    printf("%d ",p->val);
    midTree(p->right);
}

//中序(不用栈且非递归)
void morrisInOrderTraversal(BiTree *root) {
    BiTree *current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d ", current->val);  // 访问节点
            current = current->right;    // 向右移动
        } else {
            // 找到当前节点的前驱节点
            BiTree *pre = current->left;
            while (pre->right != NULL && pre->right != current) {
                pre = pre->right;
            }
            // 如果前驱节点的右孩子为空，将它的右孩子指向当前节点
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
            // 如果前驱节点的右孩子是当前节点，将它的右孩子恢复为空
            // 访问当前节点并向右移动
            else {
                pre->right = NULL;
                printf("%d ", current->val);  // 访问节点
                current = current->right;
            }
        }
    }
}

//后序遍历
void postTree(BiTree *p){
    if(p==NULL)return;
    postTree(p->left);
    postTree(p->right);
    printf("%d ",p->val);
}

//先序遍历(栈实现)
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

//先序创建二叉树?
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

//层序遍历
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

//层序遍历
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
//层序(排序版本)
// 定义队列节点结构体
typedef struct QueueNode {
    BiTree *treeNode;
    struct QueueNode *next;
    struct QueueNode *parent;
} QueueNode;
// 定义队列结构体
typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;
// 初始化队列
Queue* initQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
// 判断队列是否为空
bool isEmpty(Queue *q) {
    return q->front == NULL;
}
// 入队操作
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
// 出队操作
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
// 比较函数，用于排序
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
// 层次遍历并输出每层从小到大的节点值
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
//在树中搜索一个值，并把搜索时经过的路径打印出来(dfs顺序)
int j;
int searchAndPrintPath(BiTree *root, int target,int path[]){
    if (root == NULL){
        return 0;
    }
    // 打印当前节点的值
    printf("%d ", root->val);
    path[j++]=root->val;
    if (root->val == target){
        return 1;
    }
    // 搜索左子树
    if (searchAndPrintPath(root->left, target,path)){
        return 1;
    }
    // 搜索右子树
    if (searchAndPrintPath(root->right, target,path)){
        return 1;
    }
    // 如果当前路径没有找到目标值，则回溯
    printf("Backtracking from %d\n", root->val);
    j--;
    return 0;
}
// 复制二叉树
BiTree* copyTree(BiTree* root) {
    if (root == NULL) {
        return NULL;
    }

    // 创建新的节点
    BiTree* newRoot = createNode(root->val);

    // 递归复制左子树和右子树
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