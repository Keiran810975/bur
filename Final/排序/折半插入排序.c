#include <stdio.h>
// �۰����������
void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;
        // ʹ�ö��ֲ���ȷ������λ��
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // ������ key ��Ԫ������ƶ�
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }
        // ���� key ����ȷ��λ��
        arr[left] = key;
    }
}
// ��ӡ���麯��
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// ������
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����������:\n");
    printArray(arr, n);

    binaryInsertionSort(arr, n);

    printf("������������:\n");
    printArray(arr, n);

    return 0;
}
