#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // 建立图
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    
    int S, T;
    cin >> S >> T;
    
    // BFS 队列，存储节点以及当前步数
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n + 1, vector<bool>(4, false));  // 记录每个节点是否已访问
    
    q.push({S, 0});
    visited[S][0] = true;
    
    // BFS
    while (!q.empty()) {
        auto [node, steps] = q.front();
        q.pop();
        
        // 如果已经到达目标节点，且走了 3 步
        if (node == T && steps == 3) {
            cout << steps / 3 << endl;
            return 0;
        }
        
        // 如果步数小于 3，则继续沿着当前节点扩展
        if (steps < 3) {
            for (int next : graph[node]) {
                if (!visited[next][steps + 1]) {
                    visited[next][steps + 1] = true;
                    q.push({next, steps + 1});
                }
            }
        }
    }
    
    cout << -1 << endl;  // 无法达到 T
    return 0;
}
