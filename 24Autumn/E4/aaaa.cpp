#include <bits/stdc++.h>
using namespace std;
#define MAX 2147483647
long long graph[210][210];
map<int, map<int, long long>> last;
vector<long long> c(210, MAX);
long long re[210];
int depth[210];
vector<int> path(210, -1);
int cur[210];
bool bfs(int i, int t)
{
    memset(depth, 0, sizeof(depth));
    queue<int> q;
    q.push(i);
    depth[i] = 1;
    cur[i] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        map<int, long long>::iterator iter;
        for (iter = last[x].begin(); iter != last[x].end(); iter++)
        {
            if ((!depth[iter->first]) && (iter->second > 0))
            {
                q.push(iter->first);
                depth[iter->first] = depth[x] + 1;
                cur[iter->first] = 0;
                if (iter->first == t)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
long long dfs(int u, int t, long long limit)
{
    if (u == t)
    {
        return limit;
    }
    long long mid = limit;
    map<int, long long>::iterator iter;
    for (iter = next(last[u].begin(), cur[u]); iter != last[u].end(); iter++)
    {
        if (iter->second > 0 && depth[iter->first] == depth[u] + 1)
        {
            long long tmp = dfs(iter->first, t, min(mid, iter->second));
            if (tmp <= 0)
            {
                depth[iter->first] = 0;
            }
            mid -= tmp;
            iter->second -= tmp;      
            last[iter->first][u] += tmp; 
            if (mid <= 0)
            {
                break;
            }
        }
        cur[u]++; 
    }
    return limit - mid;
}
void Dinic(int n, int s, int t)
{
    long long ans = 0;
    while (bfs(s, t))
    {
        ans += dfs(s, t, MAX);
    }

    cout << ans << endl;
}
int main()
{
        int T;
        cin>>T;
        while(T--)
        {int n, m, s, t;
        cin >> n >> m >> s >> t;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                graph[i][j] = 0;
                last[i][j] = 0;
            }
            re[i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if (u == v)
            {
                continue;
            }
            graph[u][v] += w;
            last[u][v] += w;
        }

        Dinic(n, s, t);}
    return 0;
}