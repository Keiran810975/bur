#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // 找到未排序部分的最小元素
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // 将最小元素与当前元素交换
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int a[10]={3,5,4,1,7,0,8,9,2,6};int min;
    // for(int i=0;i<9;i++){
    //     int temp;
    //     min=i;
    //     for(int j=i+1;j<10;j++){
    //         if(a[min]>a[j])min=j;
    //     }
    //     temp=a[min];a[min]=a[i];a[i]=temp;
        
    // }
    selectionSort(a,10);
    for(int i=0;i<10;i++)printf("%d ",a[i]);

    return 0;
}