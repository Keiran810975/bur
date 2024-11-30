#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int a[1000005];
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
// 二分查找第一个大于等于 m1 的数
int find(int l, int r, int m1) {
    int result = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= m1) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return result;
}

// 二分查找第一个小于等于 m2 的数
int find2(int l, int r, int m2) {
    int result = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= m2) {
            result = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    while (q--) {
        int d, k;
        scanf("%d %d", &d, &k);
        int m1 = d * k;
        int m2 = d * (k + 1) - 1;
        int l = find(0, n - 1, m1);
        int r = find2(0, n - 1, m2);
        if (l == -1 || r == -1) {
            printf("0\n");
        } else {
            printf("%d\n", r - l + 1);
        }
    }
    return 0;
}
