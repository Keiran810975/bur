#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void heapSort(int arr[], int n);

// Global variables for counting comparisons
int bubbleComparisons = 0;
int selectionComparisons = 0;
int insertionComparisons = 0;
int mergeComparisons = 0;
int quickComparisons = 0;
int heapComparisons = 0;

int main() {
    int arr[]={1,2,3,4,5,10,6,7,8,9};
    int n=10;
    // printf("Enter the size of the array: ");
    // scanf("%d", &n);

    // int arr[n];
    // printf("Enter %d elements:\n", n);
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &arr[i]);
    // }

    // Initialize minimum comparisons to a large number
    int minComparisons = 999999999;
    int comparisons;
    char optimalMethod[20]; // To store the name of the optimal sorting method
    char methodNames[6][20] = {"Bubble Sort", "Selection Sort", "Insertion Sort", 
                               "Merge Sort", "Quick Sort", "Heap Sort"};

    int sortedArray[n];

    // Bubble Sort
    for (int i = 0; i < n; i++) {
        sortedArray[i] = arr[i];
    }
    bubbleSort(sortedArray, n);
    comparisons = bubbleComparisons;
    if (comparisons < minComparisons) {
        minComparisons = comparisons;
        strcpy(optimalMethod, methodNames[0]);
    }

    // Selection Sort
    for (int i = 0; i < n; i++) {
        sortedArray[i] = arr[i];
    }
    selectionSort(sortedArray, n);
    comparisons = selectionComparisons;
    if (comparisons < minComparisons) {
        minComparisons = comparisons;
        strcpy(optimalMethod, methodNames[1]);
    }

    // Insertion Sort
    for (int i = 0; i < n; i++) {
        sortedArray[i] = arr[i];
    }
    insertionSort(sortedArray, n);
    comparisons = insertionComparisons;
    if (comparisons < minComparisons) {
        minComparisons = comparisons;
        strcpy(optimalMethod, methodNames[2]);
    }

    // Merge Sort
    for (int i = 0; i < n; i++) {
        sortedArray[i] = arr[i];
    }
    mergeSort(sortedArray, 0, n - 1);
    comparisons = mergeComparisons;
    if (comparisons < minComparisons) {
        minComparisons = comparisons;
        strcpy(optimalMethod, methodNames[3]);
    }

    // Quick Sort
    for (int i = 0; i < n; i++) {
        sortedArray[i] = arr[i];
    }
    quickSort(sortedArray, 0, n - 1);
    comparisons = quickComparisons;
    if (comparisons < minComparisons) {
        minComparisons = comparisons;
        strcpy(optimalMethod, methodNames[4]);
    }

    // Heap Sort
    for (int i = 0; i < n; i++) {
        sortedArray[i] = arr[i];
    }
    heapSort(sortedArray, n);
    comparisons = heapComparisons;
    if (comparisons < minComparisons) {
        minComparisons = comparisons;
        strcpy(optimalMethod, methodNames[5]);
    }

    printf("Minimum comparisons: %d\n", minComparisons);
    printf("Optimal sorting method: %s\n", optimalMethod);
    printf("Minimum comparisons: %d\n", minComparisons);
    printf("Optimal sorting method: %s\n", optimalMethod);
    printf("________\n");
    printf("Bubble Sort comparisons: %d\n", bubbleComparisons);
    printf("Selection Sort comparisons: %d\n", selectionComparisons);
    printf("Insertion Sort comparisons: %d\n", insertionComparisons);
    printf("Merge Sort comparisons: %d\n", mergeComparisons);
    printf("Quick Sort comparisons: %d\n", quickComparisons);
    printf("Heap Sort comparisons: %d\n", heapComparisons);
    return 0;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            bubbleComparisons++;
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            selectionComparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        insertionComparisons++;
        while (j >= 0 && arr[j] > key) {
            
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];
    for (int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        mergeComparisons++;
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        quickComparisons++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    heapComparisons++;
    if (left < n && arr[left] > arr[largest])
        largest = left;

    heapComparisons++;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}
