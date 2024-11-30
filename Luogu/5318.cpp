#include<iostream>
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX_NODES=30;
const int INF=INT_MAX;


struct Graph{
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
    bool visited[MAX_NODES];

    //初始化
    void init(int n){
        numNodes=n;
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                adjMatrix[i][j] = (i == j) ? 0 : INF; // 初始化为无穷大
            }
        }
    }

    //添加边
    void addEdge(int u,int v,int w){
        adjMatrix[u][v]=w;
    }

    //dfs遍历图节点
    void dfs(int node) {
        visited[node] = true;
        printf("%d ", node);

        for (int i = 1; i <= numNodes; i++) {
            if (adjMatrix[node][i] != INF && !visited[i]) { // 检查有边且未访问
                dfs(i);
            }
        }
    }

    // 清除访问状态
    void resetVisited() {
        memset(visited, false, sizeof(visited));
    }
    
    //bfs
    void bfs(int start) {
        vector<bool> visited(numNodes, false);
        priority_queue<int , vector<int> , greater<int> > pq;
        //queue<int> q;

        visited[start] = true;
        pq.push(start);

        while (!pq.empty()) {
            int v = pq.top();
            pq.pop();
            printf("%d ", v);

            for (int i = 1; i <= numNodes; i++) {
                if (adjMatrix[v][i] != INF && !visited[i]) {
                    visited[i] = true;
                    pq.push(i);
                }
            }
        }
        printf("\n");
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    Graph g; 
    g.init(n); 
    int u,v;
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        g.addEdge(u,v,1);
    }
    g.resetVisited();
    g.dfs(1);
    printf("\n");
    g.bfs(1);

    
    return 0;
}