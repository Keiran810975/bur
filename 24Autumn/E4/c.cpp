#include<iostream>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
const int MAX_NODES = 100001;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adjList[MAX_NODES]; // 邻接表，存储的是边和权重
int numNodes;
bool visited[MAX_NODES];

// 初始化
void init(int n) {
    numNodes = n;
    for (int i = 0; i < numNodes; i++) {
        adjList[i].clear(); // 清除邻接表的内容
    }
}

// 添加边
void addEdge(int u, int v, int w) {
    adjList[u].push_back({v, w});
}


// Bellman-Ford 算法
bool bellmanFord(int src) {
    vector<int> distance(numNodes, INF);
    distance[src] = 0;

    // 松弛操作：重复 V-1 次
    for (int i = 1; i <= numNodes - 1; i++) {
        for (int u = 0; u < numNodes; u++) {
            for (auto &edge : adjList[u]) {
                int v = edge.first;
                int w = edge.second;
                if (distance[u] != INF && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }

    // 检测负环：如果在第 V 次松弛后还能更新距离，则存在负环
    for (int u = 0; u < numNodes; u++) {
        for (auto &edge : adjList[u]) {
            int v = edge.first;
            int w = edge.second;
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                cout << "图中存在负环，无法计算最短路径。" << endl;
                return false;
            }
        }
    }

    for (int i = 0; i < numNodes; i++) {
        if (distance[i] == INF) {
            cout << "到节点 " << i << " 无法到达" << endl;
        } else {
            cout << "到节点 " << i << " 的最短距离是 " << distance[i] << endl;
        }
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        init(n);
        int p[m+1];
        for(int i=0;i<k;i++){
            scanf("%d",&p[i]);
        }
        int u,v,w;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
        }
    }
    return 0;
}
