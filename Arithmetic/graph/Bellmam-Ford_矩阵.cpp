#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int MAX_NODES = 100; // 适当设定最大节点数
const long long INF = 1e9;

struct Graph {
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;

    void initialize(int nodes) {
        numNodes = nodes;
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                adjMatrix[i][j] = (i == j) ? 0 : INF; // 初始化为无穷大
            }
        }
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // 对于无向图
    }

    vector<long long> bellmanFord(int start) {
        vector<long long> dist(numNodes, INF); // 初始化所有节点距离为无穷大
        dist[start] = 0; // 起点到自身的距离为0

        // 执行 |V|-1 次松弛操作
        for (int i = 1; i <= numNodes - 1; i++) {
            for (int u = 0; u < numNodes; u++) {
                for (int v = 0; v < numNodes; v++) {
                    if (adjMatrix[u][v] != INF && dist[u] != INF) { // 如果边(u, v)存在
                        dist[v] = min(dist[v], dist[u] + adjMatrix[u][v]);
                    }
                }
            }
        }

        // 检测负权环
        for (int u = 0; u < numNodes; u++) {
            for (int v = 0; v < numNodes; v++) {
                if (adjMatrix[u][v] != INF && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v]) {
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
    Graph graph;
    graph.initialize(nodes);

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
            if (distances[i] == INF) {
                cout << "no" << endl;
            } else {
                cout << distances[i] << endl;
            }
        }
    }

    return 0;
}
