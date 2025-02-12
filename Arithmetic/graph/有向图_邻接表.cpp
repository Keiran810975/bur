#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility> // for std::pair
#include <stack>

using namespace std;

// 邻接表存储的有向图
struct Graph {
    int numNodes; // 节点数
    vector<vector<pair<int, int>>> adjList; // 邻接表，pair<邻接节点, 权重>

    Graph(int n) : numNodes(n), adjList(n) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight); // 添加有向边
    }
};

// Dijkstra 算法
vector<int> dijkstra(const Graph& graph, int start) {
    int n = graph.numNodes;
    vector<int> dist(n, INT_MAX); // 距离数组，初始值为无穷大
    vector<bool> visited(n, false); // 标记节点是否已访问
    dist[start] = 0; // 起点到自身距离为 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 最小堆
    pq.emplace(0, start); // (距离, 节点)

    while (!pq.empty()) {
        auto [currDist, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        // 更新相邻节点的距离
        for (const auto& [v, weight] : graph.adjList[u]) {
            if (currDist + weight < dist[v]) {
                dist[v] = currDist + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

// 拓扑排序
vector<int> topologicalSort(const Graph& graph) {
    int n = graph.numNodes;
    vector<int> inDegree(n, 0); // 记录入度
    for (int u = 0; u < n; ++u) {
        for (const auto& [v, weight] : graph.adjList[u]) {
            inDegree[v]++;
        }
    }

    queue<int> q; // 入度为 0 的节点队列
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order; // 存储拓扑排序的结果
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        // 减少相邻节点的入度
        for (const auto& [v, weight] : graph.adjList[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // 检查是否有环
    if (order.size() != n) {
        cout << "图中存在环，无法进行拓扑排序。\n";
        return {}; // 返回空结果
    }

    return order;
}

// 深度优先搜索（DFS）
void dfsUtil(int u, const Graph& graph, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " "; // 访问节点

    for (const auto& [v, weight] : graph.adjList[u]) {
        if (!visited[v]) {
            dfsUtil(v, graph, visited);
        }
    }
}

void dfs(const Graph& graph) {
    vector<bool> visited(graph.numNodes, false);
    for (int i = 0; i < graph.numNodes; ++i) {
        if (!visited[i]) {
            dfsUtil(i, graph, visited);
        }
    }
}

// 广度优先搜索（BFS）
void bfs(const Graph& graph, int start) {
    vector<bool> visited(graph.numNodes, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " "; // 访问节点

        for (const auto& [v, weight] : graph.adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
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

    // Dijkstra
    int start = 0;
    vector<int> distances = dijkstra(graph, start);
    cout << "Dijkstra shortest distances from node " << start << ":\n";
    for (int i = 0; i < numNodes; ++i) {
        if (distances[i] == INT_MAX)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << distances[i] << "\n";
    }

    // 拓扑排序
    vector<int> topoOrder = topologicalSort(graph);
    cout << "Topological Sort Order:\n";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << "\n";

    // DFS
    cout << "DFS traversal:\n";
    dfs(graph);
    cout << "\n";

    // BFS
    cout << "BFS traversal starting from node 0:\n";
    bfs(graph, 0);
    cout << "\n";

    return 0;
}
