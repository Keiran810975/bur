#include <bits/stdc++.h>
using namespace std;

#define MAX 2147483647  // 最大容量，表示无穷大的值
long long graph[210][210];  // 邻接矩阵，存储图的容量
map<int, map<int, long long>> last;  // 邻接表,key是当前点，value->first是邻接的点，second 是边长
vector<long long> c(210, MAX);  // 存储每个节点的剩余容量（初始为无穷大）
long long re[210];  // 存储每个节点的流量信息（用于记录最大流）
int depth[210];  // 存储节点的层次（用于BFS）
vector<int> path(210, -1);  // 存储增广路径（暂时没有使用到）
int cur[210];  // 当前节点在其邻接表中的指针，DFS时用于遍历邻接边

// BFS，找层次图
bool bfs(int i, int t)
{
    memset(depth, 0, sizeof(depth));  // 初始化层次数组
    queue<int> q;  // 用于BFS的队列
    q.push(i);  // 从源点s开始
    depth[i] = 1;  // 源点的层次设为1
    cur[i] = 0;  // 当前指针置为0
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        map<int, long long>::iterator iter;
        // 遍历当前节点x的所有邻接边
        for (iter = last[x].begin(); iter != last[x].end(); iter++)
        {
            // 如果该边可用且目标节点尚未被访问
            if ((!depth[iter->first]) && (iter->second > 0))
            {
                q.push(iter->first);  // 加入队列
                depth[iter->first] = depth[x] + 1;  // 更新目标节点的层次
                cur[iter->first] = 0;  // 初始化目标节点的指针
                if (iter->first == t)  // 如果找到了汇点t，则返回true
                {
                    return true;
                }
            }
        }
    }
    return false;  
}

// DFS，用于寻找增广路径并进行流量更新
long long dfs(int u, int t, long long limit)
{
    if (u == t)  // 如果到达汇点t，返回流量
    {
        return limit;
    }
    long long mid = limit;  // 保存当前可增广的最大流量
    map<int, long long>::iterator iter;
    // 从当前节点u的指针开始，遍历邻接边
    for (iter = next(last[u].begin(), cur[u]); iter != last[u].end(); iter++)//next:从u的邻接表的cur[u]位置开始遍历(避免dfs重复遍历)
    {
        // 如果该边有剩余容量且目标节点的层次符合要求
        if (iter->second > 0 && depth[iter->first] == depth[u] + 1)
        {
            // 递归调用DFS，找到增广流量
            long long tmp = dfs(iter->first, t, min(mid, iter->second));
            if (tmp <= 0)  // 如果递归返回的流量为 0，说明无法通过这条边增广流量，重置目标节点的层次    
            {
                depth[iter->first] = 0;
            }
            mid -= tmp;  // 更新当前可增广的流量
            iter->second -= tmp;  // 更新当前边的剩余容量
            last[iter->first][u] += tmp;  // 更新反向边的流量
            if (mid <= 0)  // 如果已经没有可增广的流量，退出循环
            {
                break;
            }
        }
        cur[u]++;  // 更新当前节点的指针
    }
    return limit - mid;  // 返回实际增广的流量
}

// Dinic 算法计算最大流
void Dinic(int n, int s, int t)
{
    long long ans = 0;  // 初始化最大流量为0
    // 不断进行BFS和DFS，直到找不到增广路径
    while (bfs(s, t))
    {
        ans += dfs(s, t, MAX);  // 每次找到增广路径，计算流量并累加
    }

    cout << ans << endl;  // 输出最大流
}

int main()
{
    int T;
    cin >> T;  // 输入测试用例的数量
    while (T--)
    {
        int n, m, s, t;
        cin >> n >> m >> s >> t;  // 输入节点数、边数、源点和汇点
        // 初始化图的相关信息
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                last[i][j] = 0;  // 邻接表初始化为0
            }
            re[i] = 0;  // 初始化流量为0
        }
        // 输入边的容量信息
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;  // 输入每条边的起点、终点和容量
            if (u == v)  // 如果是自环，跳过
            {
                continue;
            }
            last[u][v] += w;  // 邻接表更新容量
        }

        Dinic(n, s, t);  // 调用Dinic算法计算最大流
    }
    return 0;
}
