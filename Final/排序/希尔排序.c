#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void shellSort(int arr[], int n) {
    // 选择增量序列，通常选择 n/2, n/4, ..., 1
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个增量序列进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
int main(){
    int a[10]={3,7,5,0,9,6,8,1,2,4};
    //     int gap,i,j,temp;
    //     for (gap=len>>1;gap>0;gap>>=1){
    //         for (i=gap;i<len;i++) {
    //             temp=arr[i];
    //             for(j=i-gap;j>=0&&arr[j]>temp;j-=gap)
    //                 arr[j+gap]=arr[j];
    //             arr[j+gap]=temp;
    //         }
    // }
    shellSort(a,10);
    for(int i=0;i<10;i++){
            printf("%d ",a[i]);
        }
    return 0;
}