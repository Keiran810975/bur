#include <stdio.h>
#include <stdbool.h>

#define MAXN 100005

int tree[MAXN][MAXN];
int degree[MAXN];
int color[MAXN];
bool visited[MAXN];
int ans = 0;
int n; 

bool dfs(int node) {
    visited[node] = true;
    bool isBlackChild = (color[node] == 1);
    for (int i = 0; i < degree[node]; i++) {
        int child = tree[node][i];
        if (!visited[child]) {
            if (dfs(child)) {
                isBlackChild = true;
            }
        }
    }
    
    if (color[node] == 0 && isBlackChild) {
        ans++;
        isBlackChild = true; 
    }
    
    return isBlackChild;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        tree[x][degree[x]++] = y;
        tree[y][degree[y]++] = x;
    }
    dfs(1);
    printf("%d\n", ans);
    
    return 0;
}
