#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <utility> // for std::pair

using namespace std;

// 邻接表存储的无向图
struct Graph {
    int numNodes; // 节点数
    vector<vector<pair<int, int>>> adjList; // 邻接表，pair<邻接节点, 权重>

    Graph(int n) : numNodes(n), adjList(n) {}// 初始化邻接表

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // 无向图添加反向边
    }
};

vector<pair<int, pair<int, int>>> prim(const Graph& graph) {
    int n = graph.numNodes;
    vector<bool> inMST(n, false); // 标记节点是否在最小生成树中
    vector<int> parent(n, -1); // 用于记录每个节点的父节点
    vector<pair<int, pair<int, int>>> mstEdges; // 存储最小生成树的边
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // (权重, (u, v))

    // 从节点 0 开始
    inMST[0] = true;
    for (const auto& [v, weight] : graph.adjList[0]) {
        pq.emplace(weight, make_pair(0, v));
        parent[v] = 0; // 记录v的父节点
    }

    while (!pq.empty()) {
        auto [weight, edge] = pq.top();
        pq.pop();
        int u = edge.first;
        int v = edge.second;

        if (inMST[v]) continue; // 如果节点 v 已在 MST 中，跳过

        inMST[v] = true;
        mstEdges.emplace_back(weight, edge); // 添加边到 MST

        // 更新相邻节点
        for (const auto& [next, nextWeight] : graph.adjList[v]) {
            if (!inMST[next]) {
                pq.emplace(nextWeight, make_pair(v, next));
                parent[next] = v; // 记录next的父节点
            }
        }
    }

    // 打印最小生成树的边
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < n; i++) { // 从 1 开始，因为节点 0 是起始节点，没有父节点
        cout << "Edge: " << parent[i] << " - " << i << endl;
    }

    return mstEdges; // 还可以返回 mstEdges 作为其他用途
}


// Kruskal 算法
struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // 路径压缩
        }
        return parent[u];
    }

    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

vector<pair<int, pair<int, int>>> kruskal(const Graph& graph) {
    int n = graph.numNodes;
    vector<pair<int, pair<int, int>>> edges; // 存储所有边
    for (int u = 0; u < n; ++u) {
        for (const auto& [v, weight] : graph.adjList[u]) {
            if (u < v) { // 防止重复添加
                edges.emplace_back(weight, make_pair(u, v));
            }
        }
    }

    sort(edges.begin(), edges.end()); // 按权重排序
    DisjointSet ds(n);
    vector<pair<int, pair<int, int>>> mstEdges; // 存储最小生成树的边

    for (const auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (ds.find(u) != ds.find(v)) {
            ds.unionSet(u, v);
            mstEdges.push_back(edge); // 添加边到 MST
        }
    }

    return mstEdges;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        Graph g(n+5);
        int u,v,h;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&h);
            g.addEdge(u,v,h);
        }
        auto mst=kruskal(g);
        //遍历
        int mmax=0;
        for(const auto& [weight, edge] :mst){
            if(weight>mmax){
                mmax=weight;
            }
        }
        printf("%d\n",mmax);
    }
    
    return 0;
}
