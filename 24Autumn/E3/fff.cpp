#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        // 输入网格的颜色
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        // 构建图结构
        vector<vector<int>> graph(n * m + 2 * (n + m));
        
        // 行虚拟节点连接
        for (int i = 0; i < n; i++) {
            int rowBlack = n * m + 2 * i;
            int rowWhite = n * m + 2 * i + 1;
            for (int j = 0; j < m; j++) {
                int id = i * m + j;
                if (grid[i][j] == 0) {
                    graph[id].push_back(rowBlack);
                    graph[rowBlack].push_back(id);
                } else {
                    graph[id].push_back(rowWhite);
                    graph[rowWhite].push_back(id);
                }
            }
        }

        // 列虚拟节点连接
        for (int j = 0; j < m; j++) {
            int colBlack = n * m + 2 * n + 2 * j;
            int colWhite = n * m + 2 * n + 2 * j + 1;
            for (int i = 0; i < n; i++) {
                int id = i * m + j;
                if (grid[i][j] == 0) {
                    graph[id].push_back(colWhite); // 黑色格子连接到白色虚拟节点
                    graph[colWhite].push_back(id);
                } else {
                    graph[id].push_back(colBlack); // 白色格子连接到黑色虚拟节点
                    graph[colBlack].push_back(id);
                }
            }
        }

        // BFS 寻找最短路径
        vector<int> visited(n * m + 2 * (n + m), -1);
        queue<pair<int, int>> q;
        q.push({0, 0}); // 起点 (0,0)
        visited[0] = 0;

        int target = n * m - 1;
        int minSteps = -1;

        while (!q.empty()) {
            auto [current, steps] = q.front(); q.pop();

            if (current == target) { // 到达终点
                minSteps = steps;
                break;
            }

            for (int next : graph[current]) {
                if (visited[next] == -1) {
                    visited[next] = steps + 1;
                    q.push({next, steps + 1});
                }
            }
        }

        // 输出结果
        cout << (minSteps == -1 ? -1 : minSteps / 2) << '\n';
    }

    return 0;
}
