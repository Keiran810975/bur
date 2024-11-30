#include<iostream>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
const int MAX_NODES = 100001;
const int INF = 0x3f3f3f3f;

    vector<pair<int, int>> adjList[MAX_NODES]; // 邻接表，存储的是边和权重
    int numNodes;
    bool visited[MAX_NODES];

    // 初始化
    void init(int n) {
        numNodes = n;
        for (int i = 0; i < numNodes; i++) {
            adjList[i].clear(); // 清除邻接表的内容
        }
    }

    // 添加边
    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
    }

    // DFS 遍历图节点
    void dfs(int node) {
        visited[node] = true;
        printf("%d ", node);

        for (auto &edge : adjList[node]) {
            int neighbor = edge.first;
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
    }

    // 清除访问状态
    void resetVisited() {
        memset(visited, false, sizeof(visited));
    }

    // BFS
    void bfs(int start) {
        vector<bool> visited(numNodes, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            printf("%d ", v);

            for (auto &edge : adjList[v]) {
                int neighbor = edge.first;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        printf("\n");
    }

    // 拓扑排序 (Kahn 算法)
    bool topologicalSort() {
        vector<int> inDegree(numNodes, 0);

        // 计算每个节点的入度
        for (int i = 0; i < numNodes; i++) {
            for (auto &edge : adjList[i]) {
                int v = edge.first;
                inDegree[v]++;
            }
        }

        // 将入度为 0 的节点加入队列
        queue<int> q;
        for (int i = 0; i < numNodes; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder; // 存储拓扑排序结果

        // 进行拓扑排序
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            // 将当前节点的邻接节点的入度减 1
            for (auto &edge : adjList[node]) {
                int v = edge.first;
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // 检查是否存在环
        if (topoOrder.size() != numNodes) {
            return false;
        }

        // 输出拓扑排序结果
        for (int node : topoOrder) {
            printf("%d ", node);
        }
        printf("\n");
        return true;
    }


//---------Kruskal---------

    // 查找并查集
    int find(int parent[], int i) {
        if (parent[i] == -1) 
            return i;
        return find(parent, parent[i]);
    }

    // 合并并查集
    void Union(int parent[], int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (xroot != yroot) {
            parent[xroot] = yroot;
        }
    }

    // Kruskal 算法求最小生成树
    void kruskalMST() {
        vector<pair<int, pair<int, int>>> edges; // 存储边 (权重, (u, v))

        // 把所有边放入边列表
        for (int u = 0; u < numNodes; u++) {
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                if (u < v) { // 防止重复加入无向图的边
                    edges.push_back({w, {u, v}});
                }
            }
        }

        // 按照边的权重升序排序
        sort(edges.begin(), edges.end());

        int parent[numNodes];
        fill(parent, parent + numNodes, -1); // 初始化并查集

        vector<pair<int, int>> mst; // 存储最小生成树的边
        int mstWeight = 0;

        // 逐个遍历边，按权重从小到大选边
        for (auto& edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int weight = edge.first;

            int x = find(parent, u);
            int y = find(parent, v);

            if (x != y) { // 如果u和v不在同一个集合，加入最小生成树
                mst.push_back({u, v});
                mstWeight += weight;
                Union(parent, x, y); // 合并u和v的集合
            }
        }

        // 输出最小生成树
        cout << "最小生成树的边及其权重:" << endl;
        for (auto& edge : mst) {
            cout << edge.first << " - " << edge.second << endl;
        }
        cout << "最小生成树的总权重: " << mstWeight << endl;
    }

    

    // Floyd 最短路径
    void floydShortestPath() {
        vector<vector<int>> dist(numNodes, vector<int>(numNodes, INF));

        // 初始化距离矩阵
        for (int i = 0; i < numNodes; i++) {
            for (auto &edge : adjList[i]) {
                int v = edge.first;
                dist[i][v] = edge.second;
            }
        }

        // Floyd-Warshall 算法
        for (int k = 0; k < numNodes; k++) {
            for (int i = 0; i < numNodes; i++) {
                for (int j = 0; j < numNodes; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
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

    // Bellman-Ford 算法
    bool bellmanFord(int src) {
        vector<int> distance(numNodes, INF);
        distance[src] = 0;

        // 松弛操作：重复 V-1 次
        for (int i = 1; i <= numNodes - 1; i++) {
            for (int u = 0; u < numNodes; u++) {
                for (auto &edge : adjList[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    if (distance[u] != INF && distance[u] + w < distance[v]) {
                        distance[v] = distance[u] + w;
                    }
                }
            }
        }

        // 检测负环：如果在第 V 次松弛后还能更新距离，则存在负环
        for (int u = 0; u < numNodes; u++) {
            for (auto &edge : adjList[u]) {
                int v = edge.first;
                int w = edge.second;
                if (distance[u] != INF && distance[u] + w < distance[v]) {
                    cout << "图中存在负环，无法计算最短路径。" << endl;
                    return false;
                }
            }
        }

        // 输出最短路径结果
        for (int i = 0; i < numNodes; i++) {
            if (distance[i] == INF) {
                cout << "到节点 " << i << " 无法到达" << endl;
            } else {
                cout << "到节点 " << i << " 的最短距离是 " << distance[i] << endl;
            }
        }
        return true;
    }

    // Dijkstra 算法
    void dijkstra(int src) {
        vector<int> distance(numNodes, INF); // 存储最短距离
        vector<bool> visited(numNodes, false); // 标记节点是否已访问

        distance[src] = 0;

        for (int i = 0; i < numNodes - 1; i++) {
            // 找到未访问的节点中距离源节点最近的节点
            int minDist = INF, u;
            for (int v = 0; v < numNodes; v++) {
                if (!visited[v] && distance[v] < minDist) {
                    minDist = distance[v];
                    u = v;
                }
            }

            visited[u] = true;

            // 更新邻接节点的距离
            for (auto &edge : adjList[u]) {
                int v = edge.first;
                int w = edge.second;
                if (!visited[v] && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                }
            }
        }

        // 输出从 src 节点到其他节点的最短距离
        cout << "从节点 " << src << " 到其他节点的最短距离：" << endl;
        for (int i = 0; i < numNodes; i++) {
            if (distance[i] == INF) {
                cout << "到节点 " << i << " 无法到达" << endl;
            } else {
                cout << "到节点 " << i << " 的最短距离是 " << distance[i] << endl;
            }
        }
    }

int main() {
    

    return 0;
}
