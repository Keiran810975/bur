#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX_NODES = 300;
const int INF = INT_MAX;

struct Graph {
    vector<vector<pair<int, int>>> adjList; // 邻接表，存储图的信息
    int numNodes;

    Graph(int nodes) {
        numNodes = nodes;
        adjList.resize(nodes + 1); // 1-based index
    }

    // 添加边
    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
    }

    // 使用 Dijkstra 计算从 u 到 v 的最短路径，不经过 s
    int dijkstra(int u, int v, int s) {
        vector<int> dist(numNodes + 1, INF);
        dist[u] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, u});

        while (!pq.empty()) {
            int curDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (curDist > dist[node]) continue;
            if (node == v) return dist[node];

            for (auto& edge : adjList[node]) {
                int nextNode = edge.first;
                int weight = edge.second;

                // 如果经过 s 节点，跳过
                if (nextNode == s) continue;

                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return INF; // 如果不可达
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    Graph g(n);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int last = 0;  // last的初始值
    for (int i = 0; i < q; i++) {
        cin >> u >> v >> w;
        // 根据 last 计算真实的 u, v, s
        u = (u + last - 1) % n + 1;
        v = (v + last - 1) % n + 1;
        w = (w + last - 1) % n + 1;

        // 求不经过 s 的最短路径
        int result = g.dijkstra(u, v, w);
        if (result == INF) {
            cout << "0" << endl;
            last = 0;
        } else {
            cout << result << endl;
            last = result;
        }
    }

    return 0;
}
