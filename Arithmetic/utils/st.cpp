#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 50005;   // 最大牛的数量
const int LOG = 16;       // log2(50005) 大约为 16

int n, m;                 // 牛的数量和查询的数量
int heights[MAXN];        // 牛的身高数组
int maxST[MAXN][LOG];     // 存储区间最大值的 ST 表
int minST[MAXN][LOG];     // 存储区间最小值的 ST 表

// 预处理 ST 表
void buildST() {
    // 初始化 ST 表的第一层
    for (int i = 0; i < n; i++) {
        maxST[i][0] = heights[i]; // 最大值 ST 表
        minST[i][0] = heights[i]; // 最小值 ST 表
    }

    // 填充 ST 表
    for (int j = 1; (1 << j) <= n; j++) {  // 遍历每一层
        for (int i = 0; i + (1 << j) - 1 < n; i++) {  // 遍历每个可能的区间
            maxST[i][j] = max(maxST[i][j - 1], maxST[i + (1 << (j - 1))][j - 1]); // 计算区间最大值
            minST[i][j] = min(minST[i][j - 1], minST[i + (1 << (j - 1))][j - 1]); // 计算区间最小值
        }
    }
}

// 查询区间 [l, r] 中的最大值
int queryMax(int l, int r) {
    int len = r - l + 1;           // 区间长度
    int k = log2(len);             // 找到覆盖区间的最大2的幂次
    return max(maxST[l][k], maxST[r - (1 << k) + 1][k]); // 返回区间最大值
}

// 查询区间 [l, r] 中的最小值
int queryMin(int l, int r) {
    int len = r - l + 1;           // 区间长度
    int k = log2(len);             // 找到覆盖区间的最大2的幂次
    return min(minST[l][k], minST[r - (1 << k) + 1][k]); // 返回区间最小值
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];         // 输入牛的身高
    }

    buildST();                     // 构建 ST 表

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--; // 将输入转换为0基索引
        int maxHeight = queryMax(l, r); // 查询区间最大值
        int minHeight = queryMin(l, r); // 查询区间最小值
        cout << maxHeight - minHeight << endl; // 输出差值
    }

    return 0;
}
