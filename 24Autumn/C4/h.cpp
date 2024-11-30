#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        in_degree[v]++;
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> topological_order;

    while (!pq.empty()) {
        int cur = pq.top(); 
        pq.pop();
        topological_order.push_back(cur);
        for (int neighbor : graph[cur]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }
    if (topological_order.size() != n) {
        return 0;
    }
    for (int i = 0; i < topological_order.size(); ++i) {
        cout << topological_order[i] << (i == topological_order.size() - 1 ? "\n" : " ");
    }

    return 0;
}
