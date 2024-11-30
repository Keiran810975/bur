#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_NODES = 200;
const int INF = 1e9; // 设置一个大数表示无穷大

// 邻接表存储边和容量
vector<pair<int, int>> adjList[MAX_NODES];  // 正向边
vector<pair<int, int>> adjRevList[MAX_NODES]; // 反向边
int level[MAX_NODES];  // 用于BFS的层次信息
int ptr[MAX_NODES];    // 用于DFS的指针
int revEdgeIdx[MAX_NODES][MAX_NODES];  // 记录反向边的位置

// 初始化图
void init(int n) {
    for (int i = 0; i < n; i++) {
        adjList[i].clear();
        adjRevList[i].clear();
    }
}

// 添加边 (u -> v, 容量 w)
void addEdge(int u, int v, int w) {
    bool found = false;
    for (auto& edge : adjList[u]) {
        if (edge.first == v) {
            edge.second += w;  // 如果已经存在u -> v的边，增加容量
            found = true;
            break;
        }
    }
    if (!found) {
        adjList[u].push_back({v, w});
    }

    // 反向边初始化为0
    bool revFound = false;
    for (auto& edge : adjList[v]) {
        if (edge.first == u) {
            revFound = true;
            break;
        }
    }
    if (!revFound) {
        adjList[v].push_back({u, 0});
    }
}

// 使用BFS构建层次图
bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));  // 初始化层次信息
    queue<int> q;
    q.push(s);
    level[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& edge : adjList[u]) {
            int v = edge.first;
            int cap = edge.second;

            if (level[v] == -1 && cap > 0) {  // 只有容量大于0的边才会被探索
                level[v] = level[u] + 1;
                if (v == t) return true;  // 如果到达汇点t，直接返回
                q.push(v);
            }
        }
    }

    return false;  // 如果没有路径从s到t
}

// 使用DFS寻找增广路径
int dfs(int u, int t, int flow) {
    if (u == t) return flow;

    for (; ptr[u] < adjList[u].size(); ptr[u]++) {
        int v = adjList[u][ptr[u]].first;
        int& cap = adjList[u][ptr[u]].second;

        if (level[v] == level[u] + 1 && cap > 0) {
            int minFlow = min(flow, cap);
            int pushed = dfs(v, t, minFlow);

            if (pushed > 0) {
                cap -= pushed;  // 更新正向边流量
                adjRevList[v][revEdgeIdx[u][v]].second += pushed; // 更新反向边流量
                return pushed;
            }
        }
    }

    return 0;  // 如果没有增广路径，返回0
}

// Dinic算法计算最大流
int dinic(int s, int t) {
    int maxFlow = 0;

    // 不断进行BFS和DFS，直到找不到增广路径
    while (true) {
        if (!bfs(s, t)) break;  // 如果没有增广路径，结束

        memset(ptr, 0, sizeof(ptr));

        while (true) {
            int flow = dfs(s, t, INF);
            if (flow == 0) break;
            maxFlow += flow;  // 累加流量
        }
    }

    return maxFlow;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        init(n);

        int u, v, w;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }

        cout << dinic(s, t) << endl;
    }

    return 0;
}
