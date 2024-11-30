#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 10005
#define M 10005

typedef struct {
    int to, next;
} Edge;

Edge edges[M];
int head[N], indegree[N], edgeCount;
int topoOrder[N];
int queue[N];

void init(int n) {
    edgeCount = 0;
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
        indegree[i] = 0;
    }
}

void addEdge(int u, int v) {
    edges[edgeCount].to = v;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount++;
    indegree[v]++;
}

bool topologicalSort(int n) {
    int front = 0, rear = 0, idx = 0;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) queue[rear++] = i;
    }

    while (front < rear) {
        int u = queue[front++];
        topoOrder[idx++] = u;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            if (--indegree[v] == 0) queue[rear++] = v;
        }
    }
    return idx == n; 
}

bool isSemiConnected(int n) {
    for (int i = 0; i < n - 1; i++) {
        int u = topoOrder[i];
        int v = topoOrder[i + 1];
        
        bool canReach = false;
        for (int j = head[u]; j != -1; j = edges[j].next) {
            if (edges[j].to == v) {
                canReach = true;
                break;
            }
        }
        
        if (!canReach) return false; 
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);

        init(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            addEdge(u, v);
        }
        if (!topologicalSort(n)) {
            printf("NO\n");
            continue;
        }
        if (isSemiConnected(n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
