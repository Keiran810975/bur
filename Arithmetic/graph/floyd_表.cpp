#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;  // 定义无穷大

struct Graph {
    int numNodes;  // 节点数
    vector<vector<pair<int, int>>> adjList;  // 邻接表，pair<邻接节点, 权重>

    Graph(int n) : numNodes(n), adjList(n) {}  // 初始化邻接表

    // 添加边
    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);  // 无向图添加反向边
    }

    // 使用Floyd-Warshall算法计算最短路径
    void floydWarshall() {
        // dist[i][j]表示从节点i到节点j的最短路径
        vector<vector<int>> dist(numNodes, vector<int>(numNodes, INF));

        // 初始化dist数组，使用邻接表的边初始化距离
        for (int i = 0; i < numNodes; i++) {
            dist[i][i] = 0;  // 从自己到自己距离为0
            for (auto& edge : adjList[i]) {
                int v = edge.first;
                int weight = edge.second;
                dist[i][v] = weight;  // 初始化直接连接的节点的距离
            }
        }

        // 进行动态规划更新最短路径
        for (int k = 0; k < numNodes; k++) {  // 遍历所有可能的中间节点
            for (int i = 0; i < numNodes; i++) {  // 遍历所有源节点
                for (int j = 0; j < numNodes; j++) {  // 遍历所有目标节点
                    // 如果通过k节点能使得从i到j的路径更短，更新dist[i][j]
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // 输出最短路径矩阵
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (dist[i][j] == INF) {
                    cout << "INF ";  // 如果路径不可达，输出INF
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    Graph g(nodes);

    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    // 运行Floyd-Warshall算法
    g.floydWarshall();

    return 0;
}
