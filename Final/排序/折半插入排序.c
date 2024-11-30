#include <stdio.h>
// 折半插入排序函数
void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;
        // 使用二分查找确定插入位置
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // 将大于 key 的元素向后移动
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }
        // 插入 key 到正确的位置
        arr[left] = key;
    }
}
// 打印数组函数
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// 主函数
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("给定数组是:\n");
    printArray(arr, n);

    binaryInsertionSort(arr, n);

    printf("排序后的数组是:\n");
    printArray(arr, n);

    return 0;
}
