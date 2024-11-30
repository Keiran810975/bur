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

    // Dijkstra算法: 从start到所有节点的最短路径
    void Dijkstra(int start, vector<int>& dist) {
        dist.assign(numNodes, INF);
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
    }

    // 求两点之间的最近距离
    int ShortestPath(int start, int end) {
        vector<int> dist;
        Dijkstra(start, dist);
        return dist[end];
    }
};

int main() {
    Graph g;
    int numNodes = 5;

    g.initialize(numNodes);
    // 为图添加边
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    int startNode = 0, endNode = 4;
    int distance = g.ShortestPath(startNode, endNode);
    
    if (distance == INF) {
        cout << "There is no path from node " << startNode << " to node " << endNode << "." << endl;
    } else {
        cout << "The shortest distance from node " << startNode << " to node " << endNode << " is: " << distance << endl;
    }

    return 0;
}
