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
//��������??--->�����������õ���С�������??
//�ڶ����������в���Ԫ??
void bstInsert(BiTree **p,int data,BiTree *par){
    if(*p==NULL){                      //��������??
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
    if(data>(*p)->val){            //���ǿ�������??
        bstInsert(&((*p)->right),data,*p);
    }else if(data<(*p)->val){
        bstInsert(&((*p)->left),data,*p);
    }else if(data==(*p)->val){
        (*p)->cnt++;
    }
}
//�ڶ����������в���Ԫ??(���ص�ַ)
BiTree *bstSearch(BiTree *p,int data){
    if(p==NULL)return NULL;//����
    if(data==p->val)return p;
    if(data>p->val)return bstSearch(p->right,data);
    if(data<p->val)return bstSearch(p->left,data);
    return NULL;//û���ҵ�
}
//ɾ�������������еĽ�??
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
//�����������(�ݹ�)
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
//�������
void midTree(BiTree *p){
    if(p==NULL)return;
    midTree(p->left);
    printf("%d ",p->val);
    midTree(p->right);
}
//�������
void postTree(BiTree *p){
    if(p==NULL)return;
    postTree(p->left);
    postTree(p->right);
    printf("%d ",p->val);
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