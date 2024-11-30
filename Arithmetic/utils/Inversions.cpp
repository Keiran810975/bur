#include <iostream>
using namespace std;
const int MAX_SIZE =500010; 
int arr[MAX_SIZE];
long long invCount = 0;
int n;
// 合并并统计逆序对
void mergeAndCount(int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    
    // 临时数组用于合并
    int leftArr[leftSize], rightArr[rightSize];
    
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < rightSize; i++)
        rightArr[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    
    // 合并过程并统计逆序对
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
}

// 归并排序并统计逆序对
void inverse(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        inverse(left, mid);
        inverse(mid + 1, right);
        mergeAndCount(left, mid, right);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    inverse(0, n - 1);  // 调用归并排序函数
    printf("%lld\n", invCount);  // 输出逆序对的数量
    return 0;
}
