#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

const long long INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges; // 存储边的信息
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u, v, w));
    }

    // Bellman-Ford
    vector<long long> dist(n + 1, INF);
    dist[1] = 0; // 从点 1 到自身的距离是 0

    // 松弛操作
    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] < INF) {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    // 检测负环
    bool hasNegativeCycle = false;
    for (auto [u, v, w] : edges) {
        if (dist[u] < INF && dist[v] > dist[u] + w) {
            hasNegativeCycle = true;
            break;
        }
    }

    // 输出结果
    if (hasNegativeCycle) {
        cout << "boo how" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) {
                cout << 1000000000 << " "; // 输出不可达的距离
            } else {
                cout << dist[i] << " "; // 输出最短路径
            }
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t; // 读取测试组数
    while (t--) {
        solve();
    }
    return 0;
}
