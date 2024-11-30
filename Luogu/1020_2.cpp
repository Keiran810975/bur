#include <iostream>
#include <algorithm>
using namespace std;

int m[100010];
int dp1[100010]; // 用于存储最长不下降子序列的最小末尾
int dp2[100010]; // 用于存储最长严格递增子序列的最小末尾

int main() {
    int n = 0;
    while (scanf("%d", &m[n + 1]) != EOF) {
        n++;
    }

    // 计算最长不下降子序列的长度
    int len1 = 0;
    for (int i = 1; i <= n; i++) {
        // 找到 dp1 中第一个大于 m[i] 的位置（支持相等）
        int pos = upper_bound(dp1, dp1 + len1, m[i]) - dp1;
        dp1[pos] = m[i];
        if (pos == len1) {
            len1++; // 如果是新的最大值，则序列长度增加
        }
    }
    printf("%d\n", len1);

    // 计算最长严格递增子序列的长度
    int len2 = 0;
    for (int i = 1; i <= n; i++) {
        // 找到 dp2 中第一个大于等于 m[i] 的位置
        int pos = lower_bound(dp2, dp2 + len2, m[i]) - dp2;
        dp2[pos] = m[i];
        if (pos == len2) {
            len2++; // 如果是新的最大值，则序列长度增加
        }
    }
    printf("%d\n", len2);

    return 0;
}
