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
//维护堆的性质
void heapify(int arr[],int n,int i){//数组长度n,要维护的数据下标i
    int largest=i;//先假设这个结点是max
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[largest]<arr[left])largest=left;
    if(right<n&&arr[largest]<arr[right])largest=right;
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}
//建堆
void BuildHeap(int arr[],int n){
    for(int i=(n-1)/2;i>=0;i--)heapify(arr,n,i);
}
//堆排序(建堆复杂度为O(N),维护堆复杂度O(logN),总O(NlogN))
void HeapSort(int arr[],int n){
    BuildHeap(arr,n);
    for(int i=n-1;i>=0;i--){
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }
}
int main(){
    int s[20];
    for(int i=0;i<6;i++)scanf("%d",&s[i]);
    HeapSort(s,6);
    int t=6;
    while(t--)printf("%d ",s[t]);
    return 0;
}