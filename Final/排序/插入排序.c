#include<stdio.h>
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // 将大于 key 的元素向后移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(){
    int a[10]={3,7,5,0,9,6,8,1,2,4};
    // for(int i=1;i<10;i++){
    //     for(int j=i;j>0;j--){
    //         int temp,k=j;
    //         if(a[k]<a[k-1]){
    //             temp=a[k];a[k]=a[k-1];a[k-1]=temp;k--;
    //         }
    //         else break;
    //     }
    // }
    insertionSort(a,10);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }

    return 0;
}