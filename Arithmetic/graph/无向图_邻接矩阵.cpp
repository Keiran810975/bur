#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_NODES = 100;
const int INF = INT_MAX;

// 图的结构体
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

    //最小生成树：稠密图用prim，稀疏图用kruskal
    //即邻接矩阵+prim，邻接表+kruskal

    // Prim算法: 最小生成树
    void PrimMST() {
    vector<int> key(numNodes, INF);//记录与生成树相连的边的最小权重
    vector<bool> inMST(numNodes, false);//标记每个节点是否已包含在最小生成树中
    vector<int> parent(numNodes, -1); // 记录每个节点的父节点（用于输出生成树的边），初始时所有元素为-1，表示没有父节点。
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // 最小堆

    key[0] = 0;
    minHeap.push({0, 0}); // {权重, 节点}

    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();

        if (inMST[u]) continue; // 如果这个节点已经在MST中，则跳过

        inMST[u] = true;

        for (int v = 0; v < numNodes; v++) {
            // 只考虑有效的边
            if (adjMatrix[u][v] != INF && !inMST[v] && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                parent[v] = u; // 更新父节点
                minHeap.push({key[v], v}); // 将新的边加入到最小堆
            }
        }
    }

    cout << "Minimum Spanning Tree using Prim's Algorithm:" << endl;
    int mstCost = 0;
    for (int i = 1; i < numNodes; i++) {
        if (parent[i] != -1) {
            cout << "Edge: " << parent[i] << " - " << i << " Weight: " << adjMatrix[parent[i]][i] << endl;
            mstCost += adjMatrix[parent[i]][i];
        }
    }
    cout << "Total cost: " << mstCost << endl;
}

    // Kruskal算法: 最小生成树
    struct Edge {
        int u, v, weight;
        bool operator<(const Edge &e) const { return weight < e.weight; }
    };

    vector<Edge> edges;

    void addEdgeKruskal(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    int findSet(int u, vector<int> &parent) {
        if (u != parent[u]) parent[u] = findSet(parent[u], parent);
        return parent[u];
    }

    void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
        u = findSet(u, parent);
        v = findSet(v, parent);
        if (u != v) {
            if (rank[u] < rank[v]) swap(u, v);
            parent[v] = u;
            if (rank[u] == rank[v]) rank[u]++;
        }
    }

    void KruskalMST() {
        sort(edges.begin(), edges.end());
        vector<int> parent(numNodes), rank(numNodes, 0);
        for (int i = 0; i < numNodes; i++) parent[i] = i;

        int mstCost = 0;
        cout << "Minimum Spanning Tree using Kruskal's Algorithm:" << endl;
        for (auto &edge : edges) {
            int u = edge.u, v = edge.v, weight = edge.weight;
            if (findSet(u, parent) != findSet(v, parent)) {
                cout << "Edge: " << u << " - " << v << " Weight: " << weight << endl;
                mstCost += weight;
                unionSets(u, v, parent, rank);
            }
        }
        cout << "Total cost: " << mstCost << endl;
    }
    
    // Dijkstra算法: 最短路径
    void Dijkstra(int start) {
        vector<int> dist(numNodes, INF);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (int v = 0; v < numNodes; v++) {
                if (adjMatrix[u][v] != INF && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from node " << start << ":" << endl;
        for (int i = 0; i < numNodes; i++) {
            cout << "Node " << i << " : " << dist[i] << endl;
        }
    }

    // DFS
    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < numNodes; i++) {
            if (adjMatrix[v][i] != INF && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(numNodes, false);
        cout << "DFS starting from node " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // BFS
    void BFS(int start) {
        vector<bool> visited(numNodes, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);
        cout << "BFS starting from node " << start << ": ";

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i = 0; i < numNodes; i++) {
                if (adjMatrix[v][i] != INF && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    int numNodes = 5;

    g.initialize(numNodes);

    // 为 Prim 和 Dijkstra 添加边
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    cout << "Prim's MST:\n";
    g.PrimMST();

    cout << "\nDijkstra's Shortest Path starting from node 0:\n";
    g.Dijkstra(0);

    cout << "\nDFS traversal:\n";
    g.DFS(0);

    cout << "\nBFS traversal:\n";
    g.BFS(0);

    Graph g2;
    g2.initialize(numNodes);

    // 为 Kruskal 和拓扑排序添加边
    g2.addEdgeKruskal(0, 1, 2);
    g2.addEdgeKruskal(0, 3, 6);
    g2.addEdgeKruskal(1, 3, 8);
    g2.addEdgeKruskal(1, 4, 5);
    g2.addEdgeKruskal(1, 2, 3);
    g2.addEdgeKruskal(2, 4, 7);
    g2.addEdgeKruskal(3, 4, 9);

    cout << "\nKruskal's MST:\n";
    g2.KruskalMST();

    return 0;
}
