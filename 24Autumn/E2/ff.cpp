#include<iostream>
#include<cstring>
using namespace std;

int t;

int x, y, xx, yy;
int qx[100005], qy[100005]; 
int front, back; 
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        char g[n][m];
        int dis[n][m];
        scanf("%d%d%d%d", &x, &y, &xx, &yy);
        x--; y--; xx--; yy--;
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }
        int sig=0;
        int res;
        front = back = 0; 
        memset(dis, -1, sizeof(dis));
        
        qx[back] = x; 
        qy[back++] = y;
        dis[x][y] = 0;
        
        while (front < back) {
            if(sig==1)break;
            int tx = qx[front];
            int ty = qy[front++];
            for (int i = 0; i < 4; i++) {
                int a = tx, b = ty;
                int aa = tx, bb = ty;
                while (!(a + dx[i] < 0 || b + dy[i] < 0 || a + dx[i] >= n || b + dy[i] >= m) && g[a + dx[i]][b + dy[i]] == '.') {
                    a += dx[i];
                    b += dy[i];
                    if (a == xx && b == yy) { 
                        res= dis[tx][ty] + 1;
                        sig=1;
                        break;
                    }
                }
                if(sig==1) break;
                if (a == aa && b == bb) continue; 
                if (dis[a][b] != -1) continue; 
                
                dis[a][b] = dis[tx][ty] + 1;
                qx[back] = a; 
                qy[back++] = b;
                
                if (a == xx && b == yy){
                    res= dis[xx][yy];
                    sig=1;
                    break;
                }
            }
            if(sig==1) break;
        }
        
        if(!sig)res= dis[xx][yy];
        printf("%d\n", res);
    }
    return 0;
}
