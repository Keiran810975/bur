#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    long long g[305][305];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            g[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
    }

    int q;
    cin >> q; 
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        //Dijkstra
        vector<long long> d(n + 1, INF);
        vector<bool> vis(n + 1, false);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        d[u] = 0;
        pq.push({0, u});
        while (!pq.empty()) {
            pair<long long, int> cur = pq.top();
            pq.pop();

            long long cur_d = cur.first;
            int cur_node = cur.second;
            if (vis[cur_node]) continue;
            vis[cur_node] = true;
            for (int j = 1; j <= n; ++j) {
                if (g[cur_node][j] != INF && !vis[j]) {
                    long long new_d = cur_d + g[cur_node][j];
                    if (new_d < d[j]) {
                        d[j] = new_d;
                        pq.push({d[j], j});
                    }
                }
            }
        }
        if (d[v] == INF) {
            cout << -1 << endl;
        } else {
            cout << d[v] << endl;
        }
    }

    return 0;
}
