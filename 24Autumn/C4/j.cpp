#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
#define int long long
// 邻接表存储的无向图
struct Graph {
    int numNodes; // 节点数
    vector<vector<int>> adjList; // 邻接表

    Graph(int n) : numNodes(n), adjList(n + 1) {} // 初始化邻接表

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // 无向图添加反向边
    }
};

// 执行 BFS，返回最远的不同颜色节点的距离和该节点编号
pair<int, int> bfs(int startNode, int targetColor, const Graph &graph, const vector<int> &colors) {
    vector<int> distance(graph.numNodes + 1, -1);
    queue<int> q;
    q.push(startNode);
    distance[startNode] = 0;

    int maxDist = 0;
    int farthestNode = startNode;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph.adjList[node]) {
            if (distance[neighbor] == -1) { // 如果未访问过
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);

                // 如果找到目标颜色节点，更新最远距离
                if (colors[neighbor] == targetColor && distance[neighbor] > maxDist) {
                    maxDist = distance[neighbor];
                    farthestNode = neighbor;
                }
            }
        }
    }

    return {farthestNode, maxDist};
}
pair<int, int> bfs2(int startNode, const Graph &graph, const vector<int> &colors) {
    vector<int> distance(graph.numNodes + 1, -1);
    queue<int> q;
    q.push(startNode);
    distance[startNode] = 0;

    int maxDist = 0;
    int farthestNode = startNode;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph.adjList[node]) {
            if (distance[neighbor] == -1) { // 如果未访问过
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);

                // 如果找到目标颜色节点，更新最远距离
                if ( distance[neighbor] > maxDist) {
                    maxDist = distance[neighbor];
                    farthestNode = neighbor;
                }
            }
        }
    }

    return {farthestNode, maxDist};
}

signed main() {
    int numNodes;
    scanf("%lld", &numNodes);

    vector<int> colors(numNodes + 1);
    for (int i = 1; i <= numNodes; i++) {
        scanf("%lld", &colors[i]);
    }

    Graph graph(numNodes);
    int u, v;
    for (int i = 0; i < numNodes - 1; i++) {
        scanf("%lld%lld", &u, &v);
        graph.addEdge(u, v);
    }

    // 找到第一个不同颜色节点
    int startNode = 1;
    while (colors[startNode] == colors[1]) startNode++;

    // 第一次 BFS
    auto result1 = bfs(startNode, colors[startNode] ^ 1,graph, colors);
    int farthestNode = result1.first;

    // 第二次 BFS
    auto result2 = bfs(farthestNode, colors[farthestNode] ^ 1, graph, colors);
    int maxDistance = result2.second;

    printf("%lld\n", maxDistance);

    return 0;
}
