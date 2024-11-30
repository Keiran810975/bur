#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
void swap(int *x,int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}
int priQ[100000];//堆(小根堆)
int len;//记录堆的长度
void put(int x){//把数加在最后,长度+1，利用堆的父子节点关系,一次次与父亲比较，如果比父亲小就交换，继续比较，直到比父亲大或到了根节点为止
    int f;
    len++;
    priQ[len]=x;
    int b=len;
    while(b!=1&&priQ[b]<priQ[b/2]){
        swap(&priQ[b],&priQ[b/2]);
        b=b/2;
    }
}
int get(){//取出堆顶
//长度-1，把最后一个提到第一个。利用堆的父子节点关系，用换到第一个的数与儿子比较，
//如果比孩子大，就与两个儿子之间较小的一个交换，直到没有儿子或比儿子小为止
    int x=priQ[1];
    priQ[1]=priQ[len];
    len--;
    int f,c;
    while(2*f<=len){
        if(2*f+1>len||priQ[2*f]<priQ[2*f+1])c=2*f;
        else c=2*f+1;
        if(priQ[f]<priQ[c]){
        swap(&priQ[f],&priQ[c]);
        f=c;
    }else return x;
    }
    return x;
}
int main(){
    put(1);
    put(3);
    put(4);
    put(2);
    put(7);
    printf("%d\n",len);
    get();
    get();
    for(int i=0;i<len;i++)printf("%d ",priQ[i]);
    printf("\n%d\n",len);
    return 0;
}