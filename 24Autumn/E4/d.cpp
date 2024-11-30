#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
#include <tuple>

using namespace std;

#define INF INT_MAX

// 计算环的权值
double solve(int n, int m, vector<tuple<int, int, int>>& edges) {
    // Bellman-Ford算法的距离数组
    vector<int> dist(n, INF);  // 存储从源点到各个点的最短路径
    vector<int> edge_weights(n, INF);  // 存储每条边的权值

    // 对于每个源点 i 进行 Bellman-Ford
    double min_weight = INF;  // 最小环的权值初始化为无穷大
    
    for (int start = 0; start < n; start++) {
        dist[start] = 0;  // 初始化源点的距离为 0
        
        // Bellman-Ford 算法：进行 n-1 次迭代
        for (int i = 1; i < n; i++) {
            for (auto& edge : edges) {
                int u, v, w;
                tie(u, v, w) = edge;
                
                // 松弛操作，更新最短路径
                if (dist[u - 1] != INF && dist[v - 1] > dist[u - 1] + w) {
                    dist[v - 1] = dist[u - 1] + w;
                    edge_weights[v - 1] = w;
                }
            }
        }

        // 检查是否存在负权环
        for (auto& edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;
            
            if (dist[u - 1] != INF && dist[v - 1] > dist[u - 1] + w) {
                // 如果能松弛，说明图中有负环
                min_weight = min(min_weight, (double)w); // 更新最小的环权值
            }
        }
    }

    return min_weight == INF ? 0.0 : min_weight;
}

int main() {
    int T;
    cin >> T;  // 读入测试数据组数

    while (T--) {
        int n, m;
        cin >> n >> m;  // 读入点数和边数

        vector<tuple<int, int, int>> edges(m); // 边的列表
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;  // 每条边的起点、终点和权重
            edges[i] = make_tuple(u, v, w);
        }

        // 计算最小环的权值
        double result = solve(n, m, edges);

        // 输出结果，保留四位小数
        cout << fixed << setprecision(4) << result << endl;
    }

    return 0;
}
