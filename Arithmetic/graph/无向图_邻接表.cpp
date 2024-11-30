#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <utility> // for std::pair

using namespace std;

// 邻接表存储的无向图
struct Graph {
    int numNodes; // 节点数
    vector<vector<pair<int, int>>> adjList; // 邻接表，pair<邻接节点, 权重>

    Graph(int n) : numNodes(n), adjList(n) {}// 初始化邻接表

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // 无向图添加反向边
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

vector<pair<int, pair<int, int>>> prim(const Graph& graph) {
    int n = graph.numNodes;
    vector<bool> inMST(n, false); // 标记节点是否在最小生成树中
    vector<int> parent(n, -1); // 用于记录每个节点的父节点
    vector<pair<int, pair<int, int>>> mstEdges; // 存储最小生成树的边
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // (权重, (u, v))

    // 从节点 0 开始
    inMST[0] = true;
    for (const auto& [v, weight] : graph.adjList[0]) {
        pq.emplace(weight, make_pair(0, v));
        parent[v] = 0; // 记录v的父节点
    }

    while (!pq.empty()) {
        auto [weight, edge] = pq.top();
        pq.pop();
        int u = edge.first;
        int v = edge.second;

        if (inMST[v]) continue; // 如果节点 v 已在 MST 中，跳过

        inMST[v] = true;
        mstEdges.emplace_back(weight, edge); // 添加边到 MST

        // 更新相邻节点
        for (const auto& [next, nextWeight] : graph.adjList[v]) {
            if (!inMST[next]) {
                pq.emplace(nextWeight, make_pair(v, next));
                parent[next] = v; // 记录next的父节点
            }
        }
    }

    // 打印最小生成树的边
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < n; i++) { // 从 1 开始，因为节点 0 是起始节点，没有父节点
        cout << "Edge: " << parent[i] << " - " << i << endl;
    }

    return mstEdges; // 还可以返回 mstEdges 作为其他用途
}


// Kruskal 算法
struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // 路径压缩
        }
        return parent[u];
    }

    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

vector<pair<int, pair<int, int>>> kruskal(const Graph& graph) {
    int n = graph.numNodes;
    vector<pair<int, pair<int, int>>> edges; // 存储所有边
    for (int u = 0; u < n; ++u) {
        for (const auto& [v, weight] : graph.adjList[u]) {
            if (u < v) { // 防止重复添加
                edges.emplace_back(weight, make_pair(u, v));
            }
        }
    }

    sort(edges.begin(), edges.end()); // 按权重排序
    DisjointSet ds(n);
    vector<pair<int, pair<int, int>>> mstEdges; // 存储最小生成树的边

    for (const auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (ds.find(u) != ds.find(v)) {
            ds.unionSet(u, v);
            mstEdges.push_back(edge); // 添加边到 MST
        }
    }

    return mstEdges;
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

    // 添加无向边 (示例图)
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

    // Prim
    auto primMST = prim(graph);
    cout << "Prim's MST edges:\n";
    for (const auto& [weight, edge] : primMST) {
        cout << "Edge: (" << edge.first << ", " << edge.second << ") Weight: " << weight << "\n";
    }

    // Kruskal
    auto kruskalMST = kruskal(graph);
    cout << "Kruskal's MST edges:\n";
    for (const auto& [weight, edge] : kruskalMST) {
        cout << "Edge: (" << edge.first << ", " << edge.second << ") Weight: " << weight << "\n";
    }

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
