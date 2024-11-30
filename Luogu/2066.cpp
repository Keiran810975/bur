#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int profit[11][16];  // profit[i][j]表示第 i 个公司分配 j 台设备的盈利
int dp[11][16];      // dp[i][j]表示前 i 个公司分配 j 台设备的最大盈利
int path[11][16][11]; // path[i][j][k]表示在状态 (i, j) 时，第 i 个公司分配了 k 台设备
int N, M;

int main() {
    // 读入公司数 N 和设备数 M
    cin >> N >> M;

    // 读入每个公司分配不同数量设备的盈利
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> profit[i][j];
        }
    }

    // 初始化 dp 数组为负无穷，表示未计算的状态
    memset(dp, -1, sizeof(dp));

    // 初始化 base case
    dp[0][0] = 0; // 没有公司，没有设备时，盈利为 0

    // 动态规划计算最大盈利
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= j; k++) {
                // 如果分配 k 台设备给第 i 个公司，更新 dp[i][j]
                if (dp[i - 1][j - k] != -1) { // 检查上一个状态是否有效
                    int new_profit = dp[i - 1][j - k] + profit[i][k];
                    if (new_profit > dp[i][j]) {
                        dp[i][j] = new_profit;
                        // 更新路径数组
                        for (int h = 1; h < i; h++) {
                            path[i][j][h] = path[i - 1][j - k][h];
                        }
                        path[i][j][i] = k;
                    }
                }
            }
        }
    }

    // 输出最大盈利值
    cout << dp[N][M] << endl;

    // 输出每个公司分配的设备数
    int remaining = M;
    for (int i = N; i >= 1; i--) {
        cout << i << " " << path[N][remaining][i] << endl;
        remaining -= path[N][remaining][i]; // 更新剩余设备数
    }

    return 0;
}
