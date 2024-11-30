#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define int long long
#define INT_MAX LLONG_MAX
using namespace std;

typedef pair<int, int> pii;  

const int MAXN = 100005;
const int MAXM = 500005;

vector<pii> adj[MAXN];
vector<int> dijkstra(int n, int start) {
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        // 初始化图
        for (int i = 1; i <= n; i++) adj[i].clear();
        
        vector<int> printShops(k);
        for (int i = 0; i < k; i++) cin >> printShops[i];
        for (int i = 0; i < m; i++) {
            int u, v, t;
            cin >> u >> v >> t;
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        vector<int> dist_from_1 = dijkstra(n, 1);
        vector<int> dist_to_n = dijkstra(n, n);
        int result = INT_MAX;
        for (int p : printShops) {
            if (dist_from_1[p] != INT_MAX && dist_to_n[p] != INT_MAX) {
                result = min(result, dist_from_1[p] + dist_to_n[p]);
            }
        }
        if (result == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << result << endl;
        }
    }
    
    return 0;
}
