#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
void merge(int arr[],int tempArr[],int left,int mid,int right){
    int l=left;//左半区第一个未排序的元素
    int r=mid+1;//右半区第一个未排序的元素
    int pos=left;//临时数组元素下标
    //合并
    while(l<=mid&&r<=right){
        if(arr[l]<arr[r])tempArr[pos++]=arr[l++];
        else tempArr[pos++]=arr[r++];
    }
    while(l<=mid)tempArr[pos++]=arr[l++];
    while(r<=right)tempArr[pos++]=arr[r++];
    while(left<=right){
        arr[left]=tempArr[left];
        left++;
    }
}
void msort(int arr[],int tempArr[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        msort(arr,tempArr,left,mid);
        msort(arr,tempArr,mid+1,right);
        merge(arr,tempArr,left,mid,right);
    }
}
void MergeSort(int arr[],int n){
    int *tempArr=(int *)malloc(n * sizeof(int));
    if(tempArr){
        msort(arr,tempArr,0,n-1);
        free(tempArr);
    }else{
        printf("Failed\n");
    }
}
int main(){
    int s[20];
    for(int i=0;i<6;i++)scanf("%d",&s[i]);
    MergeSort(s,6);
    int t=6;
    while(t--)printf("%d ",s[t]);
    return 0;
}