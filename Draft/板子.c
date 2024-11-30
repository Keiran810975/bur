#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define NHASH  3001
#define MULT  37
#define eps 1e-7
//swap����
void swap(int *x,int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}
//�����ṹ���swap
typedef struct BiTree{
    int val;
    struct BiTree *left;
    struct BiTree *right;
}BiTree;
void swapStruct(BiTree *x,BiTree *y){
    struct BiTree temp=*x;
    *x=*y;
    *y=temp;
}
//�۰����
int binsearch(char key[][20], int n, char k[]){
     int low=0, high=n-1, mid;
       while(low<=high){
              mid=(low+high)/2;
              if(strcmp(k,key[mid])==0)
                    return mid;             /*  ���ҳɹ�  */
              if(strcmp(k,key[mid])>0)
                    low=mid+1;            /*  ׼�����Һ�벿�� */
              else
                    high=mid-1;           /* ׼������ǰ�벿�� */
        }
        return -1;                             /*   ����ʧ��  */
}
int Inbinsearch(char key[][20],char k[],int x,int y){
     int low=x, high=y-1, mid;
       while(low<=high){
              mid=(low+high)/2;
              if(strcmp(k,key[mid])==0)
                    return mid;             /*  ���ҳɹ�  */
              if(strcmp(k,key[mid])>0)
                    low=mid+1;            /*  ׼�����Һ�벿�� */
              else
                    high=mid-1;           /* ׼������ǰ�벿�� */
        }
        return -1;                             /*   ����ʧ��  */
}
//��ϣ
unsigned int hash(char *str){
       unsigned int h=0;
       char *p;
       for(p=str; *p!='\0'; p++)
              h = MULT*h + *p;
       return h % NHASH;
}
typedef struct list{
    char val[20];
    struct list *next;
}list;
list *hh[3500];

list * hSearch(char s[]){
    unsigned int x=hash(s);
    list *p=hh[x];
    while(p!=NULL){
        if(strcmp(p->val,s)==0)return p;
        //else if(strcmp(p->val,s)>0)return NULL;
        p=p->next;
    }
    return NULL;
}
void hashInsert(char s[]){
    list *p=(list *)malloc(sizeof(list));
                unsigned int x=hash(s);
                strcpy(p->val,s);
                p->next=hh[x];
                hh[x]=p;
}
//�ṹ��cmp
typedef struct info{
    char phone[50];
    char stat;
    int in;
    int out;
}info;
int cmp(const void *x,const void *y){
    info xx = *(info*)x;
    info yy = *(info*)y;
    if(strcmp(xx.phone,yy.phone)>0)return 1;
    if(strcmp(xx.phone,yy.phone)<0)return -1;
    if(strcmp(xx.phone,yy.phone)==0){
        if(xx.stat>yy.stat)return 1;
        if(xx.stat<yy.stat)return -1;
        return 0;
    }
}
//��ؼ�������
int score[100],time[100];
int cmp3(const void *p,const void *q){
    int a=(*(int *)p);
    int b=(*(int *)q);
    double aa=score[a];double bb=score[b];
    if(aa-bb>eps)return -1;
    if(aa-bb<-eps)return 1;
    int aaa=time[a],bbb=time[b];
    if(aaa>bbb)return 1;
    if(aaa<bbb)return -1;
    return 0;
}
int main(){
    //strstr:���ص�һ�γ��ֵĵ�ַ
    char *s;
    char aaa[]="abcdefghijklmn";
    s=strstr(aaa,"hij");
    printf("%s\n",s);

    //�ļ�����
    FILE* op=fopen("encrypt.txt","r");
    FILE *ou=fopen("output.txt","w");
    char ch;
    while((ch=fgetc(op))!=EOF);
    int n=1;
    fprintf(ou,"%d",n);
    return 0;
}