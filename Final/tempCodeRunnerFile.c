#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct list{
    int data;
    struct list *next;
};
typedef struct list sss;
sss *function(int ddd){
    sss *node=NULL;         //定义头指针
    node=(sss*)malloc(sizeof(sss)); //分配内存空间
    if(node==NULL)printf("fail");
    memset(node,0,sizeof(sss));
    node->data=ddd;
    node->next=NULL;
    //printf("%d",node->data);
    return node;
}
int main(){
    /*
    sss *node=NULL;         //定义头指针
    node=(sss*)malloc(sizeof(sss)); //分配内存空间
    if(node==NULL)printf("fail");
    memset(node,0,sizeof(sss));
    node->data=114;
    node->next=NULL;
    printf("%d",node->data);
    free(node);
    */
    sss *chaungjian=function(114);
    printf("%d\n%d",chaungjian->data,chaungjian->next);
    free(chaungjian);

    return 0;
}