#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // 堆的最大容量

typedef struct {
    int data[MAX_SIZE];
    int size;  // 当前堆的大小
} MaxHeap;

// 初始化堆
void initHeap(MaxHeap *heap) {
    heap->size = 0;
}

// 获取堆顶元素
int getTop(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -1;  // 堆为空时返回 -1 表示错误
    }
    return heap->data[0];  // 堆顶是 data[0]
}

// 上滤操作，维护堆的性质
void siftUp(MaxHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->data[parent] >= heap->data[index])
            break;
        // 交换父节点和当前节点
        int temp = heap->data[parent];
        heap->data[parent] = heap->data[index];
        heap->data[index] = temp;
        index = parent;
    }
}

// 插入元素
void insert(MaxHeap *heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap is full.\n");
        return;
    }
    heap->data[heap->size] = value;
    heap->size++;
    siftUp(heap, heap->size - 1);  // 进行上滤操作
}

// 下滤操作，维护堆的性质
void siftDown(MaxHeap *heap, int index) {
    while (index * 2 + 1 < heap->size) {
        int leftChild = index * 2 + 1;
        int rightChild = index * 2 + 2;
        int largest = index;

        if (leftChild < heap->size && heap->data[leftChild] > heap->data[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap->size && heap->data[rightChild] > heap->data[largest]) {
            largest = rightChild;
        }
        if (largest == index)
            break;
        
        // 交换
        int temp = heap->data[largest];
        heap->data[largest] = heap->data[index];
        heap->data[index] = temp;

        index = largest;
    }
}

// 删除堆顶元素
void deleteTop(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    // 将最后一个元素移到堆顶
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    siftDown(heap, 0);  // 进行下滤操作
}

// 取出堆顶元素并删除
int extractTop(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -1;  // 返回 -1 表示错误
    }
    int top = heap->data[0];  // 取出堆顶元素
    deleteTop(heap);  // 删除堆顶元素
    return top;  // 返回堆顶元素
}

// 打印堆
void printHeap(MaxHeap *heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap heap;
    initHeap(&heap);

    // 插入元素
    insert(&heap, 10);
    insert(&heap, 40);
    insert(&heap, 30);
    insert(&heap, 60);
    insert(&heap, 90);
    insert(&heap, 70);

    printHeap(&heap);  // 打印堆

    // 获取堆顶元素
    printf("Heap top: %d\n", getTop(&heap));

    // 删除堆顶元素
    deleteTop(&heap);
    printHeap(&heap);

    return 0;
}
