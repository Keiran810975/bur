#include <iostream>
using namespace std;
int arr[500010];
long long invCount = 0;
int n;int key;
void mergeAndCount(int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int leftArr[leftSize], rightArr[rightSize];
    
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < rightSize; i++)
        rightArr[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] > key * rightArr[j]) {
            invCount += (leftSize - i);
            j++;
        } else {
            i++;
        }
    }
    i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
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
    cin >> key;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    invCount = 0;
    inverse(0, n - 1); 
    printf("%lld\n", invCount); 
    return 0;
}
