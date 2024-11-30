#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX_NODES = 210;
const int INF = LLONG_MAX;

vector<pair<int, int>> adjList[MAX_NODES];
unordered_map<int, unordered_map<int, int>> capacity;
int numNodes;
int level[MAX_NODES];
int ptr[MAX_NODES];

// 初始化图
void init(int n) {
    numNodes = n;
    for (int i = 0; i < numNodes; i++) {
        adjList[i].clear();
    }
    capacity.clear();
}

// 添加边 (u -> v, 容量 w)
void addEdge(int u, int v, int w) {
    if (u == v) return;

    if (capacity[u][v]) {
        capacity[u][v] += w;
        return;
    }

    adjList[u].push_back({v, adjList[v].size()});
    adjList[v].push_back({u, adjList[u].size() - 1});
    capacity[u][v] = w;
    capacity[v][u] = 0;
}

// 使用BFS构建层次图
bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& edge : adjList[u]) {
            int v = edge.first;
            if (level[v] == -1 && capacity[u][v] > 0) {
                level[v] = level[u] + 1;
                if (v == t) return true;
                q.push(v);
            }
        }
    }

    return false;
}

// 使用DFS寻找增广路径
int dfs(int u, int t, int flow) {
    if (u == t) return flow;

    for (; ptr[u] < adjList[u].size(); ptr[u]++) {
        int v = adjList[u][ptr[u]].first;
        int revIdx = adjList[u][ptr[u]].second;

        if (level[v] == level[u] + 1 && capacity[u][v] > 0) {
            int minFlow = min(flow, capacity[u][v]);
            int pushed = dfs(v, t, minFlow);

            if (pushed > 0) {
                capacity[u][v] -= pushed;
                capacity[v][u] += pushed;
                return pushed;
            }
        }
    }

    return 0;
}

// Dinic算法计算最大流
int dinic(int s, int t) {
    int maxFlow = 0;

    while (true) {
        if (!bfs(s, t)) break;

        memset(ptr, 0, sizeof(ptr));

        while (true) {
            int flow = dfs(s, t, INF);
            if (flow == 0) break;
            maxFlow += flow;
        }
    }

    return maxFlow;
}

signed main() {
    ios::sync_with_stdio(false);
    int k;
    cin>>k;
    while(k--){
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        init(n);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }

        cout << dinic(s, t) << endl;
}
    return 0;
}
