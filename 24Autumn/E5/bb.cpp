#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define int long long
const int MAX_NODES = 550;
const int INF= LLONG_MAX;

typedef pair<int, int> pii;

int adjMatrix[MAX_NODES][MAX_NODES]; 
int dist[MAX_NODES][MAX_NODES];     
pii edges[5500];             
int numNodes, numEdges;
void dijkstra(int s) {
    vector<int> distance(numNodes + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    distance[s] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > distance[u]) continue;

        for (int v = 1; v <= numNodes; v++) {
            if (adjMatrix[u][v] != INF) {
                int newDist = distance[u] + adjMatrix[u][v];
                if (newDist < distance[v]) {
                    distance[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
    }
    for (int i = 1; i <= numNodes; i++) {
        dist[s][i] = distance[i];
    }
}
void initGraph() {
    for (int i = 0; i <= numNodes; i++) {
        for (int j = 0; j <= numNodes; j++) {
            adjMatrix[i][j] = INF;
        }
    }
}
signed main() {
    int m, q;
    cin >> numNodes >> m >> q;
    initGraph();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
        edges[i] = {u, v}; 
    }

    for (int i = 1; i <= numNodes; i++) {
        dijkstra(i);
    }

    while (q--) {
        int s, t, k;
        cin >> s >> t >> k;

        int x = edges[k].first;
        int y = edges[k].second;
        int w = adjMatrix[x][y];

        int minDis = dist[s][t];
        if( minDis == INF){
            printf("No\n");
            continue;
        }
        
        if (dist[s][x] + w + dist[y][t] == minDis || dist[s][y] + w + dist[x][t] == minDis) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
