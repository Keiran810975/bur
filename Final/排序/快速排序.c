#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int cmp(const void *p,const void *q){
    if(*(int *)p<*(int *)q)return -1;
    if(*(int *)p>*(int *)q)return 1;
    return 0;
}
//�ṹ������
// int cmp(const void *x,const void *y){
//     struct node xx = *(struct node*)x;
//     struct node yy = *(struct node*)y;
//     return xx.d-yy.d;
// }
// ��ӡ����
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ����������������ߵ�Ԫ��Ϊ��׼
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (i < j && arr[j] >= pivot) {
            j--;
        }
        if (i < j) {
            arr[i] = arr[j];
            i++;
        }

        while (i < j && arr[i] <= pivot) {
            i++;
        }
        if (i < j) {
            arr[j] = arr[i];
            j--;
        }
    }

    arr[i] = pivot;
    return i;
}

// ����������
void quickSort(int arr[], int low, int high, int size) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        printArray(arr, size);  // �����������״̬
        quickSort(arr, low, pivotIndex - 1, size);
        quickSort(arr, pivotIndex + 1, high, size);
    }
}

int main(){
    //qsort(/*��������������sizeof������cmp*/);
    int arr[]={44, 32, 19, 31, 47, 26, 34, 48, 30, 26};
    quickSort(arr,0,9,10);
    return 0;
}