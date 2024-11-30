//二分图匹配问题
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a,p,b,q;
vector<vector<int>> g;

vector<int> match;
bool dfs(int i, vector<bool>& visited) {
    for (int j : g[i]) {
        if (!visited[j]) {
            visited[j] = true;
            // 如果女生 j 未匹配，或可以找到新的增广路径
            if (match[j] == -1 || dfs(match[j], visited)) {
                match[j] = i;
                return true;
            }
        }
    }
    return false;
}

int maxCouples() {
    match.assign(n, -1); // 初始化女生的匹配状态为 -1
    int result = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false); // 记录当前女生是否被访问
        if (dfs(i, visited)) {
            result++;
        }
    }
    return result;
}
int main(){
    scanf("%d",&n);
    a.resize(n+1);
    p.resize(n+1);
    b.resize(n+1);
    q.resize(n+1);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)scanf("%d",&p[i]);
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    for(int i=0;i<n;i++)scanf("%d",&q[i]);
    g.assign(n, vector<int>());//初始化元素为空
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]>=q[j]&&b[j]>=p[i]){
                g[i].push_back(j);
            }
        }
    }

    printf("%d\n",maxCouples());
    return 0;
}