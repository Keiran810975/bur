#include <stdio.h>
#include <string.h>
int n, m;
int g[1100][1100];
int dis[1100][1100];
int queue[1100*1100][2];
int front, rear;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int bfs(int start_x, int start_y) {
    memset(dis, -1, sizeof dis);
    front = rear = 0;
    queue[rear][0] = start_x;
    queue[rear][1] = start_y;
    rear++;
    dis[start_x][start_y] = 0;
    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;
        for (int i = 0; i < 4; i++) {
            int a = x, b = y;
            while (1) {
                a += dx[i];
                b += dy[i];
                if (a < 1 || a > n || b < 1 || b > m) break;
                if (dis[a][b] != -1) continue;
                if ((i == 0 || i == 2) && g[a][b] != g[x][y]) { // 同一列、不同色
                    break;
                } 
                else if ((i == 1 || i == 3) && g[a][b] == g[x][y]) { // 同一行、同色
                    break;
                }
                dis[a][b] = dis[x][y] + 1;
                queue[rear][0] = a;
                queue[rear][1] = b;
                rear++;
                if (a == n && b == m) return dis[n][m];
            }
        }
    }

    return dis[n][m];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &g[i][j]);
        int res = bfs(1, 1);
        printf("%d\n", res);
    }

    return 0;
}
