#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX_NODES = 2000;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adjList[MAX_NODES];
int numNodes;

// 初始化图
void init(int n) {
    numNodes = n;
    for (int i = 0; i < numNodes; i++) {
        adjList[i].clear();
    }
}

// 添加边
void addEdge(int u, int v, int w) {
    u--; // 转为 0 基准
    v--;
    adjList[u].push_back({v, w});
    adjList[v].push_back({u, w});
}

// 查找并查集
int find(int parent[], int i) {
    if (parent[i] == -1) 
        return i;
    return parent[i] = find(parent, parent[i]); // 路径压缩
}

// 合并并查集
void Union(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (xroot != yroot) {
        parent[xroot] = yroot;
    }
}

// Kruskal
int kruskalMST() {
    vector<pair<int, pair<int, int>>> edges;
    for (int u = 0; u < numNodes; u++) {
        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            if (u < v) {
                edges.push_back({w, {u, v}});
            }
        }
    }
    sort(edges.begin(), edges.end());

    int parent[MAX_NODES];
    fill(parent, parent + numNodes, -1); 

    vector<pair<int, int>> mst; 
    int mstWeight = 0;
    for (auto& edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int weight = edge.first;

        int x = find(parent, u);
        int y = find(parent, v);

        if (x != y) {
            mst.push_back({u, v});
            mstWeight += weight;
            Union(parent, x, y); 
        }
    }
    return mstWeight;
}

int main() {
    int m;
    cin >> numNodes >> m;
    init(numNodes);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    printf("%d\n", kruskalMST());
    return 0;
}
