#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_NODES = 100;  // 最大节点数
const int INF = 1e9;        // 无穷大表示不可达

struct Graph {
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;

    // 初始化邻接矩阵
    void initialize(int nodes) {
        numNodes = nodes;
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                adjMatrix[i][j] = (i == j) ? 0 : INF; // 初始化为无穷大，自己到自己的距离为0
            }
        }
    }

    // 添加边
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // 对于无向图
    }

    // 使用Floyd-Warshall算法计算最短路径
    void floydWarshall() {
        // dist[i][j] 表示从节点 i 到节点 j 的最短路径
        int dist[MAX_NODES][MAX_NODES];
        
        // 初始化dist矩阵
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                dist[i][j] = adjMatrix[i][j];  // 初始距离是邻接矩阵中的值
            }
        }

        // 进行动态规划更新最短路径
        for (int k = 0; k < numNodes; k++) {  // 遍历所有可能的中间节点
            for (int i = 0; i < numNodes; i++) {  // 遍历所有源节点
                for (int j = 0; j < numNodes; j++) {  // 遍历所有目标节点
                    // 如果从 i 到 j 的路径可以通过 k 节点更短，则更新距离
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
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    int nodes, edges;
    cin >> nodes >> edges;

    g.initialize(nodes);

    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    // 运行Floyd-Warshall算法
    g.floydWarshall();

    return 0;
}
