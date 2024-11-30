#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct BiTree{
    int val;
    struct BiTree *left;
    struct BiTree *right;
}BiTree;
//二叉搜索�?--->用中序遍历会得到从小到大的排�?
//在二叉搜索树中插入元�?
void bstInsert(BiTree **p,int data){
    if(*p==NULL){                      //空数的情�?
        BiTree *newnode=(BiTree *)malloc(sizeof(BiTree));
        newnode->val=data;
        newnode->left=NULL;
        newnode->right=NULL;
        *p=newnode;
        return;
    }
    if(data>(*p)->val){            //不是空树的情�?
        bstInsert(&((*p)->right),data);
    }else if(data<(*p)->val){
        bstInsert(&((*p)->left),data);
    }
}
//在二叉搜索树中查找元�?(返回地址)
BiTree *bstSearch(BiTree *p,int data){
    if(p==NULL)return NULL;//空树
    if(data==p->val)return p;
    if(data>p->val)return bstSearch(p->right,data);
    if(data<p->val)return bstSearch(p->left,data);
    return NULL;//没有找到
}
//删除二叉搜索树中的结�?
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
        }else if(p->left!=NULL&&p->right!=NULL){//让要删除结点的左子树都放在右子树最小结点的左子树上�?
            BiTree *cur=p->right;               //并让修改后的右子树代替删除的结点(反过来也�?)
            while(cur->left!=NULL)cur=cur->left;             //找到右子树上的最小结�?
            cur->left=p->left;
            BiTree *temp=p->right;
            free(p);
            return temp;
        }
    }
    return p;        //未找到要删除的结�?
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
//后序遍历
void postTree(BiTree *p){
    if(p==NULL)return;
    postTree(p->left);
    postTree(p->right);
    printf("%d ",p->val);
}
//先序创建二叉�?
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
BiTree *Expression(int rrr[],int num){
    BiTree *p=NULL;
	int i=0;
	BiTree* Stack[5];
	int top=-1;
	for(i=0;i<num;i++){
		p=(BiTree *)malloc(sizeof(BiTree));
		p->right=p->left=NULL;
		p->val=rrr[i];
		if(p->val>=0){
			Stack[++top]=p;
		}
		else{
			p->right=Stack[top--];
			p->left=Stack[top--];
			Stack[++top]=p;
		}
	}
	return Stack[0];
}
#define MAX 1000
char a[1000];
char temp[1000];
int tt[1000],reverse[1000];
typedef struct{
    int data[MAX];
    int top;
}stack;
stack init(stack *p){     //当栈空的时�? 初始化栈顶指针为-1
    p->top=-1;
}
//判断栈是否为�?
int isempty(stack *p){
    return p->top==-1;  //******
}
//判断栈是否满
int isfull(stack *p){
    return p->top==MAX-1;
}
//弹出栈元�?(pop)
int pop(stack *p){
    if(isempty(p)){
        printf("栈为空\n");
        return 0;
    }
    int val=p->data[p->top];
    p->top--;
    return val;
}
//插入栈元�?
void push(stack *p,int new){
    if(isfull(p)){
        printf("插入元素失败\n");
        return;
    }
    p->top+=1;
    p->data[p->top]=new; 
}
//获取栈顶元素的�?
int gettop(stack *p){
    if(isempty(p)){
        printf("获取失败\n");
        return 0;
    }
    return p->data[p->top];
}
int num(int c){
    if(c==-1||c==-2)return 1;
    if(c==-3||c==-4)return 2;
}
int issign(int c){
    if(c==-1||c==-2||c==-3||c==-4)return 1;
    if(c==-5||c==-6)return 2;
    return 0;
}
char rrr[1000];
void qwert(int x){
    if(x==-1)printf("+ ");
    else if(x==-2)printf("- ");
    else if(x==-3)printf("* ");
    else if(x==-4)printf("/ ");
    else printf("%d ",x);
}
int main(){
    gets(a);
    int len=strlen(a);
    int j=0;
    for(int i=0;i<len;i++){
        if(a[i]!=' '&&a[i]!='='){
            temp[j]=a[i];j++;
        }
    }
    j=0;
    for(int i=0;i<len;i++){
        if(temp[i]=='+'){tt[j]=-1;j++;}
        if(temp[i]=='-'){tt[j]=-2;j++;}
        if(temp[i]=='*'){tt[j]=-3;j++;}
        if(temp[i]=='/'){tt[j]=-4;j++;}
        if(temp[i]=='('){tt[j]=-5;j++;}
        if(temp[i]==')'){tt[j]=-6;j++;}
        if(temp[i]>='0'&&temp[i]<='9'){
            int x=temp[i]-'0';
            while(temp[i+1]>='0'&&temp[i+1]<='9'){
                x=10*x+temp[i+1]-'0';
                i++;
            }
            tt[j]=x;
            j++;
        }
    }
    //for(int i=0;i<j;i++)printf("%d ",tt[i]);printf("\n");
    stack *sss=(stack*)malloc(sizeof(stack));
    init(sss);
    int ll=strlen(temp);
    int k=0;
    int sig=0;//记录栈内是否有左括号（个数）
    for(int i=0;i<j;i++){
        //printf("%d\n",sig);
        if(!issign(tt[i])){//数字直接输出
            reverse[k]=tt[i];k++;
        }else if(tt[i]==-5){//左括号都入栈
            push(sss,tt[i]);
            sig++;
        }else if(tt[i]==-6){//如果有右括号,不断出栈，直到遇到左括号
            while(1){
                int x=pop(sss);
                if(x!=-5){
                    reverse[k]=x;k++;
                }else{
                    sig--;
                    break;
                }
            }
        }  
        else{
            if(isempty(sss)){//栈空运算符直接入�?
                push(sss,tt[i]);
            }else if(tt[i]==-3||tt[i]==-4){
                while(sss->data[sss->top]!=-1&&sss->data[sss->top]!=-2&&sss->data[sss->top]!=-5&&(!isempty(sss))){
                    int x=pop(sss);
                    reverse[k++]=x;
                }
                push(sss,tt[i]);
            }else if(tt[i]==-1||tt[i]==-2){
                while(sss->data[sss->top]!=-5&&(!isempty(sss))){
                    int x=pop(sss);
                    reverse[k++]=x;
                }
                push(sss,tt[i]);
            }
        }
    }
    while(!isempty(sss)){
        reverse[k]=pop(sss);k++;
    }
    //printf("%d\n",k);
    //for(int i=0;i<k;i++)printf("%d ",reverse[i]);printf("\n");
    stack *fff=(stack*)malloc(sizeof(stack));
    init(fff);
    for(int i=0;i<k;i++){
        if(issign(reverse[i])==0){
            push(fff,reverse[i]);
        }
        else{
            int c=pop(fff);
            int d=pop(fff);
            int e;
            if(reverse[i]==-1)e=c+d;
            else if(reverse[i]==-2)e=d-c;
            else if(reverse[i]==-4){
                if(c==0)e=0;
                else e=d/c;
            }
            else if(reverse[i]==-3)e=c*d;
            push(fff,e);
        }
    }
    // printf("%s",a);
    // printf("\n");
    int final=pop(fff);
    //printf("%d\n",final);
    BiTree *root=NULL;
    root=Expression(reverse,k);
    qwert(root->val);
    qwert(root->left->val);
    qwert(root->right->val);
    printf("\n");
    printf("%d\n",final);
    preTree(root);
    printf("\n");
    midTree(root);
    printf("\n");
    postTree(root);
    return 0;
}