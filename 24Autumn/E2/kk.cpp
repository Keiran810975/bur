#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

// 定义一个结构体来存储金币的位置和出现时间
struct Coin {
    int x, y, t;
    Coin(int x, int y, int t) : x(x), y(y), t(t) {}
};

// 曼哈顿距离
int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        
        vector<Coin> coins;
        for (int i = 0; i < n; ++i) {
            int x, y, t;
            cin >> x >> y >> t;
            coins.emplace_back(x, y, t);
        }
        
        // 按金币的时间进行排序，保证我们在考虑金币时是按时间顺序处理的
        sort(coins.begin(), coins.end(), [](const Coin &a, const Coin &b) {
            return a.t < b.t;
        });

        // 设定初始时刻 t=0，位置为 (0, 0)
        map<pair<int, int>, int> dp;
        dp[{0, 0}] = 0; // 在位置 (0, 0) 时，已经收集的金币数为 0
        
        int max_coins = 0;
        
        // 遍历每个金币
        for (const Coin &coin : coins) {
            map<pair<int, int>, int> next_dp;
            
            for (const auto &entry : dp) {
                int x = entry.first.first;
                int y = entry.first.second;
                int collected_coins = entry.second;
                
                // 曼哈顿距离判断：是否能在时间 t 到达 (coin.x, coin.y)
                int dist = manhattan_distance(x, y, coin.x, coin.y);
                if (coin.t >= dist) {
                    // 如果能够在 coin.t 时刻到达
                    next_dp[{coin.x, coin.y}] = max(next_dp[{coin.x, coin.y}], collected_coins + 1);
                }
                
                // 状态转移
                next_dp[{x + 1, y}] = max(next_dp[{x + 1, y}], collected_coins);
                next_dp[{x - 1, y}] = max(next_dp[{x - 1, y}], collected_coins);
                next_dp[{x, y + 1}] = max(next_dp[{x, y + 1}], collected_coins);
                next_dp[{x, y - 1}] = max(next_dp[{x, y - 1}], collected_coins);
                next_dp[{x, y}] = max(next_dp[{x, y}], collected_coins); // 保持不动
            }
            
            dp = next_dp;
        }

        // 计算最大能够拿到的金币数
        for (const auto &entry : dp) {
            max_coins = max(max_coins, entry.second);
        }
        
        cout << max_coins << endl;
    }
    
    return 0;
}
