#include <stdio.h>

// 返回最大值的辅助函数
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 钢管切割问题的动态规划解决方案
int rodCutting(int price[], int n) {
    int dp[n + 1];
    dp[0] = 0;  // 长度为0的钢管没有收益

    // 填充dp数组
    for (int i = 1; i <= n; i++) {
        int maxProfit = -1;
        for (int j = 1; j <= i; j++) {
            maxProfit = max(maxProfit, price[j - 1] + dp[i - j]);
        }
        dp[i] = maxProfit;
    }

    return dp[n];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};  // 各长度钢管的价格表
    int n = sizeof(price) / sizeof(price[0]);    // 钢管的最大长度

    printf("%d\n", rodCutting(price, n));

    return 0;
}
