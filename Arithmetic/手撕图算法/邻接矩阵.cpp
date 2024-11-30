#include<iostream>
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX_NODES=100;
const int INF=INT_MAX;

struct Graph{
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
    bool visited[MAX_NODES];

    //初始化
    void init(int n){
        numNodes=n;
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                adjMatrix[i][j] = (i == j) ? 0 : INF; // 初始化为无穷大
            }
        }
    }

    //添加边
    void addEdge(int u,int v,int w){
        adjMatrix[u][v]=w;
    }

    //dfs遍历图节点
    void dfs(int node) {
        visited[node] = true;
        printf("%d ",node);

        for (int i = 0; i < numNodes; i++) {
            if (adjMatrix[node][i] != INF && !visited[i]) { // 检查有边且未访问
                dfs(i);
            }
        }
    }

    // 清除访问状态
    void resetVisited() {
        memset(visited, false, sizeof(visited));
    }
    
    //bfs
    void bfs(int start) {
        vector<bool> visited(numNodes, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            printf("%d ", v);

            for (int i = 0; i < numNodes; i++) {
                if (adjMatrix[v][i] != INF && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        printf("\n");
    }


    //拓扑排序(kahn)
    bool topologicalSort() {
        vector<int> inDegree(numNodes, 0);

        // 计算每个节点的入度
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (adjMatrix[i][j] != INF && adjMatrix[i][j] != 0) {
                    inDegree[j]++;
                }
            }
        }

        // 将入度为0的节点加入队列
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

            // 将当前节点的邻接节点的入度减1
            for (int i = 0; i < numNodes; i++) {
                if (adjMatrix[node][i] != INF && adjMatrix[node][i] != 0) {
                    inDegree[i]--;
                    if (inDegree[i] == 0) {
                        q.push(i);
                    }
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

    //prim最小生成树
    void primMST() {
        vector<int> key(numNodes, INF); // 节点的权值
        vector<bool> inMST(numNodes, false); // 节点是否在MST中
        vector<int> parent(numNodes, -1); // 用于存储最小生成树

        key[0] = 0; // 从第一个节点开始
        parent[0] = -1; // 根节点没有父节点

        for (int i = 0; i < numNodes - 1; i++) {
            // 找到未包含在MST中的权值最小的节点
            int minKey = INF, u;
            for (int v = 0; v < numNodes; v++) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            // 将选定的节点加入MST
            inMST[u] = true;

            // 更新该节点的邻接节点的权值
            for (int v = 0; v < numNodes; v++) {
                if (adjMatrix[u][v] != INF && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    key[v] = adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }

        // 输出最小生成树的边和权重
        for (int i = 1; i < numNodes; i++) {
            if (parent[i] != -1) {
                cout << "Edge " << parent[i] << " - " << i << " Weight: " << adjMatrix[i][parent[i]] <<endl;
            }
        }
    }
    
    //floyd最短路径
    void floydShortestPath() {
        vector<vector<int>> dist(numNodes, vector<int>(numNodes, INF));

        // 初始化距离矩阵
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (adjMatrix[i][j] != INF) {
                    dist[i][j] = adjMatrix[i][j];
                }
            }
        }

        // Floyd-Warshall算法
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

    //Bellman-Ford算法
    //src是起点
    bool bellmanFord(int src) {
        vector<int> distance(numNodes, INF);
        distance[src] = 0;

        // 松弛操作：重复 V-1 次
        for (int i = 1; i <= numNodes - 1; i++) {
            for (int u = 0; u < numNodes; u++) {
                for (int v = 0; v < numNodes; v++) {
                    if (adjMatrix[u][v] != INF && distance[u] != INF && distance[u] + adjMatrix[u][v] < distance[v]) {
                        distance[v] = distance[u] + adjMatrix[u][v];
                    }
                }
            }
        }

        // 检测负环：如果在第 V 次松弛后还能更新距离，则存在负环
        for (int u = 0; u < numNodes; u++) {
            for (int v = 0; v < numNodes; v++) {
                if (adjMatrix[u][v] != INF && distance[u] != INF && distance[u] + adjMatrix[u][v] < distance[v]) {
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
                cout << "到节点 " << i << " 的最短距离是 " << distance[i] <<endl;
            }
        }
        return true;
    }

    //Dijkstra算法
    void dijkstra(int src) {
        vector<int> distance(numNodes, INF); // 存储最短距离
        vector<bool> visited(numNodes, false); // 标记节点是否已访问
        vector<int> parent(numNodes, -1); // 存储最短路径的前驱节点

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
            for (int v = 0; v < numNodes; v++) {
                if (!visited[v] && adjMatrix[u][v] != INF && distance[u] != INF &&
                    distance[u] + adjMatrix[u][v] < distance[v]) {
                    distance[v] = distance[u] + adjMatrix[u][v];
                }
            }
        }

        // 输出从src节点到其他节点的最短距离
        cout << "从节点 " << src << " 到其他节点的最短路径距离：" << endl;
        for (int i = 0; i < numNodes; i++) {
            if (distance[i] == INF) {
                cout << "到节点 " << i << " 无法到达" << endl;
            } else {
                cout << "到节点 " << i << " 的最短距离是 " << distance[i] << endl;
            }
        }
    }
};

int main() {
    Graph g;
    int n = 6;
    g.init(n);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 9);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 5, 7);

    printf("DFS Traversal from node 0: ");
    g.resetVisited(); // Reset visited array
    g.dfs(0);
    printf("\n");

    printf("BFS Traversal from node 0: ");
    g.bfs(0);
    printf("\n");

    printf("Topological Sort (Kahn's Algorithm): ");
    if (!g.topologicalSort()) {
        printf("The graph has a cycle.\n");
    }

    printf("Prim's Minimum Spanning Tree:\n");
    g.primMST();

    printf("Floyd-Warshall Shortest Path:\n");
    g.floydShortestPath();

    printf("Bellman-Ford Shortest Path from node 0:\n");
    g.bellmanFord(0);

    printf("Dijkstra's Shortest Path from node 0:\n");
    g.dijkstra(0);

    return 0;
}