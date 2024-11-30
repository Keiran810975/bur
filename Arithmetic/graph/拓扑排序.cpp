#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 邻接表表示图
    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0); // 记录每个节点的入度

    // 输入边信息
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        in_degree[v]++;
    }

    // 使用优先队列（大根堆）来保存入度为 0 的节点
    priority_queue<int> pq;

    // 将所有入度为 0 的节点放入优先队列
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> topological_order;

    while (!pq.empty()) {
        int cur = pq.top(); // 取出序号大的点
        pq.pop();
        topological_order.push_back(cur);

        // 对于 cur 的每一个邻居，减少其入度
        for (int neighbor : graph[cur]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                pq.push(neighbor); // 入度为 0 的邻居加入优先队列
            }
        }
    }

    // 如果拓扑排序的节点数不等于 n，说明图中存在环（但题目保证是 DAG）
    if (topological_order.size() != n) {
        cout << "There exists a cycle in the graph." << endl;
        return 0;
    }

    // 输出拓扑排序结果
    for (int i = 0; i < topological_order.size(); ++i) {
        cout << topological_order[i] << (i == topological_order.size() - 1 ? "\n" : " ");
    }

    return 0;
}
