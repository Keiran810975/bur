#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX; // 使用 long long 表示无穷大

struct ans {
    int a;
    long long b;
};

// 图的结构体，使用邻接表表示
struct Graph {
    int numNodes;
    vector<vector<pair<int, long long>>> adjList; // 存储邻接表，pair<int, long long>为<邻接点, 权重>

    Graph(int nodes) {
        numNodes = nodes;
        adjList.resize(numNodes);
    }

    void addEdge(int u, int v, long long weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // 对于无向图
    }

    // Dijkstra算法: 从start到所有节点的最短路径
    void Dijkstra(int start, vector<long long>& dist) {
        dist.assign(numNodes, INF);
        dist[start] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                long long weight = edge.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }
};

bool cmp(const ans& a, const ans& b) {
    return a.a < b.a; // 按照节点编号排序
}

int main() {
    int numNodes, m, s;
    long long t0;
    scanf("%d%d%d%lld", &numNodes, &m, &s, &t0);
    Graph g(numNodes);

    int u, v;
    long long t;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%lld", &u, &v, &t);
        g.addEdge(u - 1, v - 1, t); // 转换为 0 索引
    }

    vector<long long> dist;
    g.Dijkstra(s - 1, dist); // 转换为 0 索引

    vector<ans> res; // 存储不可接受的节点
    for (int i = 0; i < numNodes; i++) {
        if (dist[i] > t0) {
            res.push_back({i + 1, dist[i] == INF ? -1 : dist[i]}); // 保存节点编号和距离
        }
    }

    // 输出结果
    printf("%d\n", (int)res.size());
    sort(res.begin(), res.end(), cmp); // 根据节点编号排序
    for (const auto& r : res) {
        printf("%d %lld\n", r.a, r.b);
    }

    return 0;
}
