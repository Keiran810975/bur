//Bellman-Ford 算法，用来计算从起点（在这里是节点 1）到图中其他节点的最短路径。
// 如果图中存在负权环路，它会检测到负权环并输出相应结果。
// 这在处理带有负权边的图时很有用，因为 Dijkstra 算法不支持负权边。
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Graph {
    int numNodes;
    vector<vector<pair<int, int>>> adjList; // 存储邻接表，pair<int, int>为<邻接点, 权重>

    Graph(int nodes) {
        numNodes = nodes;
        adjList.resize(numNodes);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // 对于无向图
    }
    
    vector<long long> bellmanFord(int start) {
        const long long INF = numeric_limits<long long>::max();
        vector<long long> dist(numNodes, INF); // 初始化所有节点的距离为无穷大
        dist[start] = 0; // 起点到自身的距离为0

        // 执行 |V|-1 次松弛操作
        for (int i = 1; i <= numNodes - 1; i++) {
            for (int u = 0; u < numNodes; u++) {
                for (auto [v, weight] : adjList[u]) {
                    if (dist[u] != INF && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // 检测负权环
        for (int u = 0; u < numNodes; u++) {
            for (auto [v, weight] : adjList[u]) {
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    cout << "fuhuan" << endl;
                    return {}; // 如果有负权环，返回空结果
                }
            }
        }

        return dist;
    }
};

int main() {
    int nodes = 5;
    Graph graph(nodes);

    // 添加边
    graph.addEdge(0, 1, 6);
    graph.addEdge(0, 2, 7);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 3, 5);
    graph.addEdge(1, 4, -4);
    graph.addEdge(2, 3, -3);
    graph.addEdge(2, 4, 9);
    graph.addEdge(3, 1, -2);
    graph.addEdge(4, 3, 7);

    int start = 0; // 从节点 0 开始
    vector<long long> distances = graph.bellmanFord(start);

    if (!distances.empty()) {
        for (int i = 0; i < nodes; i++) {
            if (distances[i] == numeric_limits<long long>::max()) {
                cout << "no" << endl;
            } else {
                cout << distances[i] << endl;
            }
        }
    }

    return 0;
}
