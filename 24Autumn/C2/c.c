#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *x, int *y) {
    int temp = *y;
    *y = *x;
    *x = temp;
}

int len = 0;
int heap[100010];

void put(int x) {
    heap[++len] = x;
    int i = len;
    while (i > 1 && heap[i] > heap[i >> 1]) {
        swap(&heap[i], &heap[i >> 1]);
        i >>= 1;
    }
}
void get() {
    heap[1] = heap[len--];
    int i = 1;

    while (i << 1 <= len) {
        int j = i << 1;
        if (j < len && heap[j] < heap[j + 1]) j++;
        if (heap[i] >= heap[j]) break;
        swap(&heap[i], &heap[j]);
        i = j;
    }
}

// 堆排序
void heapSort() {
    int originalLen = len;

    while (len > 1) {
        swap(&heap[1], &heap[len]);
        len--; 
 
        int i = 1;
        while (i << 1 <= len) {
            int j = i << 1;
            if (j < len && heap[j] < heap[j + 1]) j++;
            if (heap[i] >= heap[j]) break;
            swap(&heap[i], &heap[j]);
            i = j;
        }
    }
    len = originalLen; 
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) { 
            int x;
            scanf("%d", &x);
            put(x);
        } else if (op == 2) { 
            get();
        } else {
            printf("%d\n", heap[1]);
        }
    }
    
    heapSort();
    for (int i = len; i>=1;i--) {
        printf("%d ", heap[i]);
    }

    return 0;
}
