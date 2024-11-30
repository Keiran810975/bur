#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 合并两个有序的子数组
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // 左半部分的大小
    int n2 = right - mid;     // 右半部分的大小
    // 创建临时数组
    int L[n1], R[n2];
    // 拷贝数据到临时数组 L 和 R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    // 合并临时数组回到原数组 arr
    int i = 0;  // 初始化 L 的索引
    int j = 0;  // 初始化 R 的索引
    int k = left;  // 初始化合并后数组的索引
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // 拷贝 L 中的剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // 拷贝 R 中的剩余元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 递归的归并排序函数
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // 找到中间点
        // 递归排序左半部分和右半部分
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // 合并已排序的部分
        merge(arr, left, mid, right);
    }
}

// 测试函数
int main() {
    int n=6;
    int arr[] = {12, 11, 13, 5, 6, 7};
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
