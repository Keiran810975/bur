#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = INT_MAX;

// 图的结构体，使用邻接表表示
struct Graph {
    int numNodes;
    vector<vector<pair<int, int>>> adjList; // 存储邻接表，pair<int, int>为<邻接点, 权重>

    Graph(int nodes) {
        numNodes = nodes;
        adjList.resize(numNodes);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // 对于无向图
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

            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
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
    Graph g(5); // 创建一个包含5个节点的图

    // 添加边
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
