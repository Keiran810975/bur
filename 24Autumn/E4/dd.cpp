#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;
const double INF = 1e9;  // 设置一个非常大的值表示不可达

// Floyd-Warshall 算法
void floydWarshall(int n, vector<vector<double>>& dist) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<double>> dist(n + 1, vector<double>(n + 1, INF));  // 存储最短路径
        vector<vector<int>> weights(n + 1, vector<int>(n + 1, -1));  // 存储边权
        
        // 初始化图的边权
        for (int i = 1; i <= n; ++i) {
            dist[i][i] = 0;
        }
        
        // 读取边信息
        vector<pair<int, int>> edges;
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], (double)w);
            weights[u][v] = w;
            edges.push_back({u, v});
        }

        // 使用Floyd-Warshall算法计算所有点对之间的最短路径
        floydWarshall(n, dist);

        // 最小平均环权值
        double minAvgWeight = INF;

        // 检查每条边
        for (auto& edge : edges) {
            int u = edge.first, v = edge.second;
            if (dist[v][u] < INF) {
                // 计算环的平均权值
                double avgWeight = (dist[v][u] + weights[u][v]) / 2.0;
                minAvgWeight = min(minAvgWeight, avgWeight);
            }
        }

        // 输出结果，保留4位小数
        if (minAvgWeight == INF) {
            cout << fixed << setprecision(4) << 0.0 << endl;
        } else {
            cout << fixed << setprecision(4) << minAvgWeight << endl;
        }
    }
    return 0;
}
