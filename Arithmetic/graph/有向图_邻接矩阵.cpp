#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// 邻接矩阵存储的有向图
struct Graph {
    int numNodes;                  // 节点数
    vector<vector<int>> adjMatrix; // 邻接矩阵

    Graph(int n) : numNodes(n) {
        adjMatrix = vector<vector<int>>(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            adjMatrix[i][i] = 0; // 自己到自己的距离为 0
        }
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
    }

    // DFS (递归实现)
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true; // 标记当前节点为已访问
        cout << v << " ";   // 输出当前节点

        for (int u = 0; u < numNodes; ++u) {
            if (adjMatrix[v][u] != INF && !visited[u]) {
                DFSUtil(u, visited); // 递归访问相邻未访问的节点
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(numNodes, false); // 访问标记数组
        cout << "DFS starting from node " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // BFS (使用队列实现)
    void BFS(int start) {
        vector<bool> visited(numNodes, false); // 访问标记数组
        queue<int> q; // 创建一个队列
        visited[start] = true; // 标记起始节点为已访问
        q.push(start); // 将起始节点入队

        cout << "BFS starting from node " << start << ": ";
        while (!q.empty()) {
            int v = q.front(); // 获取队头元素
            q.pop();          // 出队
            cout << v << " "; // 输出当前节点

            // 访问所有相邻未访问的节点
            for (int u = 0; u < numNodes; ++u) {
                if (adjMatrix[v][u] != INF && !visited[u]) {
                    visited[u] = true; // 标记为已访问
                    q.push(u);         // 入队
                }
            }
        }
        cout << endl;
    }
};

// Dijkstra 算法
vector<int> dijkstra(const Graph& graph, int start) {
    int n = graph.numNodes;
    vector<int> dist(n, INF);     // 距离数组，初始值为无穷大
    vector<bool> visited(n, false); // 标记节点是否已访问
    dist[start] = 0;              // 起点到自身距离为 0

    for (int i = 0; i < n; ++i) {
        // 找到未访问的节点中距离最小的节点
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        // 如果最小距离仍为无穷大，表示剩下的节点不可达
        if (dist[u] == INF) break;

        visited[u] = true;

        // 更新相邻节点的距离
        for (int v = 0; v < n; ++v) {
            if (graph.adjMatrix[u][v] != INF && dist[u] + graph.adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + graph.adjMatrix[u][v];
            }
        }
    }

    return dist;
}

// 拓扑排序（Kahn 算法实现）
//将图中的所有节点排列成一个线性序列，使得对于每一条有向边 𝑢→𝑣，节点 𝑢 在排序中出现在节点 𝑣 之前
vector<int> topologicalSort(const Graph& graph) {
    int n = graph.numNodes;
    vector<int> inDegree(n, 0); // 入度数组
    vector<int> topoOrder;      // 存储拓扑排序的结果

    // 计算每个节点的入度
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (graph.adjMatrix[u][v] != INF && u != v) {
                inDegree[v]++;
            }
        }
    }

    queue<int> q;
    // 入度为 0 的节点入队
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        // 更新相邻节点的入度
        for (int v = 0; v < n; ++v) {
            if (graph.adjMatrix[u][v] != INF && u != v) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }

    // 如果排序结果大小小于节点数，说明图中有环
    if (topoOrder.size() != n) {
        cout << "Graph has a cycle, topological sort not possible." << endl;
        return {};
    }

    return topoOrder;
}

int main() {
    int numNodes = 5;
    Graph graph(numNodes);

    // 添加有向边 (示例图)
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 2, 1);
    graph.addEdge(3, 1, 3);
    graph.addEdge(3, 4, 2);
    graph.addEdge(4, 2, 9);

    int start = 0;
    vector<int> distances = dijkstra(graph, start);
    cout << "Shortest distances from node " << start << ":" << endl;
    for (int i = 0; i < numNodes; ++i) {
        if (distances[i] == INF)
            cout << "Node " << i << ": INF" << endl;
        else
            cout << "Node " << i << ": " << distances[i] << endl;
    }

    graph.DFS(start); // 调用 DFS
    graph.BFS(start); // 调用 BFS

    vector<int> topoOrder = topologicalSort(graph);
    if (!topoOrder.empty()) {
        cout << "Topological Sort Order:" << endl;
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
