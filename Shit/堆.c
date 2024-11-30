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
void heapify(int arr[],int n,int i){//数组长度n,要维护的数据下标i
    int largest=i;//先假设这个结点是max
    int left=2*i;
    int right=2*i+1;
    if(left<n&&arr[largest]<arr[left])largest=left;
    if(right<n&&arr[largest]<arr[right])largest=right;
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}
void put(int x){
    int f;
    len++;
    priQ[len]=x;
    int b=len;
    heapify(priQ,len,len);
}
int get(){//取出堆顶
//长度-1，把最后一个提到第一个。利用堆的父子节点关系，用换到第一个的数与儿子比较，
//如果比孩子大，就与两个儿子之间较小的一个交换，直到没有儿子或比儿子小为止
    int x=priQ[1];
    priQ[1]=priQ[len];
    len--;
    int f,c;
    heapify(priQ,len,1);
    return x;
}
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        put(x);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",priQ[i]);
    }
    return 0;
}