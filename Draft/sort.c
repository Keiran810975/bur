#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int a[200];
int cnt;
void swap(int *x,int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}
void merge(int arr[],int tempArr[],int left,int mid,int right){
    int l=left;//左半区第一个未排序的元素
    int r=mid+1;//右半区第一个未排序的元素
    int pos=left;//临时数组元素下标
    //合并
    while(l<=mid&&r<=right){
        cnt++;
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
void quickSort(int k[],int left,int right){     
    int i, last;
    if(left<right){
        last=left; 
        for(i=left+1;i<=right;i++){
            cnt++;
            if(k[i]<k[left])
                swap(&k[++last],&k[i]); 
        }
        swap(&k[left],&k[last]);
        quickSort(k,left,last-1); 
        quickSort(k,last+1,right);   
    }
}
//堆排序
void adjust(int k[ ],int i,int n){
    int j,temp;
    temp=k[i];
    j=2*i+1;
    while(j<n){
        if(j<n-1 && k[j]<k[j+1])
            j++;
        cnt++;
        if(temp>=k[j]) break;
        k[(j-1)/2]=k[j];
        j=2*j+1;
    }
    k[(j-1)/2]=temp;
}
void heapsort(int k[],int n){
    int temp;
    for(int i=n/2-1; i>=0; i--)
        adjust(k,i,n);
    for(int i=n-1; i>=1; i--){
        temp=k[i];
        k[i]=k[0];
        k[0]=temp;
        adjust(k,0,i);
    }
}
int main(){
    int n,op;
    scanf("%d%d",&n,&op);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    if(op==1){
        int min;
        for(int i=0;i<n;i++){
        int temp;
        min=i;
        for(int j=i+1;j<n;j++){
            cnt++;
            if(a[min]>a[j])min=j;
        }
        temp=a[min];a[min]=a[i];a[i]=temp;
    }
    }
    if(op==2){
        int x=0;
        for(int i=0;i<n-1;i++){
            x=0;
            for(int j=0;j<n-1-i;j++){
                int temp;
                cnt++;
                if(a[j]>a[j+1]){
                    x++;
                    temp=a[j];a[j]=a[j+1];a[j+1]=temp;
                }
            }
            if(x==0)break;
        }
    }
    if(op==3){
        // HeapSort(a,n);
        // cnt+=2;
        //for(int i=0;i<n;i++)
        heapsort(a,n);
    }
    if(op==4){
        MergeSort(a,n);
    }
    if(op==5){
        quickSort(a,0,n-1);
    }
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n%d\n",cnt);
    return 0;
}