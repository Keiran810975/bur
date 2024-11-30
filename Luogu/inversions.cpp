#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 合并并统计逆序对
int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    
    vector<int> leftArr(leftSize);
    vector<int> rightArr(rightSize);
    
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < rightSize; i++)
        rightArr[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left, invCount = 0;
    
    // 合并过程
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            invCount += (leftSize - i);  // 统计逆序对
        }
    }
    
    // 复制剩余元素
    while (i < leftSize)
        arr[k++] = leftArr[i++];
    while (j < rightSize)
        arr[k++] = rightArr[j++];
    
    return invCount;
}

// 归并排序并统计逆序对
int mergeSortAndCount(vector<int>& arr, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        invCount += mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid + 1, right);
        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

// 主函数
int countInversions(vector<int>& arr,int n) {
    return mergeSortAndCount(arr, 0, n-1);
}

int main() {
    vector<int> arr(11000);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << countInversions(arr,n) << endl;
    return 0;
}
