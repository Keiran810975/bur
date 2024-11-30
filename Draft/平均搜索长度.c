#include <stdio.h>
#include <math.h>

// 计算总搜索长度和平均搜索长度的函数
void binary_search_lengths(int n, double *total_length, double *average_length) {
    int total_comparisons = 0;
    int i;

    // 计算总搜索长度
    for (i = 1; i <= n; i++) {
        total_comparisons += (int)log2(i) + 1;
    }

    // 计算平均搜索长度
    *total_length = total_comparisons;
    *average_length = (double)total_comparisons / n;
}

int main() {
    int n;
    double total_length, average_length;

    // 输入有序顺序表的长度
    printf("请输入有序顺序表的长度: ");
    scanf("%d", &n);

    // 计算总搜索长度和平均搜索长度
    binary_search_lengths(n, &total_length, &average_length);

    // 输出结果
    printf("总搜索长度: %.0f\n", total_length);
    printf("平均搜索长度: %.2f\n", average_length);

    return 0;
}
