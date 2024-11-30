#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
typedef struct BiTree{
    int val;
    int cnt;
    struct BiTree *left;
    struct BiTree *right;
    struct BiTree *dad;
}BiTree;
int compare;
//二叉搜索??--->用中序遍历会得到从小到大的排??
//在二叉搜索树中插入元??
void bstInsert(BiTree **p,int data,BiTree *par){
    if(*p==NULL){                      //空数的情??
        BiTree *newnode=(BiTree *)malloc(sizeof(BiTree));
        newnode->val=data;
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->cnt=1;
        newnode->dad=par;
        *p=newnode;
        return;
    }
    compare++;
    if(data>(*p)->val){            //不是空树的情??
        bstInsert(&((*p)->right),data,*p);
    }else if(data<(*p)->val){
        bstInsert(&((*p)->left),data,*p);
    }else if(data==(*p)->val){
        (*p)->cnt++;
    }
}
//在二叉搜索树中查找元??(返回地址)
BiTree *bstSearch(BiTree *p,int data){
    if(p==NULL)return NULL;//空树
    if(data==p->val)return p;
    if(data>p->val)return bstSearch(p->right,data);
    if(data<p->val)return bstSearch(p->left,data);
    return NULL;//没有找到
}
//删除二叉搜索树中的结??
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
//树的先序遍历(递归)
void preTree(BiTree *p){
    if(p==NULL)return;
    printf("%d ",p->val);
    preTree(p->left);
    preTree(p->right);
}
int max=0;
BiTree *target;
void shit(BiTree *p){
    if(p==NULL)return;
    if(p->cnt>max){
        max=p->cnt;
        target=p;
    }
    shit(p->left);
    shit(p->right);
}
//中序遍历
void midTree(BiTree *p){
    if(p==NULL)return;
    midTree(p->left);
    printf("%d ",p->val);
    midTree(p->right);
}
//后序遍历
void postTree(BiTree *p){
    if(p==NULL)return;
    postTree(p->left);
    postTree(p->right);
    printf("%d ",p->val);
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

int main(){
    int n;scanf("%d",&n);
    BiTree *p=(BiTree *)malloc(sizeof(BiTree));
    p=NULL;
    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        bstInsert(&p,x,NULL);
    }
    printf("%d\n",compare);
    target=(BiTree*)malloc(sizeof(BiTree));
    shit(p);
    //printf("\n%d\n",target->val);
    //printf("%d\n",target->dad->val);
    int path[1000];
    path[0]=target->val;
    int i=1;
    while(target->dad!=NULL){
        path[i++]=target->dad->val;
        target=target->dad;
    }
    for(int j=i-1;j>=0;j--)printf("%d ",path[j]);
    return 0;
}