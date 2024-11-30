#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int cap;           // 总容量
int w[1000], v[1000], num[1000]; // 体积、价值和每种物品的数量限制
int f[1000][1000]; // 动态规划数组
int n;             // 物品种类数

// 动态规划解法
void dp() {
    for (int i = 0; i < n; i++) {
        // 逆序遍历背包容量
        for (int j = cap; j >= 0; j--) {
            // 遍历每个物品的数量限制
            for (int k = 0; k <= num[i] && k * w[i] <= j; k++) {
                f[i+1][j] = max(f[i+1][j], f[i][j - k * w[i]] + k * v[i]);
            }
        }
    }
    printf("%d\n", f[n][cap]);
}

// 空间优化版动态规划
int ff[1000];
void dp2() {
    for (int i = 0; i < n; i++) {
        // 逆序遍历容量，防止重复使用物品
        for (int j = cap; j >= 0; j--) {
            // 每件物品最多选 num[i] 次
            for (int k = 0; k <= num[i] && k * w[i] <= j; k++) {
                ff[j] = max(ff[j], ff[j - k * w[i]] + k * v[i]);
            }
        }
    }
    printf("%d\n", ff[cap]);
}

int main() {
    cin >> cap >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i] >> num[i]; // 输入体积、价值和数量
    }

    dp();     // 使用二维数组的解法
    // dp2(); // 使用空间优化后的解法
    return 0;
}
