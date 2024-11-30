#include <stdio.h>
#include <string.h>

#define MAXN 1100
typedef struct {
    int x, y;
} pii;

int n;
int g[MAXN][MAXN];
int dis[MAXN][MAXN];
int x, y, xx, yy;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// 定义队列，用于 BFS
pii queue[MAXN * MAXN];
int front, rear;

void enqueue(pii p) {
    queue[rear++] = p;
}

pii dequeue() {
    return queue[front++];
}

int is_empty() {
    return front == rear;
}

int bfs(int x1, int y1) {
    memset(dis, -1, sizeof(dis));
    front = rear = 0; // 初始化队列
    enqueue((pii){x1, y1});
    dis[x1][y1] = 0;

    while (!is_empty()) {
        pii t = dequeue();
        for (int i = 0; i < 4; i++) {
            int a = t.x + dx[i];
            int b = t.y + dy[i];

            if (a < 1 || a > n || b < 1 || b > n) continue;
            if (g[a][b] != 0) continue;
            if (dis[a][b] != -1) continue;

            enqueue((pii){a, b});
            dis[a][b] = dis[t.x][t.y] + 1;

            if (a == xx && b == yy) return dis[xx][yy];
        }
    }
    return dis[xx][yy];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &g[i][j]);
        }
    }
    scanf("%d %d %d %d", &x, &y, &xx, &yy);
    int res = bfs(x, y);
    printf("%d\n", res);
    return 0;
}
